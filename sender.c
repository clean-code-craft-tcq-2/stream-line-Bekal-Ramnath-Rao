#include "sender.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

float generateRandomData(float parameter_Maximum, float parameter_Minimum,int time_parameter)
{
  srand(time((time_t)time_parameter));
  float data = (rand() % (int)(parameter_Maximum+1)) ;
  if(data < parameter_Minimum)
  {
    data = data + parameter_Minimum;
  }
  return data;
}

void Sender::generateandFormatData(Temperature &temperature,SOC &soc,Sender &sender,float (*funp_generateData)(float,float,int),
                                   void (*funp_formatData)(Temperature&,SOC&,Sender&),void (*funp_printonConsole)(Sender&))
{
  for(int i=0;i<sender.number_of_values;i++)
  {
    temperature.data[i] = funp_generateData(temperature.maximum, temperature.minimum,i);
    soc.data[i] = funp_generateData(soc.maximum,soc.minimum,i);
  }
  funp_formatData(temperature,soc,sender);
  funp_printonConsole(sender);
}

void formatData(Temperature &temperature,SOC &soc,Sender &sender)
{
  for(int i=0;i<sender.number_of_values;i++)
  {
    sender.formatted_output[i] = to_string(temperature.data[i]) + "," + to_string(soc.data[i]);
  }
}

void printonConsole(Sender &sender)
{
  for(int i=0;i<sender.number_of_values;i++)
  {
    cout<<sender.formatted_output[i]<<endl;
  }
}
