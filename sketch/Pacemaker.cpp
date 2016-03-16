#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"
#include "SimpleFIFO.h"

SimpleFIFO<enum Pacemaker::Event_T,10> PacemakerMailbox; //store 10 ints
extern SimpleFIFO<enum LEDBlink::Event_T,10> LEDBlinkMailbox; //store 10 ints
extern SimpleFIFO<enum due::Event_T,10> dueMailbox; //store 10 ints
extern SimpleFIFO<enum Pacemaker::Event_T,10> PacemakerMailbox; //store 10 ints


Pacemaker::Pacemaker(){
	pacemaker_state=Start;
}
Pacemaker::~Pacemaker(){}

void Pacemaker::transition(Pacemaker::Event_T event){
  switch(pacemaker_state){
	  case Pacemaker::State6:
    if(event == Pacemaker::None){
      pacemaker_state = Pacemaker::State6;
    }
    break;
	  case Pacemaker::Start:
    if(event == Pacemaker::Reset){
      pacemaker_state = Pacemaker::Start;
      counter=0;
 // Pacemaker::Start entry action;
    }
    if(event == Pacemaker::None){
      pacemaker_state = Pacemaker::State6;
    }
    break;
  default:
    break;
  }
}

void Pacemaker::doAction(){
  switch(pacemaker_state){
  case Pacemaker::State6:
    if(++counter >= 50)
{
counter=0;
}
    break;
  case Pacemaker::Start:
    break;
  default:
    break;
  }
}

