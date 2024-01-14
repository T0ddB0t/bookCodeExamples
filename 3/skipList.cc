#include <iostream>
#include "skipList.h"

int main(){
    SkipList<int> test;
    test.skipListInsert(1);
    test.skipListInsert(2);
    test.skipListInsert(3);
    test.skipListInsert(4);
    //std::cout << test.skipListSearch(3) << std::endl;
}