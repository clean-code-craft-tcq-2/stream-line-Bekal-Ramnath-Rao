#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

using namespace std;

void generateManualData(Temperature temperature,SOC soc,Sender sender)
{
  int manualtemperature_data[sender.number_of_values] = {21,31,41,51,61};
  int manualsoc_data[sender.number_of_values] = {21,25,30,35,39};
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
  temperature.maximum_temperature = 80;
  temperature.minimum_temperature = 20;
  soc.maximum_soc = 40;
  soc.minimum_soc = 20;
  sender.number_of_values = 5;
  float Expectedtemperature_data[sender.number_of_values] = {21,31,41,51,61};//assuming these are generated values
  float Expectedsoc_data[sender.number_of_values] = {21,25,30,35,39};
  void (*funp_generateData)(Temperature,SOC,Sender) = generateManualData;
  sender.generateData(temperature,soc,sender,funp_generateData);
  for(int i=0; i<sender.number_of_values; i++)
  {
    REQUIRE( temperature.data[i] == Expectedtemperature_data[i]);
    REQUIRE( soc.data[i] == Expectedsoc_data[i]);
  }
}
