#include "metaheuristique.h"

metaheuristique::metaheuristique(double tau, double coef_t,
                                 double coef_e, int size) :
  tau_zero (tau),
  coef_temp (coef_t),
  coef_eq (coef_e)
{
  circuit = new circuit(size);
}

void metaheuristique::init_temp()
{
  int last = circuit->manhattan();
  int temp = 0;
  int delta = 0;
  for (int i  = 0; i < 100; ++i)
  {
    circuit->invertion();
    temp = circuit->manhattan();
    delta += std::abs(last - temp);
    last = temp;
  }

  delta = delta / 100;

  temperature = - delta / ln(tau_zero);
}

voidr metaheuristique::recuit_sim()
{}
