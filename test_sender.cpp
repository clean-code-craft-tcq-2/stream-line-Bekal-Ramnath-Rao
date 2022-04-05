#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

using namespace std;

int generateData_Called;
void generateManualData(float parameter_Maximum,float parameter_Minimum)
{
  generateData_Called = 1;
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
  void (*funp_generateData)(float,float) = generateManualData;
  void (*funp_formatData)(Temperature&,SOC&,Sender&) = formatData;
  void (*funp_printonConsole)(Sender&) = printonConsole;
  sender.generateandFormatData(temperature,soc,sender,funp_generateData,funp_formatData,funp_printonConsole);
  REQUIRE( generateData_Called == 1);
}
