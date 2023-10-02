#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include <chrono>
#include <utility>

#define ll long long
struct xyz {ll x,y,z;};

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

template<typename F, typename... Args>
double funcTime(F func, Args&&... args){
    TimeVar t1=timeNow();
    func(std::forward<Args>(args)...);
    return duration(timeNow()-t1);
}


template<class T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (auto& v: vec) { in >> v; }
    return in;
}

template<class T>
ostream& operator<<(ostream& o, const vector<T>& vec) {
    o << "[";
    for (const auto& v: vec) { o << v << ' '; }
    o << "]\n";
    return o;
}


bool arr_is_sorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

bool is_sorted_correctly(int unsorted[], int sorted[], int n) {
    sort(unsorted, unsorted+n);
    for (int i = 0; i < n; i++) {
        if (unsorted[i] != sorted[i]) return false;
    }
    return true;
}



