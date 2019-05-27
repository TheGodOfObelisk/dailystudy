#include <iostream>
#include "bag1.h"

using namespace std;

int main(){
    // prepare to test
    main_savitch_3::bag bag1;// 现在是空的
    cout << "Declare a new bag called bag1." << endl;
    cout << "Keep inserting new items into bag1 until it is full." << endl;
    for(int i = 0; i < bag1.CAPACITY; i++){
        bag1.insert(i);
        cout << "Now there are " << bag1.size() << " item(s) in bag1." << endl;
    }
    cout << "Erase one item from bag1." << endl;
    if(bag1.erase_one(28) == true){
        cout << "Succeed to erase 28 from bag1" << endl;
    } else {
        cout << "Failed to erase 28 from bag1" << endl;
    }
    cout << "Now there are " << bag1.size() << " item(s) in bag1." << endl;
    cout << "Declare bag2" << endl;
    main_savitch_3::bag bag2;
    cout << "Insert 2 into bag2" << endl;
    bag2.insert(2);
    cout << "bag2 = bag1 + bag2" << endl;
    bag2 += bag1;
    cout << "How many 2s in bag2?" << endl;
    cout << "Here are " << bag2.count(2) << " 2(s)" << endl;
    cout << "Try to erase 2 from bag2." << endl;
    cout << "Erase " << bag2.erase(2) << " 2(s) from bag2" << endl;
    cout << "How many 2s in bag2 now?" << endl;
    cout << "Here are " << bag2.count(2) << " 2(s)" << endl;
    cout << "How many item(s) in bag2 now?" << endl;
    cout << "Here are " << bag2.size() << " item(s) in bag2 now." << endl;

    cout << "bag3 = bag1 - bag2" << endl;
    main_savitch_3::bag bag3 = bag1 - bag2;
    cout << "The size of bag3: " << bag3.size() << endl;
    return 0;
}