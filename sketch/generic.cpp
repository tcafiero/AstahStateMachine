#include "Arduino.h"
volatile int tic=1000;

int PIN_LED0=13;
int PIN_LED1=12;
int pippo=0;
int counter=0;
int led1;

void StartupCode()
{
	pinMode(PIN_LED0, OUTPUT);
	pinMode(PIN_LED1, OUTPUT);
}
