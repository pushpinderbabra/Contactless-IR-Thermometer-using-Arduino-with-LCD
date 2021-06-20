#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Define I2C address of lcd, number of columns and rows
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(2,3,4,5,6,7);

double temp_amb;
double temp_obj;

void setup()
{
  Serial.begin(9600);
  Serial.println("Temperature Sensor MLX90614");

  //Initialize LCD I2C
  lcd.begin(16, 2);

  //Initialize MLX90614
  mlx.begin();
 
}

void loop()
{

  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempF();
  if(temp_obj > 99) {
   
   Serial.print("Warning...HIGH TEMP...");
   lcd.clear();
   lcd.print("HIGH TEMPERATURE");
   delay(1200);}
  else{
    
  }
 
  //lcd display 
  lcd.setCursor(0, 0);
  lcd.print("Room Temp:");
  lcd.setCursor(10, 0);
  lcd.print(temp_amb);
  lcd.print("C");
  lcd.setCursor(16, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print("Body Temp:");
  lcd.setCursor(10, 1);
  lcd.print(temp_obj);
  lcd.print("F");
  lcd.setCursor(16, 1);
  lcd.write(1);

  //Serial Monitor
  Serial.print("Room Temp = ");
  Serial.println(temp_amb);
  Serial.print("Object temp = ");
  Serial.println(temp_obj); 

  delay(1000);
}
