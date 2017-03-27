#include <iostream>
#include <ball.h>
#include <paddle.h>
#include <myServer.h>
#include <string>
ball* pointer;
paddle* me1;
paddle* me2;
Server MyServer(1111); //Create server on port 100
int32_t* _arr;
void myMoveFunc() {
	while (true) {
		if (MyServer.getP1_Y() == 0.25) {
			(*me1).move(20);
		}
		if (MyServer.getP1_Y() == -0.25) {
			(*me1).move(-20);
		}
		if (MyServer.getP2_Y() == 0.25) {
			(*me2).move(10);
		}
		if (MyServer.getP2_Y() == -0.25) {
			(*me2).move(-10);
		}
		MyServer.setP1_Y(0);
		MyServer.setP2_Y(0);
	}
}
void test() {
	while(true){
		
		if ((*pointer).get_x() - 10 <= (*me1).get_x()) {
			if ((*pointer).get_y() <= (*me1).get_y() + (*me1).get_radius() + 20 && (*pointer).get_y() >= (*me1).get_y() - 20)
				(*pointer).collision();
			else {

				printf("player2 score\n");
				printf("|| %F |^| %F||\n", (*pointer).get_x(), (*pointer).get_y());
				(*me2).set_score(1);
				(*pointer).set_x(320);
				(*pointer).set_y(192);
				(*pointer).randomStart();
		}
	}
	if ((*pointer).get_x() + 20 >= (*me2).get_x()) {
		if ((*pointer).get_y() <= (*me2).get_y() + (*me2).get_radius() + 20 && (*pointer).get_y() >= (*me2).get_y() - 20)
			(*pointer).collision();
		else {
			printf("player1 score\n");
			printf("|| %F |^| %F||\n", (*pointer).get_x(), (*pointer).get_y());
			(*me1).set_score(1);
			(*pointer).set_x(320);
			(*pointer).set_y(192);
			(*pointer).randomStart();

		}
	}
	(*pointer).play();


	//Send To Clients Positions!
	//[Player1_Y,Player2_Y,Ball_X,Ball_Y,Player1_Score,Player2_Score]
	float arr[] = { (*me1).get_y(),(*me2).get_y(),(*pointer).get_x(),(*pointer).get_y(),(*me1).get_score(),(*me2).get_score() }; //6floats
	int size = sizeof(float) * 6;
	MyServer.sendLoc(arr, size);
	Sleep(10);
	}
}
void network() {
	for (int i = 0; i < 100; i++) //Up to 100 times...
	{
		MyServer.ListenForNewConnection(); //Accept new connection (if someones trying to connect)
		(*me1).set_score(0);
		(*me2).set_score(0);
	}
}

int main() {
	paddle paddle1(94,250);
	paddle paddle2(556, 250);
	me1 = &paddle1;
	me2 = &paddle2;
	ball ball1(300, 192);
	pointer = &ball1;


	std::string input0;
	int input1;
	bool input2;
	std::cout << "Enter 1 to choose PRT or 0 for deafult 1111:" << std::endl;
	std::cin >> input0;
	if (input0 == "1") {
		std::cout << "Enter Port:" << std::endl;
		std::cin >> input1;
		MyServer.SetUP(input1,false);
		std::cout << "Broadcast(0 false or 1 true)... deafult is false:" << std::endl;
		std::cin >> input2;
		MyServer.SetUP(input1, input2);
	}
	else
		MyServer.SetUP(1111, false);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)network, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)myMoveFunc, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)test, NULL, NULL, NULL);
	while (true) {
		
	}
	
	
}

