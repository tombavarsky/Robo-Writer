#include <Arduino.h>
#include <Servo.h>

float broken_num[10];
int number[4];

const byte B_ARM = 7; //change later
const byte A_ARM = 4; //change later

Servo s1;
Servo s2;

const byte X1 = 7;  //check later
const byte X2 = 15; //check later
const byte BASE = X2 - X1;

float y = 5; //check later
float x = 8; //check later

int get_int_length(int num)
{
  if (num < 10)
    return 1;
  else
    return floor(log10(num)) + 1;
}

void set_angel(float x, float y)
{
  static float diagonal1;
  static float diagonal2;

  float s1_val;
  float s2_val;

  diagonal1 = sqrt(pow(X1 - x, 2) + pow(y, 2)); //5.1
  diagonal2 = sqrt(pow(X2 - x, 2) + pow(y, 2)); //8.6

  s1_val = (acos((pow(diagonal1, 2) + pow(BASE, 2) - pow(diagonal2, 2)) / (2 * BASE * diagonal1)) * 180 / M_PI)  //78.69
           + (acos((pow(A_ARM, 2) + pow(diagonal1, 2) - pow(B_ARM, 2)) / (2 * diagonal1 * A_ARM)) * 180 / M_PI); //99.88
                                                                                                                 //one of them should probably be 180 - answer
  s2_val = (acos((pow(diagonal2, 2) + pow(BASE, 2) - pow(diagonal1, 2)) / (2 * BASE * diagonal2)) * 180 / M_PI)  //35.54
           + (acos((pow(diagonal2, 2) + pow(A_ARM, 2) - pow(B_ARM, 2)) / (2 * A_ARM * diagonal2)) * 180 / M_PI); //53.43

  s1.write(s1_val);
  s2.write(s2_val);

  Serial.print(s1_val);
  Serial.print("\t");
  Serial.println(s2_val);
}

// void num_disassembler(int number)
// {
//   switch (number)
//   {
//   case:
//   }
// }

void setup()
{
  s1.attach(3);
  s2.attach(5);
  Serial.begin(9600);
}
void read_number()
{
  if (Serial.available() > 0)
  {
    int num = Serial.parseInt();
    int numLen = get_int_length(num);
    for (int i = numLen - 1; i >= 0; i--)
    {
      number[i] = num % 10;
      num /= 10;
    }
  }
}
void loop()
{

  read_number();
  delay(1000);
}
