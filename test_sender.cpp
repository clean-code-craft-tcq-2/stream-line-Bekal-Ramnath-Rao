#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"



TEST_CASE("Prepare Data") {
  Temperature temperature;
  SOC soc;
  Sender sender;
  temperature.maximum_temperature = 80;
  temperature.minimum_temperature = 20;
  soc.SOC_maximum = 40;
  soc.SOC_minimum = 20;
  sender.number_of_values = 5;
  int temperature_data[sender.number_of_values] = {21,31,41,51,61};
  int soc_data[sender.number_of_values] = {21,25,30,35,39};
  void funp_generateData()
  sender.generateData(temperature,soc,sender,funp_generateData);
  for(inr i=0; i<sender.number_of_values; i++)
  {
    REQUIRE( temperature.data[i] == temperature_data[i]);
    REQUIRE( soc.data[i] == soc_data[i]);
  }
}
