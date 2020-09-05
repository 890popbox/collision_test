/*
Let's use this from an old data structure project
*/

#ifndef GAME_CLOCK
#define GAME_CLOCK

#include <windows.h>

/*
Class: Timer
Author: Glen
Description: Timer given by professior to use in sorting class.
*/

class Timer
{
private:
	LARGE_INTEGER start;
	LARGE_INTEGER current;
	LARGE_INTEGER stop;
	LARGE_INTEGER freq;

	double PCFreq;
	__int64 CounterStart;

public:
	Timer();
	void startTimer();
	void stopTimer();

	double getCurrentSeconds();
	double getMilli();
	double getSeconds();
	double getMicro();

};

#endif

//Cantes932(Moon)
//Hmm..