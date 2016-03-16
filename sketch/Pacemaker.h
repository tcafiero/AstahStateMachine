#ifndef Pacemaker_H
#define Pacemaker_H
#include "Arduino.h"
#include "generic.h"
#include "LEDBlink.h"
#include "due.h"
#include "Pacemaker.h"

//#include <arduino.h>
//#include <Create.h>
/* class declaration */
class Pacemaker
{
public:
/* events and states enums */
	enum State_T{
		State6, Start, 
	};
	enum Event_T{
	Reset, 		Click, None
	};
/* member var */

/* functions */
	static Pacemaker* getInstance(){
		static Pacemaker instance;
		return &instance;
	}
	void transition(Pacemaker::Event_T event);
	void doAction();
private:
	Pacemaker();
	~Pacemaker();
	State_T pacemaker_state;
};
#endif //Pacemaker_H
