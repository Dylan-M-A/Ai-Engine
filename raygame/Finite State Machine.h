#pragma once
#ifndef ELEVATOR_HPP_INCLUDED
#define ELEVATOR_HPP_INCLUDED

#include <tinyfsm.hpp>

struct FloorEvent : tinyfsm::Event
{
	int floor;
};

struct Call : FloorEvent { };
struct FloorSensor : FloorEvent { };
struct Alarm : tinyfsm::Event { };

class Elevator
	: public tinyfsm::Fsm<Elevator>
{
public:
	void react(tinyfsm::Event const&) { };

	virtual void react(Call        const&);
	virtual void react(FloorSensor const&);
	void         react(Alarm       const&);

	virtual void entry(void) { };
	void         exit(void) { }; 

protected:

	static constexpr int initial_floor = 0;
	static int current_floor;
	static int dest_floor;
};

#endif