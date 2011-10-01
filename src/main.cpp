/*
 * main.cpp
 *
 *  Created on: 01-10-2011
 *      Author: Jasiek Paw
 */

#include "Server.hpp"

int main(int argc, char** argv) {

	Server newServer;
	newServer.start();
	cout << "Connection::stop()" << endl;

	return 0;
}
