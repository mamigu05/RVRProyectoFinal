
#include "Socket.hpp"
#include "Serializable.hpp"
#include <queue>

class NetMessage : public Serializable
{
public:
    static const size_t MESSAGE_SIZE = sizeof(char) * 8 + 3 * sizeof(uint8_t) + sizeof(bool);

    enum MessageType
    {
        LOGIN = 0,
        MESSAGE = 1,
        LOGOUT = 2,
        BEGIN = 3,
        END = 4
    };

    NetMessage() {};

    NetMessage(const std::string& n, const std::string& m) :nick(n), message(m) {};

    void to_bin();

    int from_bin(char* bobj);

    uint8_t type;

    std::string nick;
    uint8_t number = 0;
    uint8_t color = 0;
    bool newTurn = false; // Para comunicar si es el turno del jugador
    std::string message;

};

class NetManager
{
private:
    // Socket para comunicar con el servidor
    Socket sock;
    Socket* client;
    // Nick del usuario
    std::string nick;
    //std::queue<NetMessage> listMessage;
    NetMessage* message;
    bool server;
public:
    NetManager(const char* s, const char* p, const char* n, bool server);
    void net_thread();
    //std::queue<NetMessage>& getListMessage() {return listMessage;};
    NetMessage* getMessage() {return message;};
    bool isServer() {return server;};
    void sendCard(int type, int num, bool turn);
    void login();

};

