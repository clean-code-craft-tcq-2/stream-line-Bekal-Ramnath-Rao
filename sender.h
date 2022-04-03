#ifndef SENDER_H__
#define SENDER_H__

class Sender
{
  public:
    int number_of_values;
    void generateData(Temperature temperature,SOC soc,Sender sender,void (*)(Temperature temperature,SOC soc,Sender sender));
};

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

#endif
