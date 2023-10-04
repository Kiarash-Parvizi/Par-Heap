#include "../Par-Heap_3par.hpp"
#include "../older-heap-sort-methods.hpp"
#include "../utils.hpp"

#include "papi.h"

int main() {
    // papi
    {
        // initialize Par-Heap object
        Par_Heap pHeap(2, 9, 1);

        // measure
        int retval = PAPI_NULL;
        retval = PAPI_library_init(PAPI_VER_CURRENT);
        
        if(retval != PAPI_VER_CURRENT){
            printf("lib init err : %d\n",retval);
            return -1;
        }
        int EventSet= PAPI_NULL;

        if (PAPI_create_eventset(&EventSet) != PAPI_OK){
            printf("couldnt make event set \n");
            return -1;
        }

        if(PAPI_add_event(EventSet , PAPI_L3_TCM) != PAPI_OK){
            printf("cache l3 not avail \n");
            return -1;
        }

        cout << "----------\n";
        cout << "Par_Heap(2, 8, 1):\n";
        vector<int> NNs{10, 100, 1000, (int)1e4, (int)1e5, (int)1e6, (int)1e7, (int)5e7, (int)1e8};
        int test_count = 1;
        for (int NN: NNs) {
            cout << "--------------------------------\n";
            cout << "--------------------------------\n";
            //double totTime = 0;
            long long tot = 0;
            for (int i_ = 0; i_ < test_count; i_++) {
                long_long value[1]={0};

                // create the vector
                vector<int> tmp;
                for (int i = NN; i > 0; i--) {
                    int v = rand()%100100100;
                    tmp.push_back(v);
                }

                // start the benchmark
                if(PAPI_start(EventSet)!= PAPI_OK){
                    printf("couldnt start event \n");
                    return -1;
                }

                //task
                //auto time = funcTime([&tmp, &pHeap]() {
                pHeap.heap_sort(&tmp[0], tmp.size());
                //    });

                // end the benchmark
                if(PAPI_stop(EventSet,value)!=PAPI_OK){
                    return -1;
                }

                cout<<"l3 cache miss cnt : "<<value[0]<< "\n---"<< endl;
                tot += value[0];
                //cout<<"time : "<<time<< "\n---"<< endl;
                //totTime += time;
            }
                cout << "N: " << NN << '\n';
                cout<<"====> total   l3 cache miss cnt : "<<tot<< "\n---"<< endl;
                cout<<"====> average l3 cache miss cnt : "<<tot/test_count<< "\n---\n"<< endl;
                //cout<<"====> total   time : "<<totTime<< "\n---"<< endl;
                //cout<<"====> average time : "<<totTime/test_count<< "\n---\n"<< endl;
        }
        //
        cout << "----------\n";
        cout << "Heap recursive (ll index type):\n";
        for (int NN: NNs) {
            cout << "--------------------------------\n";
            cout << "--------------------------------\n";
            long long tot = 0;
            for (int i_ = 0; i_ < test_count; i_++) {
                long_long value[1]={0};

                // create the vector
                vector<int> tmp;
                for (int i = NN; i > 0; i--) {
                    int v = rand()%100100100;
                    tmp.push_back(v);
                }
                //cout << "N: " << tmp.size() << '\n';

                // start the benchmark
                if(PAPI_start(EventSet)!= PAPI_OK){
                    printf("couldnt start event \n");
                    return -1;
                }

                //task
                RegularHeapll().heap_sort_rec(&tmp[0], tmp.size());
                

                // end the benchmark
                if(PAPI_stop(EventSet,value)!=PAPI_OK){
                    return -1;
                }

                cout<<"l3 cache miss cnt : "<<value[0]<< "\n---"<< endl;
                tot += value[0];
            }
                cout << "N: " << NN << '\n';
                cout<<"====> total   l3 cache miss cnt : "<<tot<< "\n---"<< endl;
                cout<<"====> average l3 cache miss cnt : "<<tot/test_count<< "\n---\n"<< endl;
        }
        cout << "----------\n";
        cout << "std heap sort:\n";
        for (int NN: NNs) {
            cout << "--------------------------------\n";
            cout << "--------------------------------\n";
            long long tot = 0;
            for (int i_ = 0; i_ < test_count; i_++) {
                long_long value[1]={0};

                // create the vector
                vector<int> tmp;
                for (int i = NN; i > 0; i--) {
                    int v = rand()%100100100;
                    tmp.push_back(v);
                }
                //cout << "N: " << tmp.size() << '\n';

                // start the benchmark
                if(PAPI_start(EventSet)!= PAPI_OK){
                    printf("couldnt start event \n");
                    return -1;
                }

                //task
                std_heap_sort(&tmp[0], tmp.size());
                

                // end the benchmark
                if(PAPI_stop(EventSet,value)!=PAPI_OK){
                    return -1;
                }

                cout<<"l3 cache miss cnt : "<<value[0]<< "\n---"<< endl;
                tot += value[0];
            }
                cout << "N: " << NN << '\n';
                cout<<"====> total   l3 cache miss cnt : "<<tot<< "\n---"<< endl;
                cout<<"====> average l3 cache miss cnt : "<<tot/test_count<< "\n---\n"<< endl;
        }
    }
}
