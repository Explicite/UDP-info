/*
 * Server.hpp
 *
 *  Created on: 01-10-2011
 *      Author: Jasiek Paw
 */

#include <cstdlib>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <netdb.h>

#ifndef SERVER_HPP_
#define SERVER_HPP_
#include "Connection.hpp"
using namespace std;


class Server {
	bool working;
    int udpSocket, serverPort;
    struct sockaddr_in serverAddr;

public:
    bool stop();
    bool start(int port, char* addr, char* cmd);
    bool start();
	Server(int serverPort);
	Server();
	virtual ~Server();
};

#endif /* SERVER_HPP_ */
