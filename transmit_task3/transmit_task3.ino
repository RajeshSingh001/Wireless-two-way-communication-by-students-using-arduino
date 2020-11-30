
#include<LiquidCrystal.h>;
//int buttonState = 0;// variable for reading the pushbutton status
LiquidCrystal lcd(7,6,5,4,3,2);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int r = 10;

void setup() 
{
  pinMode(r, OUTPUT);
  Serial.begin(9600);
  inputString.reserve(200);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Welcome to Data");
  lcd.setCursor(0,1);
  lcd.print("Transmission");
  delay(200);
  lcd.clear(); 
}

void loop()
{
  int sensorValue = analogRead(A0);
  int TEMP=sensorValue/2;
  lcd.setCursor(0,0);
  lcd.print("TEMP1:");
  lcd.print(TEMP);
  Serial.println(TEMP);
  
  
    if (stringComplete)
  {
    if(inputString[0] != 0x0A)
 {
  if(inputString[0] == '8')
  {
    digitalWrite(r, HIGH);
  }
  else if(inputString[0] == '9')
  {
    digitalWrite(r, LOW);
  }
 
 }
   
    
    
    if(inputString[0]==0x0A)
    {
    if(inputString[1] == '8')
  {
    digitalWrite(r, HIGH);
  }
  else if(inputString[1] == '9')
  {
    digitalWrite(r, LOW);
  }

  }
    
    
  //  Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  

delay(50);
  
}
void serialEvent()
{
  while (Serial.available()>0)
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 0x0D) 
    {
      stringComplete = true;
    } 
  }
}

