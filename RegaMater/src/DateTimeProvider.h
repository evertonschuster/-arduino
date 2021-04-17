
RTC_DS3231 rtc;

class DateTimeProvider
{
private:
public:
	DateTimeProvider(Display *display)
	{
		if (rtc.begin())
		{
		}
		//rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //CAPTURA A DATA E HORA EM QUE O SKETCH É COMPILADO

		// Comment out below lines once you set the date & time.
		// Following line sets the RTC to the date & time this sketch was compiled

		DateTime now = rtc.now();
		Serial.println(now.year());
		Serial.println(now.month());
		Serial.println(now.hour());
		Serial.println(now.minute());
		Serial.println(rtc.getTemperature());
	}
	~DateTimeProvider()
	{
	}

	DateTime Now()
	{
		return rtc.now();
	}

	float Temperature()
	{
		return rtc.getTemperature();
	}
};
