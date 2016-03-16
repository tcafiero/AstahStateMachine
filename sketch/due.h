#ifndef due_H
#define due_H
#include "Arduino.h"
#include "generic.h"
#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"

//#include <arduino.h>
//#include <Create.h>
/* class declaration */
class due
{
public:
/* events and states enums */
	enum State_T{
		State1, Start, State2, State0, 
	};
	enum Event_T{
	Reset, Alert, Initiated, Click, 	None
	};
/* member var */

/* functions */
	static due* getInstance(){
		static due instance;
		return &instance;
	}
	void transition(due::Event_T event);
	void doAction();
private:
	due();
	~due();
	State_T due_state;
};
#endif //due_H
