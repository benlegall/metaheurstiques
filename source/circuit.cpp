#include "circuit.h"

circuit::circuit(int size_):
  size (size_),
  last_invert_first (-1),
  last_invert_second (-1)
{
  std::srand(unsigned(time(NULL)));

  // set some values:
  for (int i=1; i <= size; ++i)
    map.push_back(i); // 1 => 25


  //std::cout << "list : ";
  //for (int i = 0; i < 25; ++i)
  //  std::cout << map.at(i) << " ";

  //std::cout << std::endl;

  // Every day i'm shuffelin'
  //random_shuffle(map.begin(), map.end());

  //std::cout << "list : ";
  //for (int i = 0; i < 25; ++i)
  //  std::cout << map.at(i) << " ";

  //std::cout << std::endl;
}

void circuit::invertion()
{
  int first = rand() % size;
  int second = rand() % size;
  int temp = 0;

  while ((first == last_invert_first) &&
         (second == last_invert_second))
    first = rand() % size;

  while (first == second)
    second = rand() % size;

  temp = map[first];
  map[first] = map[second];
  map[second] = temp;

  last_invert_first = first;
  last_invert_second = second;

  //std::cout << "invertion : ";
  //for (int i = 0; i < 25; ++i)
  //  std::cout << map.at(i) << " ";

  //std::cout << std::endl;

}

void circuit::undo_invert()
{
    int temp = map[last_invert_first];
    map[last_invert_first] = map[last_invert_second];
    map[last_invert_second] = temp;
}

int circuit::manhattan()
{
  int res = 0;
  int temp = 0;
  int pos = 0;
  int msize = sqrt(size);
  std::vector<int>::iterator it;


  for (int i = 0; i < msize; ++i)
  {
    for (int j = 0; j < msize; ++j)
    {
      temp = map[i * msize + j];
      if (temp % 2 == 0) {
        if ((temp % msize == 1) || (temp % msize == 0)) {
          it = std::find(map.begin(), map.end(), temp - msize);
          pos = std::distance(map.begin(), it);
          res += dist(i, j, pos % msize, pos / msize);

          it = std::find(map.begin(), map.end(), temp + msize);
          pos = std::distance(map.begin(), it);
          res += dist(i, j, pos % msize, pos / msize);

          it = std::find(map.begin(), map.end(),
                         temp + ((temp % msize == 0) ? 1 : -1));
          pos = std::distance(map.begin(), it);
          res += dist(i, j, pos % msize, pos / msize);
        } else if ((temp < msize) || (temp >= size - msize)) {

            it = std::find(map.begin(), map.end(), temp - 1);
            pos = std::distance(map.begin(), it);
            res += dist(i, j, pos % msize, pos / msize);

            it = std::find(map.begin(), map.end(), temp + 1);
            pos = std::distance(map.begin(), it);
            res += dist(i, j, pos % msize, pos / msize);

            it = std::find(map.begin(), map.end(),
                           temp + ((temp < msize) ? msize : -msize));
            pos = std::distance(map.begin(), it);
            res += dist(i, j, pos % msize, pos / msize);
        }
      }
    }
  }
  //std::cout << "manhattan : " << res << std::endl;
  return res;
}

int circuit::dist(int begin_i, int begin_j,
                  int end_i, int end_j)

{
  int res = 0;
  res += std::abs(begin_i - end_i);
  res += std::abs(begin_j - end_j);

  return res * 5;
}

int circuit::get_size()
{
    return size;
}
