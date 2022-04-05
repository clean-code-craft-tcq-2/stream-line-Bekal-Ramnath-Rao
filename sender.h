#ifndef SENDER_H__
#define SENDER_H__

class Temperature
{
  public:
    float maximum;
    float minimum;
    float data[50];
};

class SOC
{
  public:
    float maximum;
    float minimum;
    float data[50];
};

class Sender
{
  public:
    int number_of_values;
    void generateData(Temperature& ,SOC& ,Sender& ,void (*)(float,float));
};

#endif
