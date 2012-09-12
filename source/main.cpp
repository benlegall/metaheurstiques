#include "metaheuristique.h"
#include "circuit.h"

int main(/*int argc, char **argv*/)
{
    //metaheuristique *m = new metaheuristique(0.9, 0.9, 0, 25);

    circuit *c = new circuit(25);
    std::cout << "manhattan sans shuffle : "
              << c->manhattan() << std::endl;


    //m->init_temp();
    //std::cout << "temperature init : " << m->temp_get() << std::endl;
    //std::cout << "resultat recuit : " << m->recuit_sim() << std::endl;

}

