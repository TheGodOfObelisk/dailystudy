#include <iostream>
#include "my_set.h"
#include <string>


using namespace std;

int main(){
    string girl = "Anna";
    // prepare to test
    main_savitch_3::set set1;// 现在是空的
    cout << "Declare a new set called set1." << endl;
    cout << "Keep inserting new items into set1 until it is full." << endl;
    for(int i = 0; i < set1.CAPACITY; i++){
        set1.insert(i);
        cout << "Now there are " << set1.size() << " item(s) in set1." << endl;
    }
    cout << "Erase one item from set1." << endl;
    if(set1.erase(28) == true){
        cout << "Succeed to erase 28 from set1" << endl;
    } else {
        cout << "Failed to erase 28 from set1" << endl;
    }
    if(set1.contains(28)){
        cout << "28 in set1." << endl;
    } else {
        cout << "no 28 in set1." << endl;
    }
    cout << "Now there are " << set1.size() << " item(s) in set1." << endl;
    cout << "Declare set2" << endl;
    main_savitch_3::set set2;
    cout << "Insert 2 into set2" << endl;
    set2.insert(2);
    cout << "set2 = set1 + set2" << endl;
    set2 += set1;
    cout << "How many 2s in set2?" << endl;
    cout << "Here are " << set2.count(2) << " 2(s)" << endl;
    cout << "Try to erase 2 from set2." << endl;
    cout << "Erase " << set2.erase(2) << " 2(s) from set2" << endl;
    cout << "How many 2s in set2 now?" << endl;
    cout << "Here are " << set2.count(2) << " 2(s)" << endl;
    cout << "How many item(s) in set2 now?" << endl;
    cout << "Here are " << set2.size() << " item(s) in set2 now." << endl;

    cout << "set3 = set1 - set2" << endl;
    main_savitch_3::set set3 = set1 - set2;
    cout << "The size of set3: " << set3.size() << endl;
    return 0;
}