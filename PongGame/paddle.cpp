
#include "paddle.h"
#include "iostream"
#include <paddle.h>
void paddle::settings(float x = 94, float y = 250) {
	this->x = x;
	this->y = y;
	radius = 50;
	this->score = 0;

}
paddle::paddle(float x=94,float y=250)
{
	this->x = x;
	this->y = y;
	radius = 50;
	this->score = 0;
}
paddle::~paddle()
{
}
void paddle::move(float y) {
	this->y = y + get_y();
	if (get_y() > 432 - 50) {
		set_y(432 - 50);
	}
	if (get_y() < 48 + 15) {
		set_y(48 + 15);
	}
}
void paddle::set_y(float x) {
	this->y = x;

}
float paddle::get_x() {
	return (x);
}
float paddle::get_y() {
	return (y);
}
int paddle::get_radius() {
	return(this->radius);
}
void paddle::set_score(int x) {
	this->score = get_score() + x;
}
int paddle::get_score() {
	return(this->score);
}


