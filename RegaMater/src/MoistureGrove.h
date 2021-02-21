const static int sensorPin = A0;

class MoistureGrove
{
private:
	Service *service;

public:
	MoistureGrove(Service *service)
	{
		this->service = service;
	}

	~MoistureGrove() {}

	void Loop()
	{
		int sensorValue = analogRead(sensorPin);
		service->SetMoisture(sensorValue);
	}
};
