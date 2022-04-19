using SensorReceiver.Models;
using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;

namespace SensorReceiver
{
    public class Receiver
    {
        [ExcludeFromCodeCoverage]
        static void Main(string[] args)
        {
            List<SensorReading> sensorReadings = new List<SensorReading>();

            string reading;
            while ((reading = Console.ReadLine()) != null)
            {
                var newReading = ParseStringReadingToSensorReading(reading);

                sensorReadings.Add(newReading);

                PrintReading(newReading);
                PrintStatistics(sensorReadings);

            }

        }

        public static SensorReading ParseStringReadingToSensorReading(string reading)
        {
            float temperature = float.Parse(reading.Split(',').First());

            float stateOfCharge = float.Parse(reading.Split(',').Last());

            SensorReading sensorReading = new SensorReading { stateOfCharge = stateOfCharge, temperature = temperature };

            return sensorReading;

        }

        public static float FetchMaximumValue(List<float> readings)
        {
            float maximumValue = readings.OrderByDescending(x => x).FirstOrDefault();

            return maximumValue;
        }

        public static float FetchMinimumValue(List<float> readings)
        {
            float minimumValue = readings.OrderBy(x => x).FirstOrDefault();

            return minimumValue;
        }

        public static float FetchSimpleMovingAverage(List<float> readings)
        {
            var sumOfReadings = readings.Sum(x => x);

            var numberOfReadings = readings.Count();

            return sumOfReadings / numberOfReadings;

        }

        public static string PrintReading(SensorReading sensorReading)
        {
            string lineToBePrinted = "\n\n------------------------- New Reading ---------------------\n+ New reading --> Temperature : " + sensorReading.temperature + " , StateOfCharge: " + sensorReading.stateOfCharge;

            Console.WriteLine(lineToBePrinted);

            return lineToBePrinted;

        }

        public static string PrintStatistics(List<SensorReading> sensorReadings)
        {
            var temperatureValues = sensorReadings.Select(x => x.temperature).ToList();
            var stateOfChargeValues = sensorReadings.Select(x => x.stateOfCharge).ToList();

            string header = "------------------------- Statistics ----------------------\n";

            string temperatureStatistics = "Temperature -> Max: " + FetchMaximumValue(temperatureValues) + " Min: " + FetchMinimumValue(temperatureValues) + " SMA: " + FetchSimpleMovingAverage(temperatureValues.Skip(Math.Max(0, temperatureValues.Count() - 5)).ToList()) + "\n";

            string stateOfChargeStatistics = "State of Charge -> Max: " + FetchMaximumValue(stateOfChargeValues) + " Min: " + FetchMinimumValue(stateOfChargeValues) + " SMA: " + FetchSimpleMovingAverage(stateOfChargeValues.Skip(Math.Max(0, temperatureValues.Count() - 5)).ToList()) + "\n";

            string endOfBlock = "-----------------------------------------------------------";

            string lineToBePrinted = header + temperatureStatistics + stateOfChargeStatistics + endOfBlock;

            Console.WriteLine(lineToBePrinted);

            return lineToBePrinted;

        }

    }
}
