
//www.onlinegdb.com/edit/SyhIaKEJu
  
  Adafruit_Si7021 THsensor = Adafruit_Si7021();
  
  void SensorInit(){
	if (!THsensor.begin()) {
    #ifdef PRINTOUT 
		Serial.print(F("No Si7021 sensor Found"));
        #endif  
  //  delay(250);
  //  while (true)      
	}
	else{
  #ifdef PRINTOUT 
		Serial.print(F(" Si7021 sensor found!"));
    #endif     
		//   Serial.print(" Rev(");
		//  Serial.print(THsensor.getRevision());
		THsensor.getRevision();
	   //         Sensor1_Id.toUpperCase();     
		Sensor.Id = THsensor.sernum_a;
  
    #ifdef PRINTOUT 
		Serial.println(Sensor.Id ,HEX); 
    #endif
	}
}

 void SensorRead(){
	Sensor.Humidity = THsensor.readHumidity(); 
  #ifdef PRINTOUT 
	Serial.println("Humidity: "); Serial.println(Sensor.Humidity); 
  #endif
	Sensor.Temperature = THsensor.readTemperature();
  #ifdef PRINTOUT   
	Serial.println("Temperature: "); Serial.println(Sensor.Temperature); 
  #endif

  AirTemp = (double)Sensor.Temperature;
  Humidity = (double)Sensor.Humidity/100;
}

void Adc_Read(void){
  #ifdef ARDUINO_DUE
    #ifdef ADC_10BIT   
      analogReadResolution(10);
      Adc_10bit = analogRead(NTC_INPUT);
      // Vreal_10bit = (3.3 *(float)Adc_10bit ) / (RESISTOR_LOW *1024 ); // 10 bit
      // Vreal_10bit  *= (RESISTOR_LOW + RESISTOR_HIGH ); // 10 bit 
      Vreal_10bit = (float)Adc_10bit*3.3;
      Vreal_10bit /= 1024;
      Voltage = Vreal_10bit;
      #ifdef PRINTOUT 
      Serial.print("ADC 10-bit (default) : ");
      Serial.println(Adc_10bit);
      Serial.print("Vreal_10bit : ");
      Serial.println(Vreal_10bit);  
      #endif
    #endif
    #ifdef ADC_12BIT 
      analogReadResolution(12);
      Adc_12bit = analogRead(NTC_INPUT);
      // Vreal_12bit = (3.3 * (float)Adc_12bit ) / (RESISTOR_LOW*4096 ); // 12 bit
      //  Vreal_12bit  *= (RESISTOR_LOW + RESISTOR_HIGH );  // 12 bit  
      Vreal_12bit = (float)Adc_12bit*3.3;
      Vreal_12bit /= 4096;
      Voltage = Vreal_12bit;
      #ifdef PRINTOUT 
      Serial.print(", 12-bit : ");
      Serial.println(Adc_12bit);
      Serial.print("Vreal_12bit : ");
      Serial.println(Vreal_12bit);  
      #endif
    #endif    
  #endif //end of Arduino Due
  #ifdef ARDUINO_MEGA
    #ifdef PRINTOUT 
    Serial.print("ADC 10-bit (default) : ");
    Serial.println(Adc_10bit); 
    #endif      
  Adc_10bit = analogRead(NTC_INPUT);

  Vreal_10bit = (float)Adc_10bit*5;
  Vreal_10bit /= 1024;
  /*
  Vreal_10bit = (5 *(float)Adc_10bit ) / (RESISTOR_LOW *1024 ); // 10 bit
  Vreal_10bit  *= (RESISTOR_LOW + RESISTOR_HIGH ); // 10 bit 
  */
  Voltage = Vreal_10bit;

  
    #ifdef PRINTOUT 
    Serial.print("Vreal_10bit : ");
    Serial.println(Vreal_10bit);  
    #endif
  #endif //end of Arduino Mega
}
