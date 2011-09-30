/*
 * main.cpp
 *
 *  Created on: 30-09-2011
 *      Author: Jasiek Paw
 */

#include "functions.hpp"

int main(int argc, char** argv) {

    char buffer[MAXDATASIZE];
    int udpSocket, clientSize;
    struct sockaddr_in serverAddr, clientAddr;

    //Tworzenie socketu UDP
    if((udpSocket = socket(PF_INET, SOCK_DGRAM, 0)) < 1){
        /* ERROR */
        cout << "ERROR\n Bad socket creation" << endl;
        exit(1);
    }

    //Binding
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVPORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(udpSocket, (const sockaddr*) &serverAddr, sizeof(serverAddr)) < 0){
        /* ERROR */
        cout << "ERROR\n Bad binding" << endl;
        exit(1);
    }

    while(1){
        bzero((char *) &buffer, sizeof(buffer));
        clientSize = sizeof(clientAddr);

        //Odbieranie datagramu UDP
        if((recvfrom(udpSocket, buffer, sizeof(buffer), 0, (struct sockaddr *) &clientAddr, (socklen_t*) &clientSize)) < 0){
            /* ERROR */
            cout << "ERROR\n Reciving problems" << endl;
            exit(1);
        }

        /*
         *Wywo³ywanie funkcji w zale¿noœci od odebranej wiadomoœci
         */

        if(compare(buffer, "MEM")){
            /* TEST */
            //cout << "mem" << endl;
            /* END */
            mem(udpSocket, clientAddr);
        }
        if(compare(buffer, "PROC")){
            /* TEST */
            //cout << "proc" << endl;
            /* END */
            proc(udpSocket, clientAddr);
        }
        if(compare(buffer, "DF")){
            /* TEST */
            //cout << "df" << endl;
            /* END */
            disk(udpSocket, clientAddr);
        }
        if(compare(buffer, "WHO")){
            /* TEST */
            //cout << "who" << endl;
            /* END */
            who(udpSocket, clientAddr);
        }
        if(compare(buffer, "NETINFO")){
            /* TEST */
            //cout << "netinfo" << endl;
            /* END */
            netinfo(udpSocket, clientAddr);
        }
    }

    close(udpSocket);
    return 0;
}
