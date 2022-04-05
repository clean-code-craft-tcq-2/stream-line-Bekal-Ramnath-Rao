#ifndef SENDER_H__
#define SENDER_H__

#include <string>

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
    void generateandFormatData(Temperature& ,SOC& ,Sender& ,float (*)(float,float),
                               void(*)(Temperature&,SOC&,Sender&),void(*)(Sender&));
    string formatted_output[50];
};

float generateRandomData(float,float);

void formatData(Temperature&,SOC&,Sender&);

void printonConsole(Sender&);

#endif
