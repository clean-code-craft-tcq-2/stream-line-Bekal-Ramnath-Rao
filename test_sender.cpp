#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

using namespace std;

void generateManualData(Temperature &temperature,SOC &soc,Sender &sender)
{
  float manualtemperature_data[sender.number_of_values] = {21,31,41,51,61};
  float manualsoc_data[sender.number_of_values] = {21,25,30,35,39};
  for(int i=0;i<sender.number_of_values;i++)
  {
    temperature.data[i] = manualtemperature_data[i];
    soc.data[i] = manualsoc_data[i];
  }

}

TEST_CASE("Prepare Data") {
  Temperature temperature;
  SOC soc;
  Sender sender;
  temperature.maximum= 80;
  temperature.minimum= 20;
  soc.maximum = 40;
  soc.minimum = 20;
  sender.number_of_values = 5;
  float Expectedtemperature_data[sender.number_of_values] = {21,31,41,51,61};//assuming these are generated values
  float Expectedsoc_data[sender.number_of_values] = {21,25,30,35,39};
  void (*funp_generateData)(Temperature&,SOC&,Sender&) = generateManualData;
  void (*funp_formatData)(Temperature&,SOC&,Sender&) = formatData;
  void (*funp_printonConsole)(Sender&) = printonConsole;
  sender.generateData(temperature,soc,sender,funp_generateData,funp_formatData,funp_printonConsole);
  for(int i=0; i<sender.number_of_values; i++)
  {
    REQUIRE( temperature.data[i] == Expectedtemperature_data[i]);
    REQUIRE( soc.data[i] == Expectedsoc_data[i]);
  }
}
