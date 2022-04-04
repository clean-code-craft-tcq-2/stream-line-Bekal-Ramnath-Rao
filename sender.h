#ifndef SENDER_H__
#define SENDER_H__

class Temperature
{
  public:
    float maximum_temperature;
    float minimum_temperature;
    float data[50];
};

class SOC
{
  public:
    float maximum_soc;
    float minimum_soc;
    float data[50];
};

class Sender
{
  public:
    int number_of_values;
    void generateData(Temperature *,SOC *,Sender *,void (*)(Temperature temperature,SOC soc,Sender sender));
};

#endif
