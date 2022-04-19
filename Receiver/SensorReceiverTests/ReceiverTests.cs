using Microsoft.VisualStudio.TestTools.UnitTesting;
using SensorReceiver;
using SensorReceiver.Models;
using System;
using System.Collections.Generic;
using System.Text;

namespace SensorReceiver.Tests
{
    [TestClass()]
    public class ReceiverTests
    {
        List<float> readingsForTest = new List<float> { 1f, 2f, 3f, 4f, 5f, 6f };

        SensorReading sensorReading = new SensorReading { temperature = 60, stateOfCharge = 30 };

        List<SensorReading> sensorReadings = new List<SensorReading> { new SensorReading { temperature = 60, stateOfCharge = 30 }, new SensorReading { temperature = 20, stateOfCharge = 40 } };

        [TestMethod()]
        public void ParseStringReadingToSensorReadingTest()
        {
            var sensorReading = Receiver.ParseStringReadingToSensorReading("60,30");

            Assert.AreEqual(sensorReading.temperature,60f);
        }

        [TestMethod()]
        public void FetchMaximumValueTest()
        {

            var maximumValue = Receiver.FetchMaximumValue(readingsForTest);

            Assert.AreEqual(maximumValue, 6f);
        }

        [TestMethod()]
        public void FetchMinimumValueTest()
        {
            var minimumValue = Receiver.FetchMinimumValue(readingsForTest);

            Assert.AreEqual(minimumValue, 1f);
        }

        [TestMethod()]
        public void FetchSimpleMovingAverageTest()
        {
            var simpleMovingAverage = Receiver.FetchSimpleMovingAverage(readingsForTest);

            Assert.AreEqual(simpleMovingAverage, 3.5f);
        }

        [TestMethod()]
        public void PrintReadingTest()
        {
            
            string lineToBePrinted = Receiver.PrintReading(sensorReading);

            Assert.AreEqual(lineToBePrinted, "\n\n------------------------- New Reading ---------------------\n+ New reading --> Temperature : 60 , StateOfCharge: 30");
        }

        [TestMethod()]
        public void PrintStatisticsTest()
        {
            string lineToBePrinted = Receiver.PrintStatistics(sensorReadings);

            Assert.AreEqual(lineToBePrinted, "------------------------- Statistics ----------------------\nTemperature -> Max: 60 Min: 20 SMA: 40\nState of Charge -> Max: 40 Min: 30 SMA: 35\n-----------------------------------------------------------");
        }
    }
}