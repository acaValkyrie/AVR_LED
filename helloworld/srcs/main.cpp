#include "main.h"

int main(){
  DDRB = 0b00000001;
  int delay_t_ms = 50 /*ms*/;
  while(1){
    PORTB = 0b00000001;
    _delay_ms(delay_t_ms);
    PORTB = 0b00000000;
    _delay_ms(delay_t_ms);
  }
}
