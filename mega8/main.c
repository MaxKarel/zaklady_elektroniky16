#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
int main(void)
{
   unsigned int adc_value; // Variable to hold ADC result
   DDRB=0xff; // Set Port D as Output
   DDRD=0xFF;
   PORTB = 0x00;
   PORTD = 0b01010101;
   DDRC = 0b00000001;
   ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);
   // ADEN: Set to turn on ADC , by default it is turned off
   //ADPS2: ADPS2 and ADPS0 set to make division factor 32
   ADMUX=0x05; // ADC input channel set to PC5
   while (1)
   {
      ADCSRA |= (1<<ADSC); // Start conversion
         while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
      adc_value = ADCW / 4; //Store ADC value
      PORTB = adc_value;
      if(PINC & 0x01 == 0x01){
         unsigned int rnd_max = adc_value / 4;
	 PORTB = 0x00;
	 _delay_ms(500);
	 PORTB = (int)((double)rand() / ((double)RAND_MAX + 1) * 
rnd_max);
	 _delay_ms(1000);
      }
   }
}
