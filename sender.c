#include "sender.h"
#include <iostream>
using namespace std;

void Sender::generateData(Temperature &temperature,SOC &soc,Sender &sender,void (*funp_generateData)(Temperature&,SOC&,Sender&))
{
  funp_generateData(temperature,soc,sender);
}
