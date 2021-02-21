#include <Arduino.h>
#include <Wire.h>
#include "RTClib.h"

#include "Display.h"
#include "DateTimeProvider.h"
#include "Solenoide.h"
#include "FileLogger.h"
#include "Service.h"

#include "MoistureGrove.h"

Display *display;
Solenoide *solenoide;
DateTimeProvider *dateTime;
FileLogger *fileLogger;
MoistureGrove *moistureGrove;
Service *service;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  display = new Display();
  solenoide = new Solenoide();
  fileLogger = new FileLogger(display);
  dateTime = new DateTimeProvider(display);
  service = new Service(display, fileLogger, dateTime, solenoide);

  moistureGrove = new MoistureGrove(service);
}

void loop()
{
  display->setDateTime(dateTime->Now());
  display->setTemperature(dateTime->Temperature());
  display->Loop();
  moistureGrove->Loop();
  // put your main code here, to run repeatedly:
  delay(1000);
}