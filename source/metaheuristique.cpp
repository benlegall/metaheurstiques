#include "metaheuristique.h"

metaheuristique::metaheuristique(double tau, double coef_t,
                                 double coef_e, int size) :
  coef_temp (coef_t),
  coef_eq (coef_e),
  tau_zero (tau)
{
  circ = new circuit(size);
}

void metaheuristique::init_temp()
{
  int last = circ->manhattan();
  int temp = 0;
  double delta = 0;

  for (int i  = 0; i < 100; ++i)
  {
    circ->invertion();
    temp = circ->manhattan();
    delta += std::abs(last - temp);

    std::cout << "temp = " << temp
              << "  delta = " << delta
              << std::endl;

    last = temp;
  }

  delta = delta / 100;

  std::cout << "moyenne des delta : " << delta
            << std::endl;

  temperature = - delta / log(tau_zero);
}

int metaheuristique::recuit_sim()
{
    int man_init = circ->manhattan();
    int man_post = 0;
    int nb_perturb_total = 0;
    int nb_perturb_accept = 0;
    int nb_palier = 0;
    int rand = 0;

    std::srand(unsigned(time(NULL)));

    while (nb_palier < 3)
    {
        while ((nb_perturb_total < 100 * circ->get_size()) &&
               (nb_perturb_accept < 12 * circ->get_size()))
            // tant que non équilibre thermodynamique
        {
            circ->invertion();
            man_post = circ->manhattan();
            nb_perturb_total++;
            //std::cout << "perturbation" << std::endl;

            if (man_post < man_init)
            {
                // perturbation meilleur
                // donc accpetée

                nb_perturb_accept++;
                man_init = man_post;
                //std::cout << "\t perturbation acceptée direct"
                //          << std::endl;

            }
            else
            {
                rand = std::rand() % 100;
                if (rand <=
                    (exp(-(man_post - man_init) / temperature) * 100))
                {
                    // perturbation moins bonne
                    // mais accpeté selon la proba
                    // exp((Delta_E) / temperature)
                    nb_perturb_accept++;

                    man_init = man_post;

                    //std::cout << "\t perturbation acceptée EXP"
                    //          << std::endl;
                }
                else
                {
                    //perturbation non acceptée
                    //std::cout << "\t perturbation NON acceptée"
                    //          << std::endl;
                    circ->undo_invert();
                }
            }
        }
        // équilibre thermodynamique
        // maj de la temperture
        std::cout << "Equil Thermo temp : " << temperature;


        temperature = 0.9 * temperature;

        std::cout << "nouvelle temp : " << temperature << std::endl;

        if (nb_perturb_accept == 0)
        {
            nb_palier++;
            std::cout << "palier num : " << nb_palier << std::endl;

        } else {
            nb_palier = 0;
            std::cout << "palier remis a 0" << std::endl;

        }

        nb_perturb_total = 0;
        nb_perturb_accept = 0;
    }
    std::cout << "FIN" << std::endl;

    return man_init;
}

double metaheuristique::temp_get()
{
  return temperature;
}

double metaheuristique::ctemp_get()
{
  return coef_temp;
}

double metaheuristique::ceq_get()
{
  return coef_eq;
}

double metaheuristique::tauz_get()
{
  return tau_zero;
}
