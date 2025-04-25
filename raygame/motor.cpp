#ifndef MOTOR_HPP_INCLUDED
#define MOTOR_HPP_INCLUDED

#include <tinyfsm.hpp>

struct MotorUp : tinyfsm::Event { };
struct MotorDown : tinyfsm::Event { };
struct MotorStop : tinyfsm::Event { };

class Motor
	: public tinyfsm::Fsm<Motor>
{
public:

	void react(tinyfsm::Event const&) { };

	void react(MotorUp   const&);
	void react(MotorDown const&);
	void react(MotorStop const&);

	virtual void entry(void) = 0; 
	void exit(void) { };          

protected:

	static int direction;

public:
	static int getDirection() { return direction; }
};


#endif