/*
 * Connection.cpp
 *
 *  Created on: 01-10-2011
 *      Author: Jasiek Paw
 */

#include "Connection.hpp"

bool Connection::compare(string word){
    bool flag = true;
    string newWord = buffer;
    for(int i=0; i<(int)word.length();i++){
        if(word[i] != newWord[i]){
            flag = false;
            break;
        }
    }
    return flag;
}

bool Connection::disk(){
    int length;
    char * buffer;
    bool flag = false;
    ifstream fileBuffer;

    system("df > /tmp/buffer");

    fileBuffer.open("/tmp/buffer", ios::binary);
    fileBuffer.seekg (0, ios::end);
    length = fileBuffer.tellg();
    fileBuffer.seekg (0, ios::beg);
    buffer = new char [length];
    fileBuffer.read (buffer,length);
    fileBuffer.close();

    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}

bool Connection::mem(){
    int length;
    char * buffer;
    bool flag = false;
    ifstream fileBuffer;

    system("cat /proc/meminfo > /tmp/buffer");

    fileBuffer.open("/tmp/buffer", ios::binary);
    fileBuffer.seekg (0, ios::end);
    length = fileBuffer.tellg();
    fileBuffer.seekg (0, ios::beg);
    buffer = new char [length];
    fileBuffer.read (buffer,length);
    fileBuffer.close();

    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}

bool Connection::netinfo(){
    int length;
    char * buffer;
    bool flag = false;
    ifstream fileBuffer;

    system("netstat -at > /tmp/buffer");

    fileBuffer.open("/tmp/buffer", ios::binary);
    fileBuffer.seekg (0, ios::end);
    length = fileBuffer.tellg();
    fileBuffer.seekg (0, ios::beg);
    buffer = new char [length];
    fileBuffer.read (buffer,length);
    fileBuffer.close();

    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}

bool Connection::proc(){
    int length;
    char * buffer;
    bool flag = false;
    ifstream fileBuffer;

    system("ps -aux > /tmp/buffer");

    fileBuffer.open("/tmp/buffer", ios::binary);
    fileBuffer.seekg (0, ios::end);
    length = fileBuffer.tellg();
    fileBuffer.seekg (0, ios::beg);
    buffer = new char [length];
    fileBuffer.read (buffer,length);
    fileBuffer.close();

    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}

bool Connection::who(){
    int length;
    char * buffer;
    bool flag = false;
    ifstream fileBuffer;

    system("who > /tmp/buffer");

    fileBuffer.open("/tmp/buffer", ios::binary);
    fileBuffer.seekg (0, ios::end);
    length = fileBuffer.tellg();
    fileBuffer.seekg (0, ios::beg);
    buffer = new char [length];
    fileBuffer.read (buffer,length);
    fileBuffer.close();

    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}

bool Connection::start(int Socket) {
	cout << "Connection::start" << endl;
	udpSocket = Socket;
	while(working){
	bzero((char *) &buffer, sizeof(buffer));
	clientSize = sizeof(clientAddr);

		if((recvfrom(udpSocket, buffer, sizeof(buffer), 0, (struct sockaddr *) &clientAddr, (socklen_t*) &clientSize)) < 0){
			/* ERROR */
			cout << "ERROR\n Reciving problems" << endl;
			working = false;
		}

		if(compare("MEM")){
	    	mem();
		}
		if(compare("PROC")){
			proc();
		}
		if(compare("DF")){
	    	disk();
		}
		if(compare("WHO")){
			who();
		}
		if(compare("NETINFO")){
	    	netinfo();
		}
		if(compare("STOP")){
			stop();
		}
	}
	return working;
}

bool Connection::start(int Socket, int clientPort, char* addr, char* cmd){
	cout << "Connection::start" << endl;
	udpSocket = Socket;
	if(!(sent = gethostbyname(addr))){
	        /* ERROR */
	        cout << "ERROR\n Server addres" << endl;
	 }

	clientAddr.sin_family = PF_INET;
	clientAddr.sin_port = htons(clientPort);
	bcopy(sent->h_addr, (char *) &clientAddr.sin_addr, sent->h_length);

	bzero((char *) &buffer, sizeof(buffer));
	clientSize = sizeof(clientAddr);

	sendto(udpSocket, cmd, strlen(cmd), 0, (struct sockaddr *) &clientAddr,
	           sizeof (clientAddr));

	recvfrom(udpSocket, buffer, sizeof(buffer), 0, (struct sockaddr *) &clientAddr, &clientSize);

	cout << buffer;

	return working;
}

bool Connection::stop(){
	sendto(udpSocket, "Server::stop()\n", sizeof("Server::stop()\n"), 0, (struct sockaddr *) &clientAddr,
	       sizeof (clientAddr));
	working = false;
	return working;
}

Connection::Connection(){
	working = true;
}

Connection::~Connection() {
	working = false;
	close(udpSocket);
}

