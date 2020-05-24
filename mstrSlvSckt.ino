#include "Arduino.h"
#include "TimerManager.h"
#include "Timer.h"
//The setup function is called once at startup of the sketch

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
	if (++readCount > 50)
	{
		sensorValue /= 50;
		if (!(tmrStart->getIsRunning() || tmrStart->getIsExpired()) &&
			(sensorValue > 3) &&
			(slvStatus == LOW))
		{
			tmrStop->reset();
			tmrStart->start(now);
			if (tmrStart->getIsFront())
			{
				Serial.print("Master active: ");
				Serial.println(sensorValue);
			}
		}

		if (!(tmrStop->getIsRunning() || tmrStop->getIsExpired()) &&
			(sensorValue <= 3) &&
			(slvStatus == HIGH))
		{
			tmrStart->reset();
			tmrStop->start(now);
			if (tmrStop->getIsFront())
			{
				Serial.print("Master inactive: ");
				Serial.println(sensorValue);
			}
		}
		sensorValue = 0;
		readCount = 0;
	}

	//voltage = sensorValue * (5.0 / 1023.0);

	if (tmrStart->getIsExpired() && tmrStart->getIsFront())
	{
		slvStatus = HIGH;
		Serial.println("enable socket");
	}

	if (tmrStop->getIsExpired() && tmrStop->getIsFront())
	{
		slvStatus = LOW;
		Serial.println("disable socket");
	}

	analogWrite(10, slvStatus*255);
	digitalWrite(LED_BUILTIN, ledStatus | slvStatus);
}
