## Adaptive Cache-Friendly Priority Queue: Fine-Tuning Heap Efficiency
In this research project a new approach to priority queues is presented, specifically designed to enhance cache-friendliness. Our data structure incorporates three adjustable parameters, allowing for a customized heap structure that can adapt to different system conditions. A search method is used, determining the optimal parameter values, eliminating the need for manual configuration and delivering notable performance improvements, as demonstrated through rigorous testing on the heap sort algorithm. Importantly, this designed data structure can dynamically grow without the need for reconstructing the heap tree. The adaptability of our cache-friendly priority queue makes it particularly interesting in the context of modern computing, where system architectures can vary widely.

#### **Research Paper:** https://arxiv.org/abs/2310.06663

### Important Notes:
- **Compilation Optimization:** Ensure that you compile the source codes with a minimum optimization level of O2. Failing to do so increases the overhead associated with the extra instructions required in our Par-Heap implementation. All methods discussed in the research paper were compiled for benchmarking purposes using clang on O2 optimization level.

- **Compiler Choice:** Regrettably, the GCC compiler struggled to optimize the new source code effectively on our machine. Consequently, we opted for Clang in this project for better performance.

