
#define F_CPU	4000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>

/*Global Variables Declarations*/


int main(void)
{

	DDRB = 0xFF;			// Configure PortA as input


	while(1)
  {
      PORTB ^= 1<< 0x04;
      _delay_ms(500);
  }
}
