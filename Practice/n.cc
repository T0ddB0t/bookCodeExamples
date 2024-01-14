#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

    bool reverseInt(int x){
        string rev = to_string(x);
        string test = rev;        
        reverse(rev.begin(),rev.end());
        if(test == rev){
            return true;
        }
        return false;
    }

int main(){
    cout << reverseInt(-313);
}