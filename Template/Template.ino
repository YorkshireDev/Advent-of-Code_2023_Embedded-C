#include <array>
#include <string>
#include <time.h>
#include "pico/stdlib.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Address, Columns, Rows

unsigned <TYPE_HERE> answer;
std::array<std::string, <SIZE_HERE> > input_list;

void parse()
{
  char input_str[] = <INPUT_HERE>
  
  unsigned short int i = 0;
  
  char *input_line = strtok(input_str, "`");
  
  while (input_line != NULL)
  {
    input_list[i++] = input_line;
    input_line = strtok(NULL, "`");
  }
}

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.blink_off();
  lcd.clear();

  answer = 0;

  parse();
  
  absolute_time_t s_time = get_absolute_time();
  
  runOnce();

  absolute_time_t e_time = get_absolute_time(); 

  double time_taken = ((int64_t) absolute_time_diff_us(s_time, e_time)) / 1000.0; // Milliseconds

  char str[16];
  snprintf(str, sizeof(str), "Time: %.4f", time_taken);

  lcd.setCursor(0, 1);
  lcd.print(str);
}

void runOnce()
{
  for (unsigned short i = 0; i < sizeof(input_list) / sizeof(input_list[0]); i++)
  {
    const char* str = input_list[i].c_str();
    
    // Solution Here !!!
  }

  printAnswer();
}

void printAnswer()
{
  char str[16];
  snprintf(str, sizeof(str), "> %d", answer);
  
  lcd.setCursor(0, 0);
  lcd.print(str);
}

void loop() {}
