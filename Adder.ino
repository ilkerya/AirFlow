
void CSV_Header(void) {
  String SerialOut = "";
  SerialOut += "AirTemp," ;
  SerialOut += "Humidity," ;
  SerialOut += "Voltage," ;
  SerialOut += "Resistance,"  ;
  SerialOut += "Power,"  ;
  SerialOut += "AirViscosity," ;
  SerialOut += "NTCBulbTemp," ;
  SerialOut += "AirDissipation," ;
  SerialOut += "AirConductivity," ;
  SerialOut += "S_k,"  ;
  SerialOut += "D1,"  ;
  SerialOut += "D2,"  ;
  SerialOut += "D3,"  ;
  SerialOut += "D4," ;
  SerialOut += "AirSpeed" ;
  Serial.println(SerialOut);
}
void CSV_Data(void) {
  //SerialOut = "";
  String SerialOut = String(AirTemp, 2) + ',' ;
  SerialOut += String(Humidity, 2) + ',' ;
  SerialOut += String(Voltage, 3) + ',' ;
  SerialOut += String(Resistance, 16) + ',' ;
  SerialOut += String(Power, 16) + ',' ;
  SerialOut += String(AirViscosity, 16) + ',' ;
  SerialOut += String(NTCBulbTemp, 16) + ',' ;
  SerialOut += String(AirDissipation, 16) + ',' ;
  SerialOut += String(AirConductivity, 16) + ',' ;
  SerialOut += String(S_k, 16) + ',' ;
  SerialOut += String(D1, 16) + ',' ;
  SerialOut += String(D2, 16) + ',' ;
  SerialOut += String(D3, 16) + ',' ;
  SerialOut += String(D4, 16) + ',' ;
  SerialOut += String(AirSpeed, 16) ;
  Serial.println(SerialOut);
}

void  Run_AirSpeed(void) {

  Resistance = Voltage / Current;
  Power = Voltage * Current;

  AirViscosity = v3 + v2 * AirTemp;
  //AirViscosity += v1*sqrt(AirTemp);
  AirViscosity += v1 * pow(AirTemp, 2);
  AirViscosity += vrh2 * Humidity;
  // AirViscosity += -vrh1*sqrt(Humidity);
  AirViscosity += -vrh1 * pow(Humidity, 2);

  NTCBulbTemp = a1;
  NTCBulbTemp += a2 * log(Resistance);
  NTCBulbTemp += a3 * log(Resistance) * log(Resistance) ;
  NTCBulbTemp += a4 * log(Resistance) * log(Resistance) * log(Resistance);
  NTCBulbTemp = 1 / NTCBulbTemp;

  AirDissipation = NTCBulbTemp - (AirTemp + Kelvin);
  AirDissipation = Power / AirDissipation ;


  AirConductivity = k3;
  AirConductivity += k2 * AirTemp;
  AirConductivity += -k1 * pow(AirTemp, 2);
  AirConductivity += krh2 * Humidity;
  AirConductivity += -krh1 * pow(Humidity, 2);

  S_k = AirDissipation / AirConductivity;

  D1 = -D1a * pow(AirTemp, 5);
  D1 += D1b * pow(AirTemp, 4);
  D1 += -D1c * pow(AirTemp, 3);
  D1 += D1d * pow(AirTemp, 2);
  D1 += -D1e * AirTemp;
  D1 += D1f;

  /*
      D1 = D1f;  Serial.println(D1,8);
      D1 += D1e*AirTemp*(-1.00); Serial.println(D1,8);
      D1 += D1d*pow(AirTemp, 2);   Serial.println(D1,8);
      D1 += D1c*pow(AirTemp, 3)*(-1.00);   Serial.println(D1,8);
      D1 += D1b*pow(AirTemp, 4);Serial.println(D1,8);
      D1 += -D1a*pow(AirTemp, 5);Serial.println(D1);
  */

  D2 = pow(AirTemp, 5);
  D2 *= D2a;
  D2 += -D2b * pow(AirTemp, 4);
  D2 += D2c * pow(AirTemp, 3);
  D2 += -D2d * pow(AirTemp, 2);
  D2 += D2e * AirTemp;
  D2 += -D2f;


  D3 = -D3a * pow(AirTemp, 5);
  D3 += D3b * pow(AirTemp, 4);
  D3 += -D3c * pow(AirTemp, 3);
  D3 += D3d * pow(AirTemp, 2);
  D3 += -D3e * AirTemp;
  D3 += D3f;


  D4 = D4a * pow(AirTemp, 5);
  D4 += -D4b * pow(AirTemp, 4);
  D4 += D4c * pow(AirTemp, 3);
  D4 += -D4d * pow(AirTemp, 2);
  D4 += D4e * AirTemp;
  D4 += -D4f;

  AirSpeed = D1 * pow(S_k, 3);
  AirSpeed += D2 * pow(S_k, 2);
  AirSpeed += D3 * S_k ;
  AirSpeed += D4;
  AirSpeed *= AirViscosity;

}

void PrintOutputs(void) {
  /*
     Serial.println();
      Serial.println();
       switch(sizeof(AirSpeed)){
      case 2 : Serial.println("IEE754 Half Precision");
      break;
      case 4 : Serial.println("IEE754 Single Precision");
      break;
      case 8:Serial.println("IEE754 Double Precision");
      break;
      default:Serial.println("What The Hell");
      break;
     }
  */




  /*
    Serial.print("Resistance :");
    Serial.println(Resistance,32);
      Serial.print("Power :");
    Serial.println(Power,32);
    Serial.print("AirViscosity :");
    Serial.println(AirViscosity,32);
    Serial.print("NTCBulbTemp :");
    Serial.println(NTCBulbTemp,32);
      Serial.print("AirDissipation :");
    Serial.println(AirDissipation,32);
    Serial.print("AirConductivity :");
    Serial.println(AirConductivity,32);
      Serial.print("S_k :");
    Serial.println(S_k,32);
    Serial.print("D1 :");
    Serial.println(D1,32);
      Serial.print("D2 :");
    Serial.println(D2,32);
    Serial.print("D3 :");
    Serial.println(D3,32);
      Serial.print("D4 :");
    Serial.println(D4,32);
      Serial.print("AirSpeed :");
    Serial.println(AirSpeed,32);
  */
}
