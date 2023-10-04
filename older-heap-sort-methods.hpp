#include<algorithm>

void std_heap_sort(int arr[], int n) {
    make_heap(&arr[0],&arr[0]+n);
    sort_heap(&arr[0],&arr[0]+n);
}

class RegularHeapll {
public:
    // function to heapify a subtree rooted at index i
    void heapify(int arr[], ll n, ll i) {
        ll largest = i; // initialize largest as root
        ll l = 2 * i + 1; // left child
        ll r = 2 * i + 2; // right child
    
        // if left child is larger than root
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }
    
        // if right child is larger than largest so far
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }
    
        // if largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
    
            // recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    
    // main function to perform heap sort
    void heap_sort_rec(int arr[], int n) {
        // build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    
        // extract elements from heap one by one
        for (int i = n - 1; i >= 0; i--) {
            // move current root to end
            swap(arr[0], arr[i]);
    
            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
};

