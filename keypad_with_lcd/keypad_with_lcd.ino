#include <Keypad.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

void function(void);
void home_screen(void);
void valid_sympol(void);
void check_value(void);

const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[rows] = {9, 8, 7, 6}; 
byte colPins[cols] = {5, 4, 3, 2}; 


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);


String inputnumber = "";
String var;

int number;
int count = 0;
unsigned char eq2_counter = 0;
unsigned char eq4_counter = 0;

float R2_2 = 0;
float R2_4 = 0;

int counter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter The equation Sympol (A, B, C, D, #):");
  lcd.init(); 
  lcd.backlight();
  home_screen();
}

void loop() {
  char key = keypad.getKey();
  if(key)
  {
  //Serial.println(key);
  if(key == 'A')
  {
      // equation 1
      const float R1 = 1000;
      const float R2 = 1000;
      float R3 = 0;
      float Rx = 0;

      var = "R3";

      Serial.println("Equation -> 1");
      Serial.println("Rx=((R3*R2)/R1)");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Equation -> 1");
      lcd.setCursor(1, 1);
      lcd.print("Rx=((R3*R2)/R1)");
      delay(3000); // change it if you want
      lcd.clear();

      function();

      check_value();

      if(counter == 0)
      {
      R3 = number;
      Rx = ((R2 * R3) / R1);

      Serial.print("Rx = ");
      Serial.println(Rx);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Rx = ");
      lcd.setCursor(5, 0);
      lcd.print(Rx);
      }

      R3 = 0;
      var = "";

      counter = 0;

      Serial.println("Enter The equation Sympol (A, B, C, D, #):");
      
      
      delay(5000);
      home_screen();
    }
    else if(key == 'B')
    {
      // equation 2
      const float R1 = 10000;
      const float L1 = 1000;
      float Lx = 0;

      var = "R2";

      Serial.println("Equation -> 2");
      Serial.println("Lx=(L1*(R2/R1))");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Equation -> 2");
      lcd.setCursor(1, 1);
      lcd.print("Lx=(L1*(R2/R1))");
      delay(3000); // change it if you want
      lcd.clear();

      function();

      check_value();
      
      if(counter == 0)
      {
      R2_2 = number;
      Lx = (L1 * (R2_2 / R1));

      Serial.print("Lx = ");
      Serial.println(Lx);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lx = ");
      lcd.setCursor(5, 0);
      lcd.print(Lx);
      }

      var = "";
      
      counter = 0;

      Serial.println("Enter The equation Sympol (A, B, C, D, #):");
      
      
      delay(5000);
      home_screen();
      eq2_counter = 1;

    }
    else if(key == 'C')
    {
      if(eq2_counter == 1)
      {
      // equation 3
      const float R1 = 10000;
      float R3 = 0;
      float Rx = 0;

      var = "R3";

      Serial.println(R2_2);

      Serial.println("Equation -> 3");
      Serial.println("Rx=(R3*(R2/R1))");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ٌR2 = ");
      lcd.print(R2_2);
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Equation -> 3");
      lcd.setCursor(1, 1);
      lcd.print("Rx=(R3*(R2/R1))");
      delay(3000); // change it if you want
      lcd.clear();

      function();

      check_value();

      if(counter == 0)
      {
      R3 = number;
      Rx = (R3 * (R2_2 / R1));

      Serial.print("Rx = ");
      Serial.println(Rx);

      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Rx = ");
      lcd.setCursor(5, 0);
      lcd.print(Rx);
      }

      R3 = 0;
      var = "";

      counter = 0;
      eq2_counter = 0;

      Serial.println("Enter The equation Sympol (A, B, C, D, #):");
      
      
      delay(5000);
      home_screen();
            }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You must use eq");
        lcd.setCursor(2, 1);
        lcd.print("2 first for R2");
        delay(3000);
        home_screen();
      }
      R2_2 = 0;
    }
    else if(key == 'D')
    {
      // equation 4
      const float R1 = 978;
      const float C3 = 100;
      float Cx = 0;

      var = "R2";

      Serial.println("Equation -> 4");
      Serial.println("Cx=((R1/R2)*C3)");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Equation -> 4");
      lcd.setCursor(1, 1);
      lcd.print("Cx=((R1/R2)*C3)");
      delay(3000); // change it if you want
      lcd.clear();

      function();

      check_value();

      if(counter == 0)
      {
      R2_4 = number;
      Cx = ((R1 / R2_4) * C3);

      Serial.print("Cx = "); 
      Serial.println(Cx);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Cx = ");
      lcd.setCursor(5, 0);
      lcd.print(Cx);
      }

      var = "";

      counter = 0;
      eq4_counter = 1;

      Serial.println("Enter The equation Sympol (A, B, C, D, #):");
            
      delay(5000);
      home_screen();
    }
    else if(key == '#')
    {
      if(eq4_counter == 1)
      {
      // equation 3
      const float R1 = 10000;
      float R3 = 0;
      float Rx = 0;

      var = "R3";

      Serial.println(R2_4);

      Serial.println("Equation -> 5");
      Serial.println("Rx=(R3*(R2/R1))");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ٌR2 = ");
      lcd.print(R2_4);
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Equation -> 5");
      lcd.setCursor(1, 1);
      lcd.print("Rx=(R3*(R2/R1))");
      delay(3000); // change it if you want
      lcd.clear();

      function();

      check_value();

      if(counter == 0)
      {
      R3 = number;
      Rx = (R3 * (R2_4 / R1));

      Serial.print("Rx = ");
      Serial.println(Rx);

      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Rx = ");
      lcd.setCursor(5, 0);
      lcd.print(Rx);
      }

      R2_4 = 0;
      var = "";

      counter = 0;
      eq4_counter = 0;

      Serial.println("Enter The equation Sympol (A, B, C, D, #):");
      
      
      delay(5000);
      home_screen();
            }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You must use eq");
        lcd.setCursor(2, 1);
        lcd.print("4 first for R2");
        delay(3000);
        home_screen();
      }
      R2_2 = 0;
    }
    else if(key == '*')
    {
      // equation 5
      int counter_ = 0;

      const float R1 = 1000;
      const float R2 = 1000;
      float Ax = 0;
      float Px = 0;
      float Pa = 0;
      float La = 0;
      float Aa = 0;
      float Pb = 0;
      float Lb = 0;
      float Ab = 0;
      float Lx = 0;


      Serial.println("Equation -> #");
      Serial.println("Lx=(Ax/Px*((R1/(R1+R2))*(((Pa*La)/Aa)+((Pb*Lb)/Ab)))"); // 52 characters

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Equation -> 6");
      delay(3000); // change it if you want
      lcd.clear();

      var = "Ax";

      function();
      
      check_value();

      if(counter == 0)
      {
        counter_ ++;
      }

      Ax = number;

      var = "";
      counter = 0;
      number = 0;

      var = "Px";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      Px = number;

      var = "";
      counter = 0;
      number = 0;

      var = "Pa";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      Pa = number;
      
      var = "";
      counter = 0;
      number = 0;

      var = "La";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      La = number;
      
      var = "";
      counter = 0;
      number = 0;

      var = "Aa";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      Aa = number;

      var = "";
      counter = 0;
      number = 0;
      
      var = "Pb";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      Pb = number;
      
      var = "";
      counter = 0;
      number = 0;

      var = "Lb";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      Lb = number;

      var = "";
      counter = 0;
      number = 0;
      
      var = "Ab";

      function();
      
      check_value();
      if(counter == 0)
      {
        counter_ ++;
      }

      Ab = number;

      var = "";
      counter = 0;
      number = 0;

      Serial.println(counter_);

      if(counter_ == 8)
      {
        // Serial.println(Lx);
        // Serial.println(Ax);
        // Serial.println(Px);
        // Serial.println(La);
        // Serial.println(Aa);
        // Serial.println(Pa);
        // Serial.println(Lb);
        // Serial.println(Ab);
        // Serial.println(Pb);
      Lx = (Ax/Px*((R1/(R1+R2))*(((Pa*La)/Aa)+((Pb*Lb)/Ab))));

      Serial.print("Lx = ");
      Serial.println(Lx);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lx = ");
      lcd.setCursor(5, 0);
      lcd.print(Lx);
      delay(3000);
      }
      else
      {
        Serial.println("one or more invalid input");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("one or more");
        lcd.setCursor(3, 1);
        lcd.print("invalid input");
        delay(3000);
      }

      


      Serial.println("Enter The equation Sympol (A, B, C, D, #):");
            
      
      home_screen();
    }
    else
    {
      Serial.println("Enter a valid equation sympol (A, B, C, D, #):");
      valid_sympol();
      delay(3000);
      home_screen();
    }
  }
}


void function(void)
{
  number = 0;
  Serial.print("Enter ");
  Serial.print(var);
  Serial.println(':');

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter ");
  lcd.setCursor(6, 0);
  lcd.print(var);
  lcd.setCursor(8, 0);
  lcd.print(':');

  while(1)
  {
  char key = keypad.getKey();
  if(key == 'A' || key == 'B' || key == 'C' || key == 'D')
  {
    Serial.println("No letters are allowed");
    Serial.print(var);
    Serial.print('=');
    Serial.println(inputnumber);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Only numbers!!");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(var);
    lcd.setCursor(2, 0);
    lcd.print('=');
    lcd.setCursor(3, 0);
    lcd.print(inputnumber);
    
    continue;
  }
  else
  {
  if (key) {
    // Serial.print("Key Pressed: ");
    // Serial.println(key);
    if (key == '*') { // Delete the last character
      if (count > 0) {
        count--;
        inputnumber.remove(count);        
        Serial.print(var);
        Serial.print('=');
        Serial.println(inputnumber);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(var);
        lcd.setCursor(2, 0);
        lcd.print('=');
        lcd.setCursor(3, 0);
        lcd.print(inputnumber);
      }
    } else if (key == '#') 
    { 
      // Serial.println(inputnumber);
      
      number = inputnumber.toInt();

      // Reset the input
      inputnumber = "";
      count = 0;
      break;
    } else { // Add the character to the input
      if (count < 4) { // Limit the password length
        inputnumber += key;
        count++;
        Serial.print(var);
        Serial.print('=');
        Serial.println(inputnumber);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(var);
        lcd.setCursor(2, 0);
        lcd.print('=');
        lcd.setCursor(3, 0);
        lcd.print(inputnumber);
      }
    }
  }
  }
  }
}

void home_screen(void)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Choose equation");
  // lcd.setCursor(15, 0);
  // lcd.print("-");
  // lcd.setCursor(0, 1);
  // lcd.print("-->");
  lcd.setCursor(0, 1);
  lcd.print("A, B, C, D, #, *");
}

void valid_sympol(void)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Only letters");
  lcd.setCursor(0, 1);
  lcd.print("(A, B, C, D, #):");   
}

void check_value(void)
{
    while(number > 1000)
      {
        Serial.print(var);
        Serial.println(" should be between 0 and 1000");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(var);
        lcd.setCursor(3, 0);
        lcd.print("should be");
        lcd.setCursor(2, 1);
        lcd.print("from 0 -> 1000");

        counter = 1;

        delay(3000);
        break;
      }
}