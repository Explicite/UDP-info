/*
 * main.cpp
 *
 *  Created on: 01-10-2011
 *      Author: Jasiek Paw
 */

#include "Server.hpp"

int main(int argc, char** argv) {

	Server newServer(1234);
	newServer.start();

	return 0;
}
