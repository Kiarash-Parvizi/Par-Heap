#include "../Par-Heap_3par.hpp"
#include "../Par-Heap_inter1.hpp"
#include "../utils.hpp"

int main() {
    //unit_test();
    //cout << "---\n";
    //return 0;
    //{
    vector<int> vecE;
    int NN = 8e7;
    cout << "N: " << NN << endl;
    for (int i = NN; i > 0; i--) {
        int v = rand()%100100100;
        vecE.push_back(v);
    }

    // Par_Heap
    {
    xyz bestConf;
    int bestTime = 2e9;
    //Par_Heap(int block_depth, int intra_ch_cnt):
    for (int inter_ch = 1; inter_ch < 3; inter_ch++)
    for (int b_ch = 2; b_ch < 11; b_ch++)
    for (int D = 1; D < 11; D++) {
        cout << "Par_Heap ; D = " << D << ", b_ch: " << b_ch << ", inter_ch: " << inter_ch << '\n';
        auto tmp = vecE;
        //cout << funcTime() << '\n';
        auto time = funcTime([&tmp,D,b_ch,inter_ch]() {
                if (inter_ch == 1) {
                    Par_Heap_inter1(D,b_ch).heap_sort(&tmp[0], tmp.size());
                } else {
                    Par_Heap(D,b_ch,inter_ch).heap_sort(&tmp[0], tmp.size());
                }
            });
        if (time < bestTime) {
            cout << "BBBBBBBBBBBBBBBb\n";
            bestTime = time;
            bestConf = {D,b_ch,inter_ch};
        }
        cout << "time: " << time << '\n';
        cout << "OK = " << arr_is_sorted(&tmp[0], tmp.size()) << "\n\n";
        //cout << "sec= " << arr_is_sorted(&vecE[0], tmp.size()) << "\n\n";
        //cout << "final Ok = " << is_sorted_correctly(&vecE[0], &tmp[0], tmp.size()) << "\n\n";
        //for (int v: tmp) cout << v << ' '; cout << endl;
    }
    cout << "bestTime: " << bestTime << '\n';
    cout << "bestConf (D,b_ch,inter_ch): " << bestConf.x << ", " << bestConf.y << ", " << bestConf.z << '\n';
    cout << "for n = " << NN << endl;
    }
}

