#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <SD.h>	 //INCLUSÃO DE BIBLIOTECA

const int chipSelect = 10; //PINO DIGITAL UTILIZADO PELO TERMINAL CS DO MÓDULO
const char *fileName = "LOG.TXT";
const char formatDate[] = "DD/MM/YYYY hh:mm:ss";

class FileLogger
{
private:
	Display *display;

	File openFile()
	{
		File logFile = SD.open(fileName, FILE_WRITE);
		return logFile;
	}

public:
	FileLogger(Display *display)
	{
		if (!SD.begin(chipSelect))
		{
			display->Error("Cartao de memoria falhou ou nao esta presente!"); //SE O CARTÃO DE MEMÓRIA NÃO ESTIVER PRESENTE OU FALHAR, FAZ
			return;															  //NÃO FAZ MAIS NADA
		}

		File file = openFile();
		if (file)
		{
			file.close();
		}
		else
		{
			display->Error("Falha ao abrir o arquivo!");
		}

		display->Info("Cartao SD OK!");
	}
	~FileLogger()
	{
	}

	void IrrigateOn(DateTime date, float temperature)
	{

		File file = this->openFile();
		file.println("[Irrigate] ON " + date.timestamp(DateTime::TIMESTAMP_FULL));
		file.close();
	}

	void IrrigateOff(DateTime date, float temperature)
	{
		File file = this->openFile();
		file.println("[Irrigate] OFF " + date.timestamp(DateTime::TIMESTAMP_FULL));
		file.close();

		File myFile = SD.open(fileName);
		if (myFile)
		{
			Serial.println("test.txt:");

			// read from the file until there's nothing else in it:
			while (myFile.available())
			{
				Serial.write(myFile.read());
			}
			// close the file:
			myFile.close();
		}
	}
};
