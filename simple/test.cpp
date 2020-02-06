#include <iostream>
#include <random>

struct myrand {
  uint32_t operator()() {
    return 0;
  }
  static constexpr uint32_t max(){
    return std::mt19937::max();
  }
  static constexpr uint32_t min(){
    return 0;
  }
};


double run(void) {
  myrand mt;
  double r = 0.0;
  std::uniform_real_distribution<> ud(-1.0, 1.0);
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      if (i%2) r += ud(mt);
    }
  }
  return r;
}

int main(){
  std::cout << run() << std::endl;
}
