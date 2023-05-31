#include "UnoOnline.hpp"

int main (int argc, char* argv[])
{
    UnoOnline app;
    
    if(app.init())
        app.run();

    app.release();

    return 0;
}