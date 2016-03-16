#ifndef LEDBlink_H
#define LEDBlink_H
#include "Arduino.h"
#include "generic.h"
#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"

//#include <arduino.h>
//#include <Create.h>
/* class declaration */
class LEDBlink
{
public:
/* events and states enums */
	enum State_T{
		OFF, ON, Start, 
	};
	enum Event_T{
	Click, Reset, 	None
	};
/* member var */

/* functions */
	static LEDBlink* getInstance(){
		static LEDBlink instance;
		return &instance;
	}
	void transition(LEDBlink::Event_T event);
	void doAction();
private:
	LEDBlink();
	~LEDBlink();
	State_T lEDBlink_state;
};
#endif //LEDBlink_H
