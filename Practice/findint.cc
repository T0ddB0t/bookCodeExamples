#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<vector<int>>& arr, const int& key){
    int rows = arr.size();
    if(rows == 0)
        return -1;
    
    int cols = arr[0].size();
    int lo = 0, hi = rows * cols - 1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int row = mid / cols;
        int col = mid % cols;

        if(arr[row][col] == key)
            return mid;
        else if(arr[row][col] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

bool searchMatrix(vector<vector<int>>& arr, const int& key){
    int t = 0;
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[i].size(); j++)
            if(binarySearch(arr, key) != -1)
                return true;
    return false;
}

int main(){
    vector<vector<int>> x = {{1}};
    cout << searchMatrix(x, 1);
}