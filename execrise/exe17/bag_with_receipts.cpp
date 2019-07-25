// FILE: bag_with_receipts1.cpp
// CLASS IMPLEMENTED: bag_with_receipts (see bag_with_receipts1.h for documentation)
// INVARIANT for the bag_with_receipts class:
//   1. The number of items in the bag_with_receipts is in the member variable used;
//   2. For an empty bag_with_receipts, we do not care what is stored in any of data; for a
//      non-empty bag_with_receipts the items in the bag_with_receipts are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "bag_with_receipts.h"
using namespace std;

namespace main_savitch_3
{
    const bag_with_receipts::size_type bag_with_receipts::CAPACITY;

    bag_with_receipts::bag_with_receipts(){
        used = 0;
        in_use[CAPACITY] = {false};
    }

    bag_with_receipts::size_type bag_with_receipts::erase(const value_type& target)
    {
	size_type index = 0;
	size_type many_removed = 0;

	while (index < CAPACITY)
	{
	    // if (data[index] == target)
	    // {
		// --used;
		// data[index] = data[used];
		// ++many_removed;
	    // }
	    // else
		// ++index;
        if(data[index] == target && in_use[index]){
            ++many_removed;
            in_use[index] =  false;// erase it
        }
        index++;
	}
    used -= many_removed;
	return many_removed;
    }

    bool bag_with_receipts::erase_one(const value_type& target)
    {
	size_type index; // The location of target in the data array    

	// First, set index to the location of target in the data array,
	// which could be as small as 0 or as large as used-1. If target is not
	// in the array, then index will be set equal to used.
	index = 0; 
	while ((index < CAPACITY) && (data[index] != target))
	    ++index;

	if (index == CAPACITY)
	    return false; // target isn’t in the bag_with_receipts, so no work to do.

	// When execution reaches here, target is in the bag_with_receipts at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	// data[index] = data[used]; 
    in_use[index] = false; // erase it   
	return true;
    }

    int bag_with_receipts::insert(const value_type& entry)
    // Library facilities used: cassert
    {   
        assert(size( ) < CAPACITY);
        int i;
        for(i = 0; i < CAPACITY; i++){
            if(!in_use[i]){
                data[i] = entry;
                in_use[i] = true;
                ++used;
                break;
            }
        }
	    return i;// the receipt
    }

    void bag_with_receipts::remove(int receipt, value_type& copy_item){
        // remove the item whose receipt has been presented
        in_use[receipt] = false;
        --used;
        copy_item = data[receipt];
    }

    void bag_with_receipts::operator +=(const bag_with_receipts& addend)
    // Library facilities used: algorithm, cassert
    {
	assert(size( ) + addend.size( ) <= CAPACITY);
	
	// copy(addend.data, addend.data + addend.used, data + used);
    size_type index1, index2;
    index1 = index2 = 0;

    while(index1 < CAPACITY && index2 < CAPACITY){
        if(!in_use[index1]){
            while(!addend.in_use[index2]){
                index2++;
            }
            // now addend.data[index2] is actually in use
            in_use[index1] = true;
            data[index1] = addend.data[index2];
            index2++;
        }
        index1++;
    }

	used += addend.used;
    }

    void bag_with_receipts::operator -=(const bag_with_receipts& subend){
        // assert(size() - subend.size() >= 0);
        // for(size_type i = 0; i < subend.used; i++){
        //     for(size_type j = 0; j < this->used; j++){
        //         if(subend.data[i] == this->data[j]){
        //             this->erase_one(subend.data[i]);
        //             continue;
        //         }
        //     }
        // }
        for(size_type i = 0; i < subend.CAPACITY; i++){
            for(size_type j = 0; j < this->CAPACITY; j++){
                if((subend.data[i] == this->data[j]) && subend.in_use[i] && this->in_use[j]){
                    this->erase_one(subend.data[i]);
                    continue;
                }
            }
        }
    }

    bag_with_receipts::size_type bag_with_receipts::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < CAPACITY; ++i)
            if (target == data[i] && in_use[i])
                ++answer;
        return answer;
    }

    bag_with_receipts operator +(const bag_with_receipts& b1, const bag_with_receipts& b2)
    // Library facilities used: cassert
    {
        bag_with_receipts answer;

        assert(b1.size( ) + b2.size( ) <= bag_with_receipts::CAPACITY);

        answer += b1; 
        answer += b2;
        return answer;
    }

    bag_with_receipts operator -(const bag_with_receipts& b1, const bag_with_receipts& b2){
        bag_with_receipts answer;

        // assert(b1.size() - b2.size() >= 0);
        answer = b1;
        answer -= b2;
        return answer;
    }
}
