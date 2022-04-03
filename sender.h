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
    Sender sender;
    float maximum_temperature;
    float minimum_temperature;
    float data[sender.number_of_values];
};

class SOC
{
  public:
    Sender sender;
    float maximum_soc;
    float minimum_soc;
    float data[sender.number_of_values];
};

#endif
