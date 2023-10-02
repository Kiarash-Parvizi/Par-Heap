#include "../utils.hpp"
#include "../Par-Heap_3par.hpp"
using namespace std;

int main() {
    for (int NN = 0; NN < 1000000; NN += 79)
    {
        // test gen
        vector<int> vecE;
        for (int i = NN; i > 0; i--) {
            int v = rand()%100100100;
            vecE.push_back(v);
        }
        // sort algo
        auto tmp = vecE;
        auto tmp2 = vecE;
        cout << "sorting..." << endl;
        Par_Heap(2,4,2).heap_sort(&tmp[0], tmp.size());
        sort(tmp2.begin(),tmp2.end());
        cout << "testing..." << endl;
        int okCnt = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] != tmp2[i]) {
                //cout << tmp << endl;
                cout << "EERRR" << endl;
                exit(1);
            } else okCnt++;
        }
        cout << "okcnt = " << okCnt << endl;
    }

}


