#include "sequence1.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace main_savitch_3;

sequence::sequence(){
    // If there is a current item, then it lies in data[current_index];
    // if there is no current item, then current_index equals used.
    current_index = used = 0;
}

void sequence::start(){
    current_index = 0;
}

void sequence::advance(){
    current_index = (current_index + 1) % CAPACITY;
    // the max of current_index is CAPACITY-1
}

void sequence::insert(const value_type& entry){
    assert(size() < CAPACITY);
    size_type i;
    if(current_index == used){//no current item
        for(i = current_index; i != 0; i--){
            data[i] = data[i-1];
        }
        data[i] = entry;
        used++;
        current_index = i;
        return;
    }
    for(i = current_index; i < size(); i++);
    for(; i != current_index; i--){
        data[i] = data[i-1];
    }
    data[i] = entry;// now i equals current_index
    used++;
}

void sequence::attach(const value_type& entry){
    assert(size() < CAPACITY);
    size_type i;
    if(current_index == used){//no current item
        data[current_index] = entry;
        used++;
        return;
    }
    for(i = current_index; i < size(); i++);
    for(; i != current_index; i--){
        data[i] = data[i-1];
    }
    data[i+1] = entry;// put entry in data[current_index+1]
    used++;
}

void sequence::remove_current(){
    assert(is_item());
    if(current_index == size()-1){
        // the last one
        used--;
    } else {
        for(size_type i = current_index; i < size(); i++){
            data[i] = data[i+1];
        }
        used--;
    }
}

sequence::size_type sequence::size() const{
    return used;
}

bool sequence::is_item() const{
    if(current_index >= used){
        return false;
    } else {
        return true;
    }
}

sequence::value_type sequence::current() const{
    assert(is_item());
    return data[current_index];
}