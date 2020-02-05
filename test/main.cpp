#include <iostream>
#include <random>
#include <chrono>
#include <string>

// https://github.com/boostorg/random/blob/develop/include/boost/random/uniform_real_distribution.hpp
double my_uniform_real(std::mt19937 &mt, double min_value, double max_value) {
  for(;;){
  double numerator = static_cast<double>(mt() - mt.min());
  double divisor = static_cast<double>(mt.max() - mt.min());
  double result = numerator / divisor * (max_value - min_value) + min_value;
  if(result < max_value) return result;
  }
}

using t_run = double(*)();

double run(void) {
  std::mt19937 mt(1);
  double r = 0.0;
  std::uniform_real_distribution<> ud(-1.0, 1.0);
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      if (i%2) r += ud(mt);
    }
  }
  return r;
}

double run_without_if(void) {
  std::mt19937 mt(1);
  double r = 0.0;
  std::uniform_real_distribution<> ud(-1.0, 1.0);
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      r += ud(mt);
    }
  }
  return r;
}

double run_int(void) {
  std::mt19937 mt(1);
  double r = 0.0;
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      r += my_uniform_real(mt, -100, 100);
    }
  }
  return static_cast<double>(r);
}


double run_my_distribution(void) {
  std::mt19937 mt(1);
  double r = 0.0;
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      r += my_uniform_real(mt, -1.0, 1.0);
    }
  }
  return r;
}

double run_linear(void) {
  std::minstd_rand0 mt(1);
  double r = 0.0;
  std::uniform_real_distribution<> ud(-1.0, 1.0);
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      if (i%2) r += ud(mt);
    }
  }
  return r;
}

double run_subtract(void) {
  std::ranlux24_base mt(1);
  double r = 0.0;
  std::uniform_real_distribution<> ud(-1.0, 1.0);
  for (int j = 0; j <10000; j++) {
    for (int i = 0; i < 10000; i++) {
      if (i%2) r += ud(mt);
    }
  }
  return r;
}


void measure(t_run run, std::string title){
  auto start = std::chrono::system_clock::now();
  double r = run();
  auto end = std::chrono::system_clock::now();
  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << title << " ";
  std::cout << "Result = " << r << " ";
  std::cout << "Elapsed = " << elapsed << " [ms]";
  std::cout << std::endl;
}


int main(){
  measure(run                , "mt       + real   + if");
  measure(run_linear         , "linear   + real   + if");
  measure(run_subtract       , "subtract + real   + if");
  measure(run_int            , "mt       + int    + if");
  measure(run_without_if     , "mt       + real   - if");
  measure(run_my_distribution, "mt       + myreal + if");
}
