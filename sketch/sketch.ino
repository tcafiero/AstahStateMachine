#include "Arduino.h"
#include "generic.h"

#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"
#include "SimpleFIFO.h"

extern SimpleFIFO<enum LEDBlink::Event_T,10> LEDBlinkMailbox; //store 10 ints
extern SimpleFIFO<enum due::Event_T,10> dueMailbox; //store 10 ints
extern SimpleFIFO<enum Pacemaker::Event_T,10> PacemakerMailbox; //store 10 ints


LEDBlink *lEDBlink;
due *due;
Pacemaker *pacemaker;

void setup()
{
	StartupCode();
	lEDBlink = LEDBlink::getInstance();
	due = due::getInstance();
	pacemaker = Pacemaker::getInstance();
  lEDBlink->transition(LEDBlink::Reset);
  due->transition(due::Reset);
  pacemaker->transition(Pacemaker::Reset);

}

void loop()
{
	if(LEDBlinkMailbox.count()) lEDBlink->transition(LEDBlinkMailbox.receive());
  	else lEDBlink->transition(LEDBlink::None);
	if(!counter) lEDBlink->transition(LEDBlink::Click);
	if(dueMailbox.count()) due->transition(dueMailbox.receive());
  	else due->transition(due::None);
	if(!counter) due->transition(due::Click);
	if(PacemakerMailbox.count()) pacemaker->transition(PacemakerMailbox.receive());
  	else pacemaker->transition(Pacemaker::None);
	if(!counter) pacemaker->transition(Pacemaker::Click);
  lEDBlink->doAction();
  due->doAction();
  pacemaker->doAction();
  delay(tic);
}
