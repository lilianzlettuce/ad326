#include <TVout.h>
#include<fontAll.h>
#include "schematic.h"
#include "TVOlogo.h"
#include "img.h"

TVout TV;

int screenWidth = 114;
int screenHeight = 90;

// Define input pins 
int input1 = A5;
int input2 = A4;

void setup() {
  TV.begin(NTSC,120,96);
  TV.select_font(font8x8);

  unsigned char w;
  w = pgm_read_byte(img);
  //TV.bitmap(15, 15, img);
  TV.bitmap(0, 0, img);
  TV.println(8, screenHeight - 10, "hello friend.");
  TV.delay(2000);

  /*//TV.println("★ & | * ^ % $ # @ \n ~( __.__ ~) {0} -- + : ; /\/\  >O<");
  TV.println("hello friend.");
  TV.println(50, 44, "uwu");
  TV.delay(2500);

  //intro();*/

  //TV.delay(50000);

  TV.select_font(font4x6);
  TV.select_font(font6x8);
  TV.select_font(font8x8);

  //TV.draw_rect(0, 0, screenWidth, screenHeight, 2, 2);
}

void loop() {
  int randomX = random(0, screenWidth);
  int randomY = random(0, screenHeight);
  //TV.println(randomX, randomY, "hello friend.");
  //TV.println(randomX, randomY, "★");

  // Invert screen color
  //TV.draw_rect(0, 0, screenWidth, screenHeight, 2, 2);
  
  TV.delay(50);

  // Read analog input pin for sample rate, put in range 0 to 2
  int reading1 = analogRead(input1);
  int val = reading1; //map(reading1, 0, 1023, 0, 2);

  if (val <= 100) {
    //TV.clear_screen();
    TV.select_font(font4x6);
    TV.println(randomX, randomY, random(0, 1000000000));
  } else if (val > 100 && val <= 200) {
    TV.select_font(font6x8);
    TV.println(randomX, randomY, "hello friend.");
  } else if (val > 200 && val <= 300) {
    TV.select_font(font8x8);
    TV.println(randomX, randomY, random(0, 1000000000));
  } else if (val > 300 && val <= 400) {
    TV.draw_rect(0, 0, screenWidth, screenHeight, 2, 2);
    TV.println(randomX, randomY, "hello friend.");
  } else if (val > 400 && val <= 500) {
    TV.draw_rect(0, 0, screenWidth, screenHeight, 2, 2);
  } else if (val > 500 && val <= 600) {
    TV.clear_screen();
    TV.println(8, screenHeight / 2, "hello friend.");
  } else {
    TV.clear_screen();
    TV.bitmap(randomX, randomY, img);
    TV.println(8, screenHeight / 2, "hello friend.");
  }
}

void intro() {
  unsigned char w,l,wb;
  int index;
  w = pgm_read_byte(TVOlogo);
  l = pgm_read_byte(TVOlogo+1);
  if (w&7)
    wb = w/8 + 1;
  else
    wb = w/8;
  index = wb*(l-1) + 2;
  for ( unsigned char i = 1; i < l; i++ ) {
    TV.bitmap((TV.hres() - w)/2,0,TVOlogo,index,w,i);
    index-= wb;
    TV.delay(50);
  }
  for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
    TV.bitmap((TV.hres() - w)/2,i,TVOlogo);
    TV.delay(50);
  }
  TV.delay(3000);
  TV.clear_screen();
}