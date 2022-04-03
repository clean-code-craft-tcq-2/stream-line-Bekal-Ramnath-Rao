#include "sender.h"

void Sender::generateData(Temperature temperature,SOC soc,Sender sender,void (funp_generateData*)(Temperature temperature,SOC soc,Sender sender))
{
    funp_generateData(Temperature temperature,SOC soc,Sender sender);
}
