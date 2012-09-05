#ifndef MATEHEURISIQUE_H_
# define MATEHEURISIQUE_H_

#include "circuit.h"

class metaheursique
{

  public:
  metaheuristique();
  ~metaheuristique();

  void init_temp();
  void recuit_sim();

  private:
  int temp;
  double coef_temp;
  double coef_eq;
  double tau_zero;
  circuit circuit;

};

#endif /* !MATEHEURISIQUE_H_ */
