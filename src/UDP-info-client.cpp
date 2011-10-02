/*
 * UDP-info-client.cpp
 *
 *  Created on: 02-10-2011
 *      Author: Jasiek Paw
 */

#include "Server.hpp"

int main(int argc, char** argv) {

	Server newServer(4321);
	newServer.start(1234, argv[1], argv[2]);

	return 0;
}



