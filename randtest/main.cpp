#include <iostream>
#include <chrono>
#include <random>

int run(){
  std::mt19937 mt;
  std::uniform_int_distribution<> ud(0,128);
  int r = ud(mt);
  for(int i=0;i<100000000;i++){
    r ^= ud(mt);
  }
  return r;
}

int main() {
auto start = std::chrono::system_clock::now();
  std::cout << run() << std::endl;
  auto end = std::chrono::system_clock::now();
  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "Elapsed : " << elapsed << " [ms]" << std::endl;
}
