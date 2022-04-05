#include "sender.h"
#include <iostream>
#include <stdlib.h>
#include "string.h"

using namespace std;

static float generateRandomData(float parameter_Maximum, float parameter_Minimum)
{
  srand(time(0));
  float data = (rand() % (parameter_Maximum+1)) ;
  if(data < parameter_Minimum)
  {
    data = data + parameter_Minimum;
  }
  return data;
}

void Sender::generateandFormatData(Temperature &temperature,SOC &soc,Sender &sender,void (*funp_generateData)(float,float),
                                   void (*funp_formatData)(Temperature,SOC,Sender),void (*funp_printonConsole)(Sender))
{
  for(int i=0;i<sender.number_of_values;i++)
  {
    temperature.data[i] = funp_generateData(temperature.maximum, temperature.minimum);
    soc.data[i] = funp_generateData(soc.maximum,soc.minimum);
  }
  funp_formatData(temperature,soc,sender);
  funp_printonConsole(sender);
}

static void formatData(Temperature &temperature,SOC &soc,Sender &sender)
{
  for(int i=0;i<sender.number_of_values;i++)
  {
    sender.formatted_output[i] = to_string(temperature.data[i]) + "," + to_string(soc.data[i]);
  }
}

static void printonConsole(Sender &sender)
{
  for(int i=0;i<sender.number_of_values;i++)
  {
    cout<<sender.formatted_output[i]<<endl;
  }
}
