# Monte Carlo Simulation of 4-state Potts Model

## Summary

A sample code which performs Monte Carlo simulation of 4-state Potts Model with Swendsen-Wang algorithm.

## Usage

```sh
make
make run
```

## Compile Options

GCC

```sh
g++ -O3 -march=native -Wall -Wextra -std=c++11  main.cpp -o gcc.out
```

Intel Compiler

```sh
icpc -O3 -xHOST -Wall -Wextra -std=c++11  main.cpp -o icpc.out
```

## Results

Environment

* CPU: Intel(R) Xeon(R) Gold 6230 CPU @ 2.10GHz
* OS: CentOS Linux release 7.6.1810 (Core)
* GCC: g++ (GCC) 7.3.1 20180303 (Red Hat 7.3.1-5)
* icpc: icpc (ICC) 19.0.4.243 20190416

```txt
$ ./gcc.out
Magnetization : 0.891599
Elapsed : 305 [ms]

$ ./icpc.out
Magnetization : 0.891599
Elapsed : 880 [ms]
```

The two executables give the identical result, but the executable produced by Intel Compiler is significantly slower than that by GCC.

## License

MIT. See [LICENSE](LICENSE).
