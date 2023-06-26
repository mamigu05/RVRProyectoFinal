#include <thread>
#include "UnoOnline.hpp"
#include "NetManager.hpp"

int main (int argc, char* argv[])
{
    UnoOnline app;

    NetManager netMng(argv[1], argv[2], argv[3], false);

    std::thread net_thread([&netMng](){ netMng.net_thread(); });
    
    if(app.init(&netMng))
        app.run();

    app.release();

    return 0;
}