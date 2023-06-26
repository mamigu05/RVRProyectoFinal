#include "NetManager.hpp"
#include <string.h>
#include <iostream>

NetManager::NetManager(const char* s, const char* p, const char* n, bool servidor) : sock(s, p), nick(n)
{
    if(servidor)
    {
        std::cout << "SDJFSJFD";
        server = servidor;
        sock.bind();
    }
    else
    {
        server = servidor;
    }
    
}

void NetManager::net_thread()
{
    NetMessage nm;
    Socket *mSocket = new Socket(sock);
    while(true)
    {
        // Recibir Mensajes de red
        sock.recv(nm, mSocket);

        if(nm.type == nm.LOGIN && server){
            std::cout << "LOGIN " << mSocket << "\n";
            client = mSocket;
            mSocket = nullptr;
        }
        else if(nm.type == nm.LOGOUT && server){
            std::cout << "LOGOUT " << mSocket << "\n";
            delete client;
        }
        else if(nm.type == nm.MESSAGE)
        {

            message = new NetMessage();
            message->color = nm.color;
            message->number = nm.number;
            message->newTurn = nm.newTurn;
        }

    }
}

void NetManager::sendCard(int type, int num, bool turn)
{
    NetMessage nm(nick, " ");
    nm.type = nm.MESSAGE;
    nm.color = type;
    nm.number = num;
    nm.newTurn = turn;
    if(server)
    {
        sock.send(nm, *client);
    }
    else
        sock.send(nm, sock);
}

void NetManager::login()
{

    NetMessage netMsg(nick, " ");
    netMsg.type = NetMessage::LOGIN;

    sock.send(netMsg, sock);
    
}

void NetMessage::to_bin()
{
    alloc_data(MESSAGE_SIZE);

    memset(_data, 0, MESSAGE_SIZE);

    //Serializar los campos type, nick y message en el buffer _data
    char * tmp = _data;
    memcpy(tmp, &type, sizeof(uint8_t)); // Tipo de mensaje
    tmp += sizeof(uint8_t);

    memcpy(tmp, nick.c_str(), 8 * sizeof(char)); // Nick
    tmp += 8 * sizeof(char);

    memcpy(tmp, &number, sizeof(uint8_t)); // Nº Carta
    tmp += sizeof(uint8_t);

    memcpy(tmp, &color, sizeof(uint8_t)); // Color
    tmp += sizeof(uint8_t);

    memcpy(tmp, &newTurn, sizeof(bool)); // Turno
}

int NetMessage::from_bin(char * bobj)
{
    alloc_data(MESSAGE_SIZE);

    memcpy(static_cast<void *>(_data), bobj, MESSAGE_SIZE);

    //Reconstruir la clase usando el buffer _data
    char * tmp = _data;
    memcpy(&type, tmp, sizeof(uint8_t)); // Tipo de mensaje
    tmp += sizeof(uint8_t);

    nick = tmp; // Nick
    tmp += 8 * sizeof(char); 

    memcpy(&number, tmp, sizeof(uint8_t)); // Nº Carta
    tmp += sizeof(uint8_t);

    memcpy(&color, tmp, sizeof(uint8_t)); // Nº Color
    tmp += sizeof(uint8_t);

    memcpy(&newTurn, tmp, sizeof(bool)); // Turno

    return 0;
}

