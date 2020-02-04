#include <iostream>
#include <random>

std::mt19937 mt;
const int N = 65536;

int spin[N] = {};
//std::uniform_real_distribution<> ud(0.0, 1.0);
std::uniform_int_distribution<> ud(0.0, 1.0);

void run() {
  for (int i = 0; i < N; i++) {
    if (spin[i] != 0) continue;
    ud(mt);
  }
}

int main() {
  for (int j = 0; j <1000; j++) {
    run();
  }
  //std::cout << ud(mt) << std::endl;
}
