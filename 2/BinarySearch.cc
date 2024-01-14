#include <iostream>
#include <vector>

using namespace std;

template <class genType>
int binarySearch(const vector<vector<genType>>& arr, const genType& key){
    int rows = arr.size();
    if (rows == 0)
        return -1;

    int cols = arr[0].size();
    int lo = 0, hi = rows * cols - 1;

    while (lo <= hi){
        int mid = (lo + hi) / 2;
        int row = mid / cols;
        int col = mid % cols;

        if (arr[row][col] == key)
            return mid;
        else if (arr[row][col] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return -1;
}
int main(){
    vector<vector<char>> x = {{'A','B','C'}, {'D','E','F'}};
    int n = binarySearch(x, 'E');
    cout << "at position " << n;
}