#include "Arduino.h"
#include "TimerManager.h"
#include "Timer.h"
//The setup function is called once at startup of the sketch

#define NUM_OF_SAMPLES		20
#define LOWER_CURRENT_BOUND  3

int sensorValue;
float voltage;
TimerManager timerManager;
Timer *tmrBlink;
Timer *tmrStart;
Timer *tmrStop;
int ledStatus = LOW;
unsigned long now;
int readCount;
int readVal;
int slvStatus = LOW;
bool requestToStart;
bool requestToStop;

void setup()
{
	Serial.begin(9600);

	tmrBlink = timerManager.getNewTimer("blink");
	tmrStart = timerManager.getNewTimer("start");
	tmrStop = timerManager.getNewTimer("stop");
	tmrBlink->setDuration(2000);
	tmrBlink->start(millis());
	tmrStop->setDuration(2000);
	tmrStart->setDuration(4000);
	readCount = 0;
}

// The loop function is called in an endless loop
void loop()
{
	now = millis();
	timerManager.update(now);

	requestToStart = requestToStop = false;

	if (tmrBlink->getIsExpired())
	{
		ledStatus = HIGH;
		tmrBlink->restart(now);
		Serial.print("Status ");
		Serial.print(slvStatus);
		Serial.print(" - sensor value ");
		Serial.println(analogRead(A0));
	}
	else
	{
		ledStatus = LOW;
	}

	sensorValue += ((readVal = analogRead(A0) - 512) < 0 ? readVal * -1 : readVal);
	if (++readCount > NUM_OF_SAMPLES)
	{
		if (Serial.read())
		sensorValue /= NUM_OF_SAMPLES;
		if (sensorValue > LOWER_CURRENT_BOUND)
		{
			requestToStart = true;
		}
		else
		{
			requestToStop = true;
		}

		if (slvStatus == HIGH)
		{
			if (requestToStop)
			{
				if (!tmrStop->getIsRunning())
				{
					tmrStart->reset();
					tmrStop->start(now);
					Serial.print("Master inactive: ");
					Serial.println(sensorValue);
				}
				else
				{
					if (tmrStop->getIsExpired())
					{
						slvStatus = LOW;
					}
				}
			}
			else
			{
				tmrStop->reset();
			}
		}
		else
		{
			if (requestToStart)
			{
				if (!tmrStart->getIsRunning())
				{
					tmrStop->reset();
					tmrStart->start(now);
					Serial.print("Master active: ");
					Serial.println(sensorValue);
				}
				else
				{
					if (tmrStart->getIsExpired())
					{
						slvStatus = HIGH;
					}
				}
			}
			else
			{
				tmrStart->reset();
			}
		}
	}

	analogWrite(10, slvStatus*255);
	digitalWrite(LED_BUILTIN, ((ledStatus == HIGH) || (slvStatus == HIGH) ? HIGH : LOW));
}
