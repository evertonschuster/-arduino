
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
