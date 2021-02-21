
static int pino_rele1 = 2;
class Solenoide
{
private:
public:
    Solenoide()
    {
        pinMode(pino_rele1, OUTPUT);
        digitalWrite(pino_rele1, HIGH);
    }
    ~Solenoide()
    {
    }

    void MakeOn(){
        digitalWrite(pino_rele1, LOW);
    }

    void MakeOff(){
        digitalWrite(pino_rele1, HIGH);
    }
};
