// This is a program that simultaneously measures the an applied pressure and temperature
// while outputting to an LCD and to serial
//Pressure Sensor:  MPX4250AP - Measures the absolute pressure and can be connected to tubing
//Temp Sensor:  TMP37FT9Z - sensors that measures temperature immediately surrounding the device
//LCD 16x2 (details needed)

//Library List
#include <LiquidCrystal.h>
#include <thermistor.h>

//Initialize the library with the number of interface pins
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);

//Configure thermistor instance 
//Calibration coeffs for RSBR-302J-Z50 Teflon-Coated 3k Thermistor
#define A 3.3501
#define B 0.5899
#define C 0.0104
#define R_25C 3000.0 /*ohms*/
#define R_STANDARD 10000.0 /*ohms*/
Thermistor thermistor1(A,B,C,R_25C,R_STANDARD);

//Defining the board input Analog Pins for the sensors
int PressurePin = 0;     // Analog Pressure measure (Requires 5V)
int TempPin = 5;         // Analog Temp measure (Requires 5V)

//Defining the Pressure Variables
float pressureVout = 0;  // variable to store the voltage from Pressure Sensor
float pressure;          // Variable to store the pressure value in kPa
float Vin = 5.0;         // Defining the input volate as 5V


//Defining the temperature variables
float tempVout;          // variable to store the voltage from Temp Sensor
float temperature;       // variable to store the temperature in degrees C
float tempVin=5.0;       // Defining the input volate as 5V

//Taking a measurement
void setup()
{
  
  Serial.begin(9600);    //  setup serial

  thermistor1.begin(5);  // configure the analog sense pin
  lcd.begin(16, 2);      // set up the LCD's number of columns and rows: 
  lcd.print("Press. and Temp."); //Print a message to the LCD
}

void loop()
{
  
  // read the temp and pressure values
  pressureVout = (analogRead(PressurePin)/1024.0)*Vin;    // read the input pin (scaled to the volatge input)
  pressure=((pressureVout/5.0)+.04)/.004;                 // scaling in kPa from data sheet
  float pressureATM=pressure/101.325;                     // convert to atm
  double temperature=firstThermistor.readTemperature();
  
 
  // display on the LCD
  lcd.setCursor(0, 1); //set the cursor to column 0, line 1 (line 1 is the second row, counting begins with 0)
  lcd.print(pressureATM,2);             
  lcd.print(" atm; ");
  lcd.print(temperature, 1);
  lcd.print(" C");
 
 
  //Serial output (in YAML format)
  Serial.println("---");
  Serial.print("pressure_ATM: ");
  Serial.println(pressureATM,3);
  Serial.print("temperature_C: ");
  Serial.println(temperature,3);
  Serial.println("...");
 
  delay(1000);           //delay in milliseconds 1000ms = 1 s
}
