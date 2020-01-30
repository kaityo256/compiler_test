#include <iostream>
#include <chrono>
#include <array>
#include <cmath>
#include <random>
#include <vector>

const int Q = 4;     // Number of States
const int L = 256;   // System Size
const int N = L * L; // Number of spins

std::mt19937 mt;
std::vector<int> spin(N), newspin(N);
std::vector<std::array<int, 4>> neighbor(N);
std::vector<int> parent(N);

int find(int i) {
  while (i != parent[i]) {
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}

void unite(int i, int j){
  i = find(i);
  j = find(j);
  if (i > j) {
    parent[i] = j;
  } else {
    parent[j] = i;
  }
}

int pos2index(int ix, int iy) {
  ix = (ix + L) % L;
  iy = (iy + L) % L;
  return ix + iy * L;
}

void init_neighbors() {
  for (int iy = 0; iy < L; iy++) {
    for (int ix = 0; ix < L; ix++) {
      int i = pos2index(ix, iy);
      neighbor[i][0] = pos2index(ix + 1, iy);
      neighbor[i][1] = pos2index(ix, iy + 1);
      neighbor[i][2] = pos2index(ix - 1, iy);
      neighbor[i][3] = pos2index(ix, iy - 1);
    }
  }
}

void connect(int i, int j, double p) {
  std::uniform_real_distribution<> ud(0.0, 1.0);
  if (spin[i] != spin[j]) return;
  if (ud(mt) > p) return;
  unite(i, j);
}

void mc_step(double beta) {
  std::uniform_int_distribution<> ud(0, Q - 1);
  for (int i = 0; i < N; i++) {
    parent[i] = i;
    newspin[i] = ud(mt);
  }
  const double p = 1.0 - exp(-beta);
  for (int i = 0; i < N; i++) {
    connect(i, neighbor[i][0], p);
    connect(i, neighbor[i][1], p);
  }
  for (int i = 0; i < N; i++) {
    spin[i] = newspin[find(i)];
  }
}

double magnetization(){
  std::vector<int> nc(N, 0);
  for (int i = 0; i < N; i++) {
    nc[find(i)]++;
  }
  const double ninv = 1.0/static_cast<double>(N);
  double nc2 = 0.0;
  for (int i = 0; i < N; i++) {
    double n2 = nc[i]*ninv;
    nc2 += n2*n2;
  }
  return nc2;
}

void run() {
  init_neighbors();
  const double beta = 1.25;
  std::fill(spin.begin(), spin.end(), 0);
  for (int i = 0; i <100; i++) {
    mc_step(beta);
  }
}

int main() {
auto start = std::chrono::system_clock::now();
  run();
  auto end = std::chrono::system_clock::now();
  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "Magnetization : " << magnetization()  << std::endl;
  std::cout << "Elapsed : " << elapsed << " [ms]" << std::endl;
}
