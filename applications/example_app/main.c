/* vim: set sw=2 expandtab tw=80: */

#include <stdio.h>
//#include "hello.h"

// Pentru Dots Display Driver
#include <timer.h>
#include "dots_display.h"

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

while (true) {
  for (int i = 0; i < 10; i++) {
  display_digit ('0' + i);
  delay_ms(1000);
  }
}


  



  return 0;
}
