#include <array>
#include <string>
#include <time.h>
#include "pico/stdlib.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Address, Columns, Rows

unsigned short answer;
std::array<std::string, 1000> input_list;

void parse()
{
  char input_str[] = "..." // Input is pasted here as a multi-line string that is 1000 lines long.
  
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

    unsigned char first_num = 'A';
    unsigned char last_num = 'A';

    for (size_t char_index = 0; char_index < strlen(str); char_index++)
    {
      if (isdigit(str[char_index]))
      {
        last_num = str[char_index];
        if (first_num == 'A')
        {
          first_num = last_num;
        }
      }
    }

    char num[2];
    sprintf(num, "%c%c", first_num, last_num);

    answer += (unsigned short) strtoul(num, NULL, 10);
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
