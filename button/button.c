#include "pico/stdlib.h"

int count=0;

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    stdio_init_all();
    const uint LED_PIN1 = 4; //red
    const uint LED_PIN2 = 5;  //green 
    const uint LED_PIN3 = 3;  //blue
    const uint BUTTON_PIN= 2;
    gpio_init(LED_PIN1);
    gpio_init(LED_PIN2);
    gpio_init(LED_PIN3);
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN1, GPIO_OUT);
    gpio_set_dir(LED_PIN2, GPIO_OUT);
    gpio_set_dir(LED_PIN3, GPIO_OUT);
    gpio_put(LED_PIN1, 1);
    gpio_put(LED_PIN2, 1);
    gpio_put(LED_PIN3, 1);
      while (true) {
        if(gpio_get(2)==0)
        {
         count=count+1;

         if(count==1)
         {
            printf("red and green on\n");
            gpio_put(LED_PIN1, 0);  
            gpio_put(LED_PIN2, 0);
            gpio_put(LED_PIN3, 1);
            
         }
        else if(count==2)
        {
            printf("green and blue on\n");
            gpio_put(LED_PIN1, 1);
            gpio_put(LED_PIN2, 0);
            gpio_put(LED_PIN3, 0);
           
        }
        else if(count==3)
        {
           printf("red");
           gpio_put(LED_PIN1, 0);
           gpio_put(LED_PIN2, 1);
           gpio_put(LED_PIN3, 1);
         
         }
         else if(count==4)
           {
             printf("red , green , blue off\n");
             gpio_put(LED_PIN1, 1);
             gpio_put(LED_PIN2, 1);
             gpio_put(LED_PIN3, 1);
             
            }
              else if(count==5)
               {
                 printf("red , green , blue on\n");
                 gpio_put(LED_PIN1, 0);
                 gpio_put(LED_PIN2, 0);
                 gpio_put(LED_PIN3, 0);
                 
               }
               else
               {
                  count=0;
              }
        }
      sleep_ms(500);
           }
   #endif
}