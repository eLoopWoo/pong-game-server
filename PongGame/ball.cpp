#include "ball.h"
void ball::settings(float z, float w)
{
	x = z;
	y = w;
}
ball::ball(float z,float w)
{
	x = z;
	y = w;
}
void ball::move(float z, float w) {
	x = z;
	y = w;
}
void ball::set_x(float z) {
	x = z;
}
void ball::set_y(float w) {
	y = w;
}
float ball::get_x() {
	return x;
}
float ball::get_y() {
	return y;
}
float ball::get_velocity_x(){
	return velocity_x;
}
float ball::get_velocity_y(){
	return  velocity_y;
}
void ball::set_velocity_x(float z) {
	velocity_x = z;
}
void ball::set_velocity_y(float z) {
	velocity_y = z;
}
void ball::control() {
	if (get_x() > 576 - 2*10) {
		set_velocity_x(-1 * get_velocity_x());
	}
	
	if (get_x() < 64 + 2 * 10) {
		set_velocity_x(-1 * get_velocity_x());
	}
	if (get_y() > 432 - 2 * 10) {
		set_velocity_y(-1* get_velocity_y());
	}
	if (get_y() < 48 + 2 * 10) {
		set_velocity_y(-1 * get_velocity_y());
	}
}
void ball::play() {
	control();
	set_x(get_x() + get_velocity_x());
	set_y(get_y() + get_velocity_y());
}
void ball::collision() {
	set_velocity_x(-1 * get_velocity_x());
}
void ball::randomStart() {

	this->velocity_x = (rand() % 10) / 10 + 2;
	this->velocity_y = (rand() % 10) / 10 + 2;
	int direction = 0;
	direction = rand() % 2;
	if (direction)
		this->velocity_x *= -1;
	direction = rand() % 2;
	if (direction)
		this->velocity_y *= -1;
}

