
class Service
{
private:
	Display *display;
	FileLogger *fileLogger;
	DateTimeProvider *dateTime;
	Solenoide *solenoide;

	void Irrigate()
	{
		DateTime dateOn = this->dateTime->Now();
		float temperatureOn = this->dateTime->Temperature();

		this->display->setIrrigating(true);
		this->fileLogger->IrrigateOn(dateOn, temperatureOn);
		this->solenoide->MakeOn();

		delay(120000);

		DateTime dateOff = this->dateTime->Now();
		float temperatureOff = this->dateTime->Temperature();

		this->solenoide->MakeOff();
		this->fileLogger->IrrigateOff(dateOff, temperatureOff);
		this->display->setIrrigating(false);
	}

public:
	Service(Display *display, FileLogger *fileLogger, DateTimeProvider *dateTime, Solenoide *solenoide)
	{
		this->display = display;
		this->fileLogger = fileLogger;
		this->dateTime = dateTime;
		this->solenoide = solenoide;
	}
	~Service()
	{
	}

	void SetMoisture(int moisture)
	{
		this->display->SetMoisture(moisture);

		//maior que 20 paa não ligar  fora da terra
		if (moisture > 20 && moisture < 100)
		{
			this->Irrigate();
			DateTime date = this->dateTime->Now();
			if (date.hour() > 16 && date.hour() < 8)
			{
			}
		}
	}
};
