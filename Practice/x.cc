#include <iostream>
#include <vector>

using namespace std;

template <class T>
int BiSearch(vector<T>& a, T key){
    int lo = 0, mid, hi = a.size();
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(key < a[mid])
            hi = mid - 1;
        else if(a[mid] < key)
            lo = mid + 1;
        else return mid;
    }
    return -1;
}

int main (){
    vector<int> list = {1,2,4,5,6,7,8,9};
    int n = 5;
    int out = BiSearch<int>(list, n);
    cout << out << endl;

    return 0;
}