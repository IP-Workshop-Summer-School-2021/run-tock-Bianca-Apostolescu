/* vim: set sw=2 expandtab tw=80: */

#include <stdio.h>

// Pentru Hello Driver
//#include "hello.h"

// Pentru Dots Display Driver
// #include <timer.h>
// #include "dots_display.h"

// Pentru Dots Text Display Driver
// #include "dots_text_display.h"

// Pentru Dots Text Display 2.0 Driver
#include "dots_text_display_hard.h"
#include "text_screen.h" // se foloseste de un driver deja existent
#include "timer.h"
#include "string.h"

int main(void) {
  

  // // Pentru Hello Driver
  
  //   if (hello_is_present()) {
  //   printf ("The Hello driver is present\n");

  //   // print
  //   hello_print ();

  //   // up
  //   hello_up ();
  //   hello_print ();

  //   // down
  //   hello_down ();
  //   hello_print ();

  //   // set
  //   hello_set (0);
  //   hello_print ();

  //   // error
  //   hello_down ();
  //   hello_print ();

  //   // get
  //   hello_set (120);
  //   hello_print ();
  //   unsigned int n;
  //   if (hello_get(&n)) {
  //     printf ("n is %d\n", n);
  //   }
  //   else
  //   {
  //     printf ("Failed to read n from hello driver\n");
  //   }
  // }
  // else
  // {
  //   printf ("The Hello driver is not present\n");
  // }
 
  
  // Pentru Dots Display Driver

  // while (true) {
  //   for (int i = 0; i < 10; i++) {
  //   display_digit ('0' + i);
  //   delay_ms(1000);
  //   }
  // }


  // // Pentru Text Display Driver
  // while (true) {
  //   display_text ("2990302410023");
  // }

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
