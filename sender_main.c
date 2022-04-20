#include "sender.h"
#include "sender.c"

int main(){

    Temperature temperature;
    SOC soc;
    Sender sender;
    temperature.maximum= 80;
    temperature.minimum= 20;
    soc.maximum = 40;
    soc.minimum = 20;
    sender.number_of_values = 50;
    float (*funp_generateData)(float,float) = generateRandomData;
    void (*funp_formatData)(Temperature&,SOC&,Sender&) = formatData;
    void (*funp_printonConsole)(Sender&) = printonConsole;
    sender.generateandFormatData(temperature,soc,sender,funp_generateData,funp_formatData,funp_printonConsole);

}