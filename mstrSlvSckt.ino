#include "Arduino.h"
#include "TimerManager.h"
#include "Timer.h"
//The setup function is called once at startup of the sketch

#define NUM_OF_SAMPLES				40
#define NUM_OF_RUNS_TO_POSITIVE		 6
#define LOWER_CURRENT_BOUND 		 1
#define	START						 1
#define	STOP						 0

int sensorValue;
float voltage;
TimerManager timerManager;
Timer *tmrBlink;
Timer *tmrStart;
Timer *tmrStop;
Timer *tmrDebug;
int ledStatus = LOW;
unsigned long now;
int readCount;
int readVal;
int slvStatus = LOW;
bool requestToStart;
bool requestToStop;
int	numOfRuns[2];

void setup()
{
	Serial.begin(9600);

	tmrBlink = timerManager.getNewTimer("blink");
	tmrStart = timerManager.getNewTimer("start");
	tmrStop = timerManager.getNewTimer("stop");
	tmrDebug= timerManager.getNewTimer("debug");
	tmrBlink->setDuration(2000);
	tmrBlink->start(millis());
	tmrStop->setDuration(2000);
	tmrStart->setDuration(4000);
	tmrDebug->setDuration(3000);
	tmrDebug->start(millis());
	sensorValue = readCount = 0;
	numOfRuns[STOP] = numOfRuns[START] = NUM_OF_RUNS_TO_POSITIVE;
	requestToStart = requestToStop = false;
}

// The loop function is called in an endless loop
void loop()
{
	now = millis();
	timerManager.update(now);

	if (tmrBlink->getIsExpired())
	{
		ledStatus = HIGH;
		tmrBlink->restart(now);
	}
	else
	{
		ledStatus = LOW;
	}
	readVal = analogRead(A0) - 511;
	sensorValue += (readVal < 0 ? -readVal : readVal);
	if (++readCount > NUM_OF_SAMPLES)
	{
		sensorValue /= NUM_OF_SAMPLES;
		if (tmrDebug->getIsExpired())
		{
//			Serial.print("Status ");
//			Serial.print(slvStatus);
//			Serial.print(" - Sensor value ");
//			Serial.println(sensorValue);
			tmrDebug->restart(millis());
		}

		if (sensorValue > LOWER_CURRENT_BOUND)
		{
			numOfRuns[STOP] = NUM_OF_RUNS_TO_POSITIVE;
			numOfRuns[START] = numOfRuns[START] - 1;
			if (numOfRuns[START] <= 0)
			{
				numOfRuns[START] = 0;
				requestToStop = false;
				requestToStart = true;
//				Serial.println("Request to start is active");
			}
		}
		else
		{
			numOfRuns[START] = NUM_OF_RUNS_TO_POSITIVE;
			numOfRuns[STOP] = numOfRuns[STOP] - 1;
			if (numOfRuns[STOP] <= 0)
			{
				numOfRuns[STOP] = 0;
				requestToStop = true;
				requestToStart = false;
//				Serial.println("Request to stop is active");
			}
		}

		if (slvStatus == HIGH)
		{
			if (requestToStop)
			{
				if (!tmrStop->getIsRunning() && !tmrStop->getIsExpired())
				{
					tmrStart->reset();
					tmrStop->start(now);
					Serial.print("Status ");
					Serial.print(slvStatus);
					Serial.print(" - Master inactive: ");
					Serial.println(sensorValue);
				}
				else
				{
					if (tmrStop->getIsExpired())
					{
						Serial.println("** DISABLE SOCKET **");
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
				if (!tmrStart->getIsRunning() && !tmrStart->getIsExpired())
				{
					tmrStop->reset();
					tmrStart->start(now);
					Serial.print("Status ");
					Serial.print(slvStatus);
					Serial.print(" - Master active: ");
					Serial.println(sensorValue);
				}
				else
				{
					if (tmrStart->getIsExpired())
					{
						Serial.println("** ENABLE SOCKET **");
						slvStatus = HIGH;
					}
				}
			}
			else
			{
				tmrStart->reset();
			}
		}
		sensorValue = 0;
		readCount = 0;
	}

	analogWrite(10, slvStatus*255);
	digitalWrite(LED_BUILTIN, ((ledStatus == HIGH) || (slvStatus == HIGH) ? HIGH : LOW));
}
