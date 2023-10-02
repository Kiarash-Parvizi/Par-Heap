#include<algorithm>
#define ll long long
using namespace std;

class Par_Heap {
    ll block_depth, block_width;
    ll block_sz      = 0;
    ll sub_block_sz  = 0;
    ll block_ch_cnt;
    ll intra_ch_cnt;
    ll inter_ch_cnt;
    int* data;
    ll n;
public:

//public:
    Par_Heap(ll block_depth, ll intra_ch_cnt, ll inter_ch_cnt):
        block_depth(block_depth),
        intra_ch_cnt(intra_ch_cnt),
        inter_ch_cnt(inter_ch_cnt)
    {
        block_width = 1;
        block_sz = 1;
        for (ll i = 0; i < block_depth; i++) {
            sub_block_sz += block_width;
            block_width *= intra_ch_cnt;
            block_sz += block_width;
        }
        block_ch_cnt = block_width*inter_ch_cnt;
    }

    inline void heapify(ll I, ll localI) {
        // calculate the actual index of the current node in the data array
        ll index = I * block_sz + localI;
        // check if it's a block leaf node
        if (localI >= sub_block_sz) {
            // the current node is a leaf node
            //
            // calculate the range of its childs
            ll itI = I*block_ch_cnt + 1 + (localI-sub_block_sz)*inter_ch_cnt;
            ll start  = (itI) * block_sz;
            ll end = min(start + inter_ch_cnt * block_sz, n);
            // iterate over the calculated range
            int mx = data[index];
            ll mx_I = I;
            for (; start < end; start += block_sz, ++itI) {
                // compare (set max)
                if (data[start] > mx) {
                    mx = data[start];
                    mx_I = itI;
                }
            }
            // terminate heapify if no child of the parent has a greater value
            if (mx_I == I) return;
            // swap & recursively call heapify
            swap(data[mx_I * block_sz], data[index]);
            heapify(mx_I, 0);
            return;
        }
        // if it's not a block leaf node, then the mapping to children is done
        // the same way as the regular d-ary heap:
        //
        // calculate the range of its childs
        ll start = I*block_sz + localI * intra_ch_cnt + 1;
        ll end = min(start + intra_ch_cnt, n);
        // iterate over the calculated range
        int mx = data[index];
        ll mx_index = index;
        for (; start < end; ++start) {
            // compare (set max)
            if (data[start] > mx) {
                mx = data[start];
                mx_index = start;
            }
        }
        // terminate heapify if no child of the parent has a greater value
        if (mx_index == index) return;
        // swap & recursively call heapify
        swap(data[mx_index], data[index]);
        heapify(I, mx_index-I*block_sz);
    }

    void heap_sort(int arr[], int n) {
        this->data = arr;
        this->n = n;
        // build heap (rearranges the array)
        for (ll i = n - 1; i >= 0; i--) {
            ll I = i/block_sz;
            heapify(I, i - I*block_sz);
        }
    
        // extract elements from heap one by one
        for (ll i = n - 1; i >= 0; i--) {
            // move current root to end
            swap(arr[0], arr[i]);
            this->n = i;
    
            // call max heapify on the reduced heap
            heapify(0, 0);
        }
    }
};

