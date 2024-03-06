/*
 * ATmega LED.cpp
 *
 * This simple example shows how to use AVR utils macros for direct port manipulation.
 *
 * ATmega32 microcontroller is used.
 * LED with a series 220R resistor is connected from PORTB0 to GND.
 * Button is connected from PORTA0 to GND.
 *
 * LED will light up when button is pressed.
 */

// default library
#include <avr/io.h>

// include custom library
#include <AVR_utils.h>

// led pin register defines
#define LED_DDRx   DDRB
#define LED_PORTx  PORTB
#define LED_PORTxn PORTB0

// button pin register defines
#define BUTTON_PINx   PINA
#define BUTTON_DDRx   DDRA
#define BUTTON_PORTx  PORTA
#define BUTTON_PORTxn PORTA0

// define HIGH and LOW as true and false for convenience sake
#define HIGH true
#define LOW  false

static void init(void)
{
    outputPin(LED_DDRx, LED_PORTxn);               // set LED pin as output

    inputPin(BUTTON_DDRx, BUTTON_PORTxn);          // set button pin as input
    setPin(BUTTON_PORTx, BUTTON_PORTxn, HIGH);     // enable internal pullup on button pin
}

int main(void)
{
    init();

    while(1)
    {
        if(readPin(BUTTON_PINx, BUTTON_PORTxn) == LOW)     // if button is pressed turn on LED
            setPin(LED_PORTx, LED_PORTxn, HIGH);
        else
            setPin(LED_PORTx, LED_PORTxn, LOW);            // else turn off LED
    }
    return 0;
}