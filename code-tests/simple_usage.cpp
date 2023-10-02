#include<iostream>
#include<vector>
#include "../Par-Heap.hpp"
#include "../utils.hpp"
using namespace std;

int main() {
    cout << "starting...\n";
    Par_Heap h(1, 3);
    vector vec{12,19,11,-1,2,0,8,20,15,5,-30,9,9,9,11,7,7};
    h.heap_sort(&vec[0], vec.size());
    cout << vec << endl;
}

