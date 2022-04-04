#include "sender.h"
#include <iostream>
using namespace std;

void Sender::generateData(Temperature &temperature,SOC &soc,Sender &sender,void (*funp_generateData)(Temperature,SOC,Sender))
{
  float manualtemperature_data[sender.number_of_values] = {21,31,41,51,61};
  float manualsoc_data[sender.number_of_values] = {21,25,30,35,39};
  for(int i=0;i<sender.number_of_values;i++)
  {
    temperature.data[i] = manualtemperature_data[i];
    soc.data[i] = manualsoc_data[i];
  }
  for(int i=0;i<sender.number_of_values;i++)
  {
    cout<<temperature.data[i]<<endl;
    cout<<soc.data[i]<<endl;
  }
}
