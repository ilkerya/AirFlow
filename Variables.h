
struct SensorData
{
  float Humidity = 0;
  float Temperature = 0;
  uint8_t Id = 0;
};

SensorData Sensor ;

#define RESISTOR_HIGH 10000 // 10K
#define RESISTOR_LOW 3300  // 3K3
  int16_t Adc_10bit, Adc_12bit; 
  float Vreal_10bit, Vreal_12bit;

int Counter;

double a1 = -0.01164;    // c3
double a2 = 0.008126;    // c4
double a3 = -0.001557;   // c5
double a4 = 0.0001025;   // c6

double Current = 0.034;  //c7 
double Kelvin = 273.15;  //c8

double const   D1a = 1636.4409 ;// c10
double const   D1b = 215689.3377 ;// c11
double const   D1c = 11082088.6657 ;// c12
double const   D1d = 278057421.4872  ;// c13
double const   D1e = 3413265323.7325 ;// c14
double const   D1f = 16438734835.3564  ;// c15
double const   D2a = 974.5457  ;// c16
double const   D2b = 128654.069  ;// c17
double const   D2c = 6619830.2817  ;// c18
double const   D2d = 166316354.8414  ;// c19
double const   D2e = 2044018673.7919 ;// c20
double const   D2f = 9843764074.406  ;// c21
double const   D3a = 192.8673  ;// c22
double const   D3b = 25177.7172  ;// c23
double const   D3c = 1284067.9052  ;// c24
double const   D3d = 32029909.1427 ;// c25
double const   D3e = 391313302.5273  ;// c26
double const   D3f = 1874600544.4209 ;// c27
double const   D4a = 11.9134 ;    // c28
double const   D4b = 1538.2402 ;// c29
double const   D4c = 77756.7512  ;// c30
double const   D4d = 1925437.9308  ;// c31
double const   D4e = 23379889.6658 ;// c32
double const   D4f = 111422572.3911  ;// c33

double const   v1  = 5.32911E-10 ; // c35
double const   v2  = 7.00072E-08 ; // c36
double const   v3  = 1.25777E-05 ; // c37
double const  vrh1 =   1.51031E-06 ; // c38
double const  vrh2 = 2.69159E-06 ; // c39
double const   k1  = 1.27657E-08 ; // c40
double const   k2  = 8.18685E-05 ; // c41
double const   k3  = 0.0231732884  ; // c42
double const  krh1 = 0.00200839857 ; // c43
double const krh2  = 0.00189815111 ; // c44

double AirTemp = 26.00;  //F3 
double Voltage = 6.75;   //F4 
double Humidity = 0.5;   //F5 

double Resistance = 0.00;  //I3 
double Power = 0.00;       //I4 
double AirViscosity = 0.00;//I5 
double NTCBulbTemp = 0.00; //I6 
double AirDissipation = 0.00;//I7
double AirConductivity = 0.00;//I8
double S_k = 0.00;           //I9
double D1 = 0.00;           //I10
double D2 = 0.00;           //I11
double D3  = 0.00;           //I12
double D4 = 0.00;           //I13
double AirSpeed = 0.00;     //I14

/*
#ifdef ARDUINO_MEGA
    
float a1 = -0.01164;    // c3
float a2 = 0.008126;    // c4
float a3 = -0.001557;   // c5
float a4 = 0.0001025;   // c6

float Current = 0.034;  //c7 
float Kelvin = 273.15;  //c8

float const   D1a = 1636.4409 ;// c10
float const   D1b = 215689.3377 ;// c11
float const   D1c = 11082088.6657 ;// c12
float const   D1d = 278057421.4872  ;// c13
float const   D1e = 3413265323.7325 ;// c14
float const   D1f = 16438734835.3564  ;// c15
float const   D2a = 974.5457  ;// c16
float const   D2b = 128654.069  ;// c17
float const   D2c = 6619830.2817  ;// c18
float const   D2d = 166316354.8414  ;// c19
float const   D2e = 2044018673.7919 ;// c20
float const   D2f = 9843764074.406  ;// c21
float const   D3a = 192.8673  ;// c22
float const   D3b = 25177.7172  ;// c23
float const   D3c = 1284067.9052  ;// c24
float const   D3d = 32029909.1427 ;// c25
float const   D3e = 391313302.5273  ;// c26
float const   D3f = 1874600544.4209 ;// c27
float const   D4a = 11.9134 ;    // c28
float const   D4b = 1538.2402 ;// c29
float const   D4c = 77756.7512  ;// c30
float const   D4d = 1925437.9308  ;// c31
float const   D4e = 23379889.6658 ;// c32
float const   D4f = 111422572.3911  ;// c33

float const   v1  = 5.32911E-10 ; // c35
float const   v2  = 7.00072E-08 ; // c36
float const   v3  = 1.25777E-05 ; // c37
float const  vrh1 =   1.51031E-06 ; // c38
float const  vrh2 = 2.69159E-06 ; // c39
float const   k1  = 1.27657E-08 ; // c40
float const   k2  = 8.18685E-05 ; // c41
float const   k3  = 0.0231732884  ; // c42
float const  krh1 = 0.00200839857 ; // c43
float const krh2  = 0.00189815111 ; // c44

float AirTemp = 26.00;  //F3 
float Voltage = 6.75;   //F4 
float Humidity = 0.5;   //F5 


  Vreal_10 = (5 * NTC_Adc ) / (RESISTOR_LOW *1024 ) // 10 bit
  Vreal_10  *= (RESISTOR_LOW + RESISTOR_HIGH ) // 10 bit 
     
  Vreal_12 = (3.3 * NTC_Adc ) / (RESISTOR_LOW*4096 ) // 12 bit
  Vreal_12  *= (RESISTOR_LOW + RESISTOR_HIGH )  // 12 bit    

   3V3--10K--Adc--3K3--GND   // DUE
   5V--10K--Adc--3K3--GND   // MEGA
   // 10Bit 1024 5V/1024 = 0.004882 
   // 12Bit 4096 3V3/4096 = 0.00080566 

 = (V / 13.3 ) * 3.3 
 = (6.75/ 13.3) * 3.3 
 = 1.6748

  Vread = (3.3 * NTC_Adc) / 4096; // Due
  Vread = (5 * NTC_Adc) / 1024; // Mega
  Vreal = (Vread / 3.3)*13.3 //Due or Mega
  
  Vreal_10 = (5 * NTC_Adc ) / (RESISTOR_LOW *1024 ) // 10 bit
  Vreal_10  *= (RESISTOR_LOW + RESISTOR_HIGH ) // 10 bit 
     
  Vreal_12 = (3.3 * NTC_Adc ) / (RESISTOR_LOW*4096 ) // 12 bit
  Vreal_12  *= (RESISTOR_LOW + RESISTOR_HIGH )  // 12 bit    


float Resistance = 0.00;  //I3 
float Power = 0.00;       //I4 
float AirViscosity = 0.00;//I5 
float NTCBulbTemp = 0.00; //I6 
float AirDissipation = 0.00;//I7
float AirConductivity = 0.00;//I8
float S_k = 0.00;           //I9
float D1 = 0.00;           //I10
float D2 = 0.00;           //I11
float D3  = 0.00;           //I12
float D4 = 0.00;           //I13
float AirSpeed = 0.00;     //I14

*/
