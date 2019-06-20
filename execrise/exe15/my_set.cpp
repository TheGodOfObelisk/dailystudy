#include <iostream>
#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "my_set.h"
using namespace std;

namespace main_savitch_3
{
    const set::size_type set::CAPACITY;

    bool set::erase(const value_type& target)
    {
	size_type index; // The location of target in the data array    

	// First, set index to the location of target in the data array,
	// which could be as small as 0 or as large as used-1. If target is not
	// in the array, then index will be set equal to used.
	index = 0; 
	while ((index < used) && (data[index] != target))
	    ++index;

	if (index == used)
	    return false; // target isn’t in the set, so no work to do.

	// When execution reaches here, target is in the set at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];    
	return true;
    }

    void set::insert(const value_type& entry)
    // Library facilities used: cassert
    {   
        assert(size( ) < CAPACITY);
        if(contains(entry)){
            cout << entry << " already exists." << endl;
        }
        data[used] = entry;
	    ++used;
    }

    void set::operator +=(const set& addend)
    // Library facilities used: algorithm, cassert
    {
	assert(size( ) + addend.size( ) <= CAPACITY);
	
	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
    for(int i = 0; i < used; i++){
        while(count(data[i]) > 1){
            erase(data[i]);
        }
    }
    }

    void set::operator -=(const set& subend){
        // assert(size() - subend.size() >= 0);
        for(size_type i = 0; i < subend.used; i++){
            for(size_type j = 0; j < this->used; j++){
                if(subend.data[i] == this->data[j]){
                    this->erase(subend.data[i]);
                    continue;
                }
            }
        }
    }

    set::size_type set::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    set operator +(const set& b1, const set& b2)
    // Library facilities used: cassert
    {
        set answer;

        assert(b1.size( ) + b2.size( ) <= set::CAPACITY);

        answer += b1; 
        answer += b2;
        return answer;
    }

    set operator -(const set& b1, const set& b2){
        set answer;

        // assert(b1.size() - b2.size() >= 0);
        answer = b1;
        answer -= b2;
        return answer;
    }

    bool set::contains(const value_type& target) const{
    for(int i = 0; i < used; i++){
        if(data[i] == target){
            return true;
        }
    }
    return false;
}
}

