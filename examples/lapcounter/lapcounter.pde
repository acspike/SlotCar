#include <TVout.h>
#include <font4x6.h>
#include <font8x8.h>
#include <SlotCar.h>


TVout TV;

SlotCar a = SlotCar(0, 700);
SlotCar b = SlotCar(2, 680);
SlotCar c = SlotCar(1, 700);

void display_car_line(SlotCar* c, int y) {
  TV.print(4*0,y,c->lapCount(),10);
  TV.print(4*4,y,c->lapTime(),3);
  TV.print(4*12,y,c->readLevel(),10);
}
void display_laps(){
  display_car_line(&a, 8*1);
  display_car_line(&b, 8*2);
  display_car_line(&c, 8*3);
}

void setup() {
  TV.begin(NTSC,88,70);
  
  //Count Down
  TV.select_font(font8x8);
  TV.clear_screen();
  TV.delay(2000);
  TV.print(24,24,"3");
  TV.tone(600,100);
  TV.delay(1000);
  TV.print(24,24,"2");
  TV.tone(600,100);
  TV.delay(1000);
  TV.print(24,24,"1");
  TV.tone(600,100);
  TV.delay(1000);
  TV.print(24,24,"GO!");
  a.start();
  b.start();
  c.start();
  TV.tone(1200,500);
  TV.delay(1000);
  
  TV.clear_screen();
  TV.select_font(font4x6);
}

void loop() {
    a.read();
    b.read();
    c.read();
    display_laps();
}


