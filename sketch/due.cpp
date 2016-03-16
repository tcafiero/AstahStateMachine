#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"
#include "SimpleFIFO.h"

SimpleFIFO<enum due::Event_T,10> dueMailbox; //store 10 ints
extern SimpleFIFO<enum LEDBlink::Event_T,10> LEDBlinkMailbox; //store 10 ints
extern SimpleFIFO<enum due::Event_T,10> dueMailbox; //store 10 ints
extern SimpleFIFO<enum Pacemaker::Event_T,10> PacemakerMailbox; //store 10 ints


due::due(){
	due_state=Start;
}
due::~due(){}

void due::transition(due::Event_T event){
  switch(due_state){
	  case due::State1:
    if(event == due::Alert){
      due_state = due::State2;
      Serial.println("Alert");
 // due::State2 entry action;
    }
    if(event == due::Click){
      due_state = due::State1;
      if (pippo == 10)
{
Serial.println("From due");
} // due::State1 entry action;
    }
    break;
	  case due::Start:
    if(event == due::Reset){
      due_state = due::Start;
    }
    if(event == due::Initiated){
      due_state = due::State0;
      Serial.println("Hello From due"); // due::State0 entry action;
    }
    break;
	  case due::State2:
    break;
	  case due::State0:
    if(event == due::None){
      due_state = due::State1;
      if (pippo == 10)
{
Serial.println("From due");
} // due::State1 entry action;
    }
    break;
  default:
    break;
  }
}

void due::doAction(){
  switch(due_state){
  case due::State1:
    break;
  case due::Start:
    break;
  case due::State2:
    break;
  case due::State0:
    break;
  default:
    break;
  }
}

