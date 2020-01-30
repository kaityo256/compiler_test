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

Here are some benchmark results on several environments. In any cases, the two executables give the identical result, but the executable produced by Intel Compiler is significantly slower than that by GCC.

### Environment 1

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

### Environment 2

* CPU: Intel(R) Xeon(R) CPU E5-2680 v3 @ 2.50GHz
* OS: SUSE Linux Enterprise Server 11 (x86_64)
* g++ (GCC) 5.4.0
* icpc (ICC) 18.0.5 20180823

```txt
$ ./gcc.out
Magnetization : 0.891599
Elapsed : 467 [ms]

$ ./icpc.out
Magnetization : 0.891599
Elapsed : 1524 [ms]
```

### Environment 3

* CPU: Intel(R) Xeon(R) Gold 6130 CPU @ 2.10GHz
* OS: Red Hat Enterprise Linux Server release 7.7 (Maipo)
* g++ (GCC) 6.3.0
* icpc (ICC) 18.0.5 20180823

```txt
./gcc.out
Magnetization : 0.891599
Elapsed : 333 [ms]
./icpc.out
Magnetization : 0.891599
Elapsed : 952 [ms]
```

## License

MIT. See [LICENSE](LICENSE).
