/* vim: set sw=2 expandtab tw=80: */

#include <stdio.h>

 // Pentru Dots Display Driver
 #include <timer.h>
 #include "dots_display.h"


int main(void) {
  
  // Pentru Dots Display Driver

   while (true) {
     for (int i = 0; i < 10; i++) {
     display_digit ('0' + i);
     delay_ms(1000);
     }
   }

  
  return 0;

}
