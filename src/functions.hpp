/*
 * functions.hpp
 *
 *  Created on: 30-09-2011
 *      Author: Jasiek Paw
 */

#include <cstdlib>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#define SERVPORT 1234           //Port serwera
#define CLIPORT 4321            //Port klienta
#define MAXDATASIZE 1024        //Maksymalny rozmiar wiadomoœci

bool mem(int udpSocket, struct sockaddr_in clientAddr);
bool proc(int udpSocket, struct sockaddr_in clientAddr);
bool disk(int udpSocket, struct sockaddr_in clientAddr);
bool who(int udpSocket, struct sockaddr_in clientAddr);
bool netinfo(int udpSocket, struct sockaddr_in clientAddr);
bool compare(const char *buffer, string word);

#endif /* FUNCTIONS_HPP_ */
