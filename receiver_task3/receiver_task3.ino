
 #include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int a = 10;
void setup() 
{
  pinMode(a, INPUT_PULLUP);
  lcd.begin(16,2);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() 
{
int g = 8;
int h = 9;
  // print the string when a newline arrives:
  if (stringComplete)
  {
    if(inputString[0] != 0x0A)
    {
    lcd.setCursor(0,0);
    lcd.print("TEMP:");
    lcd.print(inputString[0]);
    lcd.print(inputString[1]);
    }
    
 
   
    
    
    if(inputString[0]==0x0A)
    {
    lcd.setCursor(0,0);
    lcd.print("TEMP:");
    lcd.print(inputString[1]);
    lcd.print(inputString[2]);
 
  }
    
    
  //  Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  if(digitalRead(a) == LOW)
  {
    Serial.println(g);
  }
  else
  {
    Serial.println(h);
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
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


