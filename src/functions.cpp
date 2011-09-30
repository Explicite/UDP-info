/*
 * functions.cpp
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

bool mem(int udpSocket, struct sockaddr_in clientAddr){
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


    /* TEST */
    //cout << "mem" << endl;
    /* END */
    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}
bool proc(int udpSocket, struct sockaddr_in clientAddr){
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


    /* TEST */
    //cout << "mem" << endl;
    /* END */
    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}
bool disk(int udpSocket, struct sockaddr_in clientAddr){
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


    /* TEST */
    //cout << "mem" << endl;
    /* END */
    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}
bool who(int udpSocket, struct sockaddr_in clientAddr){
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


    /* TEST */
    //cout << "mem" << endl;
    /* END */
    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}
bool netinfo(int udpSocket, struct sockaddr_in clientAddr){
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

    /* TEST */
    //cout << "mem" << endl;
    /* END */
    sendto(udpSocket, buffer, length, 0, (struct sockaddr *) &clientAddr,
           sizeof (clientAddr));

    delete[] buffer;
    return flag;
}
bool compare(const char *buffer, string word){
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
