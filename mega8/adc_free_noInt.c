#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
int main(void)
{
   DDRB=0xff; // Set Port D as Output
   DDRD=0xFF;
   PORTD = 0x00;
   DDRC = 0x00;
   PORTC = 0x01;
   //Nastavenie ADC
   ADCSRA = (1<<ADPS1) | (1<<ADPS0); //Set divisor to 011 which is 8
   ADMUX |= 0x05; //nastavit adc na port pC5
   ADMUX |= (1 << REFS0); //Ako maximalne napatie puzit VCC namiesto AREF
   ADMUX |= (1 << ADLAR); //Pouzit 8 bitov namiesto 10
   ADCSRA |= (1 << ADFR);  // ADC Free-Running Mode
   ADCSRA |= (1 << ADEN);  // Enable ADC
   ADCSRA |= (1 << ADSC);  // Start A2D Conversions
   while (1)
   {
      PORTB = ADCH;
      if(!(PINC & 0x01 == 0x01)){
        PORTD=(int) (ADCH * (rand() / ((double)RAND_MAX + 1.0)));
        _delay_ms(50);
      }
   }
}
