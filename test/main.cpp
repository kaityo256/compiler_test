#include <iostream>
#include <random>

std::mt19937 mt;

std::uniform_real_distribution<> ud(0.0, 1.0);
//std::uniform_int_distribution<> ud(0.0, 1.0);

int main() {
  for (int j = 0; j <1000; j++) {
    for (int i = 0; i < 65536; i++) {
      if (i%2) ud(mt);
    }
  }
  //std::cout << ud(mt) << std::endl;
}
