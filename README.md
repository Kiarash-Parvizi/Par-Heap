## Adaptive Cache-Friendly Priority Queue: Fine-Tuning Heap Efficiency
In this research project a new approach to priority queues is presented, specifically designed to enhance cache-friendliness. Our data structure incorporates three adjustable parameters, allowing for a customized heap structure that can adapt to different system conditions. A search method is used, determining the optimal parameter values, eliminating the need for manual configuration and delivering notable performance improvements, as demonstrated through rigorous testing on the heap sort algorithm. Importantly, this designed data structure can dynamically grow without the need for reconstructing the heap tree. The adaptability of our cache-friendly priority queue makes it particularly interesting in the context of modern computing, where system architectures can vary widely.

#### **Research Paper:** https://arxiv.org/abs/2310.06663

### Important Notes:
- **Compilation Optimization:** Ensure that you compile the source codes with a minimum optimization level of O2. Failing to do so increases the overhead associated with the extra instructions required in our Par-Heap implementation. All methods discussed in the research paper were compiled for benchmarking purposes using clang on O2 optimization level.

- **Compiler Choice:** Regrettably, the GCC compiler struggled to optimize the new source code effectively on our machine. Consequently, we opted for Clang in this project for better performance.

- To ensure accurate results, avoid running any additional programs simultaneously while executing the source codes. We highly recommend avoiding any system activity while the code for finding optimal parameters is running. For our tests, we went a step further and ran the codes with the highest priority on our Fedora machine to guarantee the most precise outcomes. However, it's worth noting that this step proved to be unnecessary when extra system activity is avoided.

### Running and Testing:
In order to find the optimal tree layout on your machine:
```
cd "find optimal params"
clang++ -O2 find_optimal_3par.cpp
sudo nice --20 ./a.out
```
Once you've found the optimal parameters, modify the object instantiation line in "cache-benchmark/cache_time_benchmark.cpp" file (note that for inter_ch_cnt values greater than 1 you need to import the Par-Heap_3par.hpp instead) then use these cmds to run the benchmarks:
```
cd cache-benchmark
clang++ -O2 -lpapi cache_time_benchmark.cpp
./a.out
```

### Requirements:
- PAPI (icl.cs.utk.edu/projects/papi)

