#ifndef CIRCUIT_H_
#define CIRCUIT_H_

#include <string>
#include <iostream>

class circuit
{
public:
  circuit();
  ~circuit();

  void invertion();
  int manhattan();

private:
    int **map;
};

#endif //!CIRCUIT_H_
