#include <random>
int main() {
  std::mt19937 mt;
  std::uniform_real_distribution<> ud(0.0, 1.0);
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      if (i%2) ud(mt);
    }
  }
}
