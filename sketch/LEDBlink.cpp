#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"
#include "SimpleFIFO.h"

SimpleFIFO<enum LEDBlink::Event_T,10> LEDBlinkMailbox; //store 10 ints
extern SimpleFIFO<enum LEDBlink::Event_T,10> LEDBlinkMailbox; //store 10 ints
extern SimpleFIFO<enum due::Event_T,10> dueMailbox; //store 10 ints
extern SimpleFIFO<enum Pacemaker::Event_T,10> PacemakerMailbox; //store 10 ints


LEDBlink::LEDBlink(){
	lEDBlink_state=Start;
}
LEDBlink::~LEDBlink(){}

void LEDBlink::transition(LEDBlink::Event_T event){
  switch(lEDBlink_state){
	  case LEDBlink::OFF:
    if(event == LEDBlink::Click){
      led1 = led1 == LOW ? HIGH : LOW;
digitalWrite(PIN_LED1,led1); // OFF exit action;
      lEDBlink_state = LEDBlink::ON;
      digitalWrite(PIN_LED0, HIGH); // LEDBlink::ON entry action;
    }
    break;
	  case LEDBlink::ON:
    if(pippo<100 && event == LEDBlink::Click){
      pippo++; // Click [pippo<100] / pippo++; transition action;
      lEDBlink_state = LEDBlink::OFF;
      digitalWrite(PIN_LED0, LOW);
if ((pippo%21) == 0 && pippo > 0)
{
Serial.println("From LEDBlink!");
}; // LEDBlink::OFF entry action;
    }
    break;
	  case LEDBlink::Start:
    if(event == LEDBlink::None){
      lEDBlink_state = LEDBlink::OFF;
      digitalWrite(PIN_LED0, LOW);
if ((pippo%21) == 0 && pippo > 0)
{
Serial.println("From LEDBlink!");
}; // LEDBlink::OFF entry action;
    }
    if(event == LEDBlink::Reset){
      lEDBlink_state = LEDBlink::Start;
      led1=ON;
digitalWrite(PIN_LED1, led1);
Serial.begin(9600);
  while (!Serial) {
    ;
  }
tic=20;
Serial.println("Hello From LEDBlink");
dueMailbox.send(due::Initiated);

 // LEDBlink::Start entry action;
    }
    break;
  default:
    break;
  }
}

void LEDBlink::doAction(){
  switch(lEDBlink_state){
  case LEDBlink::OFF:
    if(pippo == 15) dueMailbox.send(due::Alert);
    break;
  case LEDBlink::ON:
    break;
  case LEDBlink::Start:
    break;
  default:
    break;
  }
}

