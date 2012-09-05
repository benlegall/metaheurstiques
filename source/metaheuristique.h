#ifndef METAHEURISIQUE_H_
# define METAHEURISIQUE_H_

#include "circuit.h"
#include <math.h>

class metaheursique
{

  public:
  metaheuristique(double tau, double coef_t,
                  double coef_e, int size);
  ~metaheuristique();

  void init_temp();
  void recuit_sim();

  private:
  double temperature;
  double coef_temp;
  double coef_eq;
  double tau_zero;
  circuit *circuit;

};

#endif /* !METAHEURISIQUE_H_ */
