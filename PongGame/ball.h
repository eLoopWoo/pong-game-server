#pragma once
#include <stdlib.h>
class ball
{
private:
	float x=300;
	float y=300;
	float velocity_x = 1.5;
	float velocity_y = 2;
public:
	void set_velocity_x(float z);
	void set_velocity_y(float z);
	void collision();
	float get_velocity_x();
	float get_velocity_y();
	ball();
	void settings(float x, float y);
	ball(float x,float y);
	void move(float z, float w);
	void set_x(float x);
	void set_y(float y);
	float get_x();
	float get_y();
	void control();
	void play();
	void randomStart();
};

