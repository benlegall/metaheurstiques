#ifndef METAHEURISTIQUE_H_
# define METAHEURISTIQUE_H_

#include "circuit.h"
#include <math.h>

class metaheuristique
{

  public:
  metaheuristique(double tau, double coef_t,
                  double coef_e, int size);
  ~metaheuristique();

  double temp_get();
  double ctemp_get();
  double ceq_get();
  double tauz_get();

  void init_temp();
  int recuit_sim();

  private:
  double temperature;
  double coef_temp;
  double coef_eq;
  double tau_zero;
  circuit *circ;

};

#endif /* !METAHEURISTIQUE_H_ */
