/* vim: set sw=2 expandtab tw=80: */

#include <stdio.h>

// Pentru Dots Text Display 2.0 Driver
#include "dots_text_display_hard.h"
#include "text_screen.h" // se foloseste de un driver deja existent
#include "timer.h"
#include "string.h"

int main(void) {
  

  // Pentru Text Display Driver 2

  text_screen_init (50);
  char *buffer = (char*)text_screen_buffer ();

  strcpy (buffer, "123456789");
  text_screen_write (9);

  if (display_is_present()) {
    printf("Text Display is available \n");

    // Increasing the speed of the array of characters
    for (int i = 500; i < 50000; i = i + 500) {
      display_set_speed(i);

      unsigned int speed;
      display_get_speed(&speed);
      printf("Display speed: %d\n", speed);

      delay_ms(5000);
    }
  }

  
  return 0;

}
