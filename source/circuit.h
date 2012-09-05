#ifndef CIRCUIT_H_
#define CIRCUIT_H_

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <algorithm>

class circuit
{
public:
  circuit(int size_);
  ~circuit();

  void invertion();
  int manhattan();
  int dist(int begin_i, int begin_j,
           int end_i, int end_j);

private:
  std::vector<int> map;
  int size;
  int last_invert_first;
  int last_invet_second;
};

#endif //!CIRCUIT_H_
