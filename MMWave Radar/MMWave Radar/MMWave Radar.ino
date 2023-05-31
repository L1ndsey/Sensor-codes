/**
      @brief Constructor 
      @param Stream  Software serial port interface 
    */
    //DFRobot_mmWave_Radar(Stream *s);

    /**
      @brief  Configure sensor detection area  
      @param parA_s The sensing area distance starting value of the first segment, unit: m  
      @param parA_e The sensing area distance ending value of the first segment, unit: m(Must be greater than the starting value of the current sensing area)
    */
    void DetRangeCfg(float parA_s, float parA_e);


    /**
      @brief  Configure sensor detection area 
      @param parA_s The sensing area distance starting value of the first segment, unit: m
      @param parA_e The sensing area distance ending value of the first segment, unit: m(Must greater than the starting value of the current sensing area)
      @param parB_s The sensing area distance starting value of the second segment, unit: m(Must be greater than the ending value of the previous segment sensing area) 
      @param parB_e The sensing area ending value of the second segment, unit: m(Must be greater than the starting value of the current sensing area)
    */
    void DetRangeCfg(float parA_s, float parA_e, float parB_s, float parB_e);


    /**
      @brief  Configure sensor detection area 
      @param parA_s The sensing area distance starting value of the first segment, unit: m
      @param parA_e The sensing area distance ending value of the first segment, unit: m (Must be greater than the starting value of the current sensing area)
      @param parB_s The sensing area distance starting value of the second segment, unit: m(Must be greater than the ending value of the previous segment sensing area)
      @param parB_e The sensing area distance ending value of the second segment, unit: m(Must be greater than the starting value of the current sensing area)
      @param parC_s The sensing area distance starting value of the third segment, unit: m(Must be greater than the ending value of the previous segment sensing area)
      @param parC_e The sensing area distance ending value of the third segment, unit: m(Must be greaer than the starting value of the current sensing area)
    */
    void DetRangeCfg(float parA_s, float parA_e, float parB_s, float parB_e, float parC_s, float parC_e);


    /**
      @brief  Configure sensor detection area 
      @param parA_s The sensing area distance starting value of the first segment, unit: m 
      @param parA_e The sensing area distance ending value of the first segment, unit: m(Must be greater than the starting value of the current sensing area)
      @param parB_s The sensing area distance starting value of the second segment, unit: m(Must be greatet than the ending value of the previous segment sensing area)
      @param parB_e The sensing area distance ending value of the second segment, unit: m(Must be greater than the starting value of the current sensing area)
      @param parC_s The sensing area distance starting value of the third segment, unit: m(Must be greater than the ending value of the previous segment sensing area)
      @param parC_e The sensing area distance ending value of the third segment, unit: m(Must be greater than the starting value of the current sensing area)
      @param parD_s The sensing area distance starting value of the fourth segment, unit: m(Must be greater than the ending value of the previous segment sensing area)
      @param parD_e The sensing area ditance ending value of the fourth segment, unit: m(Must be greater than the starting value of the current sensin area)
    */
    void DetRangeCfg(float parA_s, float parA_e, float parB_s, float parB_e, float parC_s, float parC_e, float parD_s, float parD_e);


    /**
      @brief  Read whether there is people or object moving in the sensing area
      @return  Returning true means that there is people or animal moving in the detection range; false means the opposite
    */
    bool readPresenceDetection(void);


    /**
      @brief  Configure sensor output delay time 
      @param par1 When a target detected, delay the output time of sensing result, range：0~1638.375, unit: s 
      @param par2 When the target disappears, delay the output time of sensing result, range: 0~1638.375, unit: s
    */
    void OutputLatency(float par1, float par2);


    /**
      @brief  Restore the sensor current configuration to the factory settings. 
    */
    void factoryReset(void);

/*!
   @file DFRobot_mmWave_Radar.ino
   @ Read whether there is people or object moving in the detection range of the sensor. 
   @ The sensor detection range and output delay time can be configured. Also you can restore the sensor to factory default settings. 
   @n Experimental phenomenon: When the sensor starts successfully, 0 or 1 will be printed on the serial monitor. 
   @ 0 means that there is no human or object moving in sensing area, 1 means the oppposite. 
   @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [huyujie](yujie.hu@dfrobot.com)
   @version  V1.0
   @date  2020-3-25
   @https://github.com/DFRobot
*/


#include <SoftwareSerial.h>

#include "DFRobot_mmWave_Radar.h"

SoftwareSerial mySerial(3, 2);
DFRobot_mmWave_Radar sensor(&mySerial);

int ledPin = 13;

void setup()
{
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(ledPin, OUTPUT);

  sensor.factoryReset();    //Restore to the factory settings 
  sensor.DetRangeCfg(0, 9);    //The detection range is as far as 9m
  sensor.OutputLatency(0, 0);
}

void loop()
{
  int val = sensor.readPresenceDetection();
  digitalWrite(ledPin, val);
  Serial.println(val);
}