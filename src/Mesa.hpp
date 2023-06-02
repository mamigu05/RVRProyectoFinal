#include <vector>

class Carta;

class Mesa
{
private:
    std::vector<Carta*> cartasEnMesa;
    Carta* ultimaCarta;
public:
    Mesa();
    void update();
    void render();
    void colocarCarta(Carta* carta);
    Carta* obtenerUltimaCarta();
};