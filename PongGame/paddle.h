#pragma once
class paddle
{
private:
	int radius;
	float x;
	float y;
	int score;
public:
	paddle();
	void settings(float x, float y);
	paddle(float x,float y);
	~paddle();
	void move(float y);
	float get_x();
	float get_y();
	void set_y(float x);
	int get_radius();
	void set_score(int x);
	int get_score();
};

