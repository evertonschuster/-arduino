#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const unsigned int scrollDelay = 800;

class Display
{
private:
	int loopCount = 0;
	int moisture = 0;
	DateTime dateTime;
	float temperature;

	void ShowMessage(const String &title, const String &text)
	{
		Serial.println("[" + title + "]" + ": " + text);

		int textLen = text.length();
		lcd.clear();

		lcd.setCursor(4, 0);
		lcd.print(title);

		lcd.setCursor(0, 1);
		lcd.print(text);

		for (int index = 0; index < (textLen - 16) + 1; index++)
		{
			lcd.setCursor(0, 1);
			String scroll = text.substring(index, index + 16);
			lcd.print(scroll);
			delay(scrollDelay);
		}
	}

public:
	Display()
	{
		// //Inicializa o display no endereco 0x27
		lcd.init();
		lcd.setBacklight(HIGH);

		lcd.clear();
		lcd.setCursor(3, 0);
		lcd.print("Iniciando");
		lcd.setCursor(3, 1);
		lcd.print("Aplicacao");
	}
	~Display()
	{
	}

	void Alert(const String &text)
	{
		this->ShowMessage("Alerta", text);
	}

	void Info(const String &text)
	{
		ShowMessage("Info", text);
	}

	void Error(const String &text)
	{
		ShowMessage("Erro", text);
	}

	void SetMoisture(const int moisture)
	{
		this->moisture = moisture;
	}

	void setDateTime(DateTime dateTime)
	{
		this->dateTime = dateTime;
	}

	void setTemperature(float temperature)
	{
		this->temperature = temperature;
	}

	void setIrrigating(bool isIrrigating)
	{
		if (isIrrigating)
		{
			this->Info("Irrigando!!");
		}
		else
		{
			this->Info("Desligando irrigacao");
		}
	}
	void Loop()
	{
		//Data Hora
		if (loopCount >= 0 && loopCount < 10)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Data " + this->dateTime.timestamp(DateTime::TIMESTAMP_DATE));
			lcd.setCursor(0, 1);
			lcd.print("Hora " + this->dateTime.timestamp(DateTime::TIMESTAMP_TIME));
		}

		//Humidade
		//Temperatura
		if (loopCount >= 10 && loopCount < 20)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Temp " + String(this->temperature));
			lcd.setCursor(0, 1);
			lcd.print("Humi " + String(this->moisture));
		}

		if (loopCount >= 20)
		{
			loopCount = 0;
			return;
		}

		loopCount++;
	}
};
