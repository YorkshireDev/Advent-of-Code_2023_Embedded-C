# Advent of Code 2023 - Embedded C
Doing Advent of Code 2023 on a Raspberry Pi Pico using C and the Arduino IDE

## How do you get an answer?

I have a 1602 LCD that I connected to a Raspberry Pi Pico on a breadboard. On the first row I print the answer and on the second I print the time taken in milliseconds. I'll include a text file with each Day/Part of how long it takes, can you beat the 133MHz Cortex M0+? :P

## What is `C_Line-Split_Tool.py`?

A multi-line string in C is defined like this:

```
char input_str[] = "First Line"
                   "Second Line"
                   "Third Line";      
```

But Advent of Code gives you your inputs like this:

```
First Line
Second Line
Third Line
```

So I made a quick Python script that I paste into the same directory as `Input.TXT` (omitted when pushing due to AoC licensing), and it will output the input list with the C syntax so I can just paste it into the code.

It has to be pasted into the code itself because a microcontroller has no operating system, you just flash the ROM with hex code and it starts executing - there is no concept of a filesystem, so no text files! Only a big block of code :)
