#include "sorted_sequence.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace main_savitch_3;

sorted_sequence::sorted_sequence(){
    // If there is a current item, then it lies in data[current_index];
    // if there is no current item, then current_index equals used.
    current_index = used = 0;
}

void sorted_sequence::start(){
    current_index = 0;
}

void sorted_sequence::advance(){
    current_index = (current_index + 1) % CAPACITY;
    // the max of current_index is CAPACITY-1
}

void sorted_sequence::insert(const value_type& entry){
    assert(size() < CAPACITY);
    size_type i;
    if(current_index != used){
        for(i = current_index; i < size(); i++);
    }
    if(used == 0){
        data[0] = entry;
        used++;
        current_index = 0;
        return;
    }
    for(; i != 0 && entry < data[i-1]; i--){
        data[i] = data[i-1];
    }
    data[i] = entry;
    used++;
    current_index = i;
    return;
}

void sorted_sequence::remove_current(){
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

sorted_sequence::size_type sorted_sequence::size() const{
    return used;
}

bool sorted_sequence::is_item() const{
    if(current_index >= used){
        return false;
    } else {
        return true;
    }
}

sorted_sequence::value_type sorted_sequence::current() const{
    assert(is_item());
    return data[current_index];
}

void sorted_sequence::insert_head(const value_type& entry){
    assert(size() < CAPACITY);
    size_t i = size();
    for(; i > 0; i--){
        data[i] = data[i-1];//数据后移
    }
    // i = 0
    data[i] = entry;
    used++;
}

void sorted_sequence::remove_head(){
    assert(size() > 0);
    size_t i = 0;
    for(; i < size(); i++){
        data[i] = data[i+1];
    }
    used--;
}

void sorted_sequence::insert_tail(const value_type& entry){
    assert(size() < CAPACITY);
    data[size()] = entry;
    used++;    
}

void sorted_sequence::end(){
    current_index = size() - 1;
}

sorted_sequence sorted_sequence::operator -(sorted_sequence& entry){
    sorted_sequence res;
    for(this->start(); this->is_item(); this->advance()){
        res.insert(this->current());
    }
    for(entry.start(); entry.is_item(); entry.advance()){
        for(res.start(); res.is_item(); res.advance()){
            if(res.current() == entry.current()){
                res.remove_current();
            }
        }
    }
    return res;
}

void sorted_sequence::operator -=(sorted_sequence& entry){
    for(entry.start(); entry.is_item(); entry.advance()){
        for(start(); is_item(); advance()){
            if(entry.current() == current()){
                remove_current();
            }
        }
    }
}

sorted_sequence::value_type sorted_sequence::operator [](size_type index) const{
    assert(index >= 0 && index < size());
    return data[index];
}

// void sorted_sequence::operator =(const sorted_sequence& entry){
//     for(entry.start(); entry.is_item(); entry.advance()){
//         this->insert(entry.current());
//     }
// }