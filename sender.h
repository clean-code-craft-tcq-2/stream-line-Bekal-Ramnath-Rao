#ifndef SENDER_H__
#define SENDER_H__

class Temperature
{
float maximum_temperature;
float minimum_temperature;
};

class SOC
{
float maximum_soc;
float minimum_soc;
};

class Sender
{
int number_of_values;
generateData(Temperature temperature,SOC soc,Sender sender,void (*)(Temperature temperature,SOC soc,Sender sender));
};
