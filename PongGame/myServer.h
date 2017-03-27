#pragma once

#define _MY_SERVER_H
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include <iostream>


enum Packet
{
	P_ChatMessage,
	P_Test,
	P_moveUP1,
	P_moveDOWN1,
	P_moveUP2,
	P_moveDOWN2,
	P_move
};

class Server
{
public:
	Server(int PORT=1111, bool BroadcastPublically = false);
	bool ListenForNewConnection();

	float getP1_Y();
	float getP2_Y();

	void setP1_Y(float x);
	void setP2_Y(float x);
	bool SetUP(int PORT, bool BroadcastPublically);

	void sendLoc(float *x,int size);


private:
	float P1_y = 0;
	float P2_y = 0;

	bool sendall(int ID, char * data, int totalbytes);
	bool recvall(int ID, char * data, int totalbytes);

	bool Sendint32_t(int ID, int32_t _int32_t);
	bool Getint32_t(int ID, int32_t & _int32_t);

	bool SendPacketType(int ID, Packet _packettype);
	bool GetPacketType(int ID, Packet & _packettype);

	bool SendString(int ID, std::string & _string);
	bool GetString(int ID, std::string & _string);

	bool ProcessPacket(int ID, Packet _packettype);

	static void ClientHandlerThread(int ID);

private:
	SOCKET Connections[100];
	int TotalConnections = 0;

	SOCKADDR_IN addr; //Address that we will bind our listening socket to
	int addrlen = sizeof(addr);
	SOCKET sListen;
};

static Server * serverptr; //Serverptr is necessary so the static ClientHandler method can access the server instance/functions.

