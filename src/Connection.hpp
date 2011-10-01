/*
 * Connection.hpp
 *
 *  Created on: 01-10-2011
 *      Author: Jasiek Paw
 */

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_
#include "Server.hpp"

using namespace std;

class Connection{
	bool working;
	char buffer[1280];
	int udpSocket, clientSize;
	struct sockaddr_in clientAddr;

public:
	bool start(int Socket);
	bool stop();
	bool mem();
	bool proc();
	bool disk();
	bool who();
	bool netinfo();
	bool compare(string word);
	Connection();
	virtual ~Connection();
};

#endif /* CONNECTION_HPP_ */
