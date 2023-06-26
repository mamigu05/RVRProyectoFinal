#include <thread>
#include "UnoOnline.hpp"
#include "NetManager.hpp"

int main (int argc, char* argv[])
{
    UnoOnline app;

    std::cout << "HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

    NetManager netMng("localhost", "1234", "aa", true);

    std::thread net_thread([&netMng](){ netMng.net_thread(); });
    
    if(app.init(&netMng))
        app.run();

    app.release();

    return 0;
}