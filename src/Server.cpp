/*
 * Server.cpp
 *
 *  Created on: 01-10-2011
 *      Author: Jasiek Paw
 */

#include "Server.hpp"
#include "Connection.hpp"

bool Server::start(){
	working = false;
    Connection NewConnection;
    if(NewConnection.start(udpSocket)){
    	cout << "Server::start()" << endl;
    	working = true;
    }
    return working;
}

bool Server::stop(){
	working = false;
	cout << "Server::stop()" << endl;
	return working;
}

Server::Server() {
    if(!((udpSocket = socket(PF_INET, SOCK_DGRAM, 0)) < 1)){
    	working = true;
    	serverAddr.sin_family = PF_INET;
    	serverAddr.sin_port = htons(1234);
    	serverAddr.sin_addr.s_addr = INADDR_ANY;
    }

    if((bind(udpSocket, (const sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) || !working){
    	//ERROR
    	//TODO

    	cout << "ERROR bind" << endl;
    }else working = true;
}

Server::~Server() {
	close(udpSocket);
}

