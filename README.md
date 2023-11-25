## Adaptive Cache-Friendly Priority Queue: Enhancing Heap-Tree Efficiency for Modern Computing
Priority queues are fundamental data structures with widespread applications in various domains, including graph algorithms and network simulations. Their performance critically impacts the overall efficiency of these algorithms. Traditional priority queue implementations often face cache-related performance bottlenecks, especially in modern computing environments with hierarchical memory systems. To address this challenge, we propose an adaptive cache-friendly priority queue that utilizes three adjustable parameters to optimize the heap tree structure for specific system conditions by making a tradeoff between cache friendliness and the average number of cpu instructions needed to carry out the data structure operations. Compared to the implicit binary tree model, our approach significantly reduces the number of cache misses and improves performance, as demonstrated through rigorous testing on the heap sort algorithm. We employ a search method to determine the optimal parameter values, eliminating the need for manual configuration. Furthermore, our data structure is laid out in a single compact block of memory, minimizing the memory consumption and can dynamically grow without the need for costly heap tree reconstructions. The adaptability of our cache-friendly priority queue makes it particularly well-suited for modern computing environments with diverse system architectures.

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

