// FILE: bag_with_receipts1.h
// CLASS PROVIDED: bag_with_receipts (part of the namespace main_savitch_3)
//
// TYPEDEF and MEMBER CONSTANTS for the bag_with_receipts class:
//   typedef ____ value_type
//     bag_with_receipts::value_type is the data type of the items in the bag_with_receipts. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     bag_with_receipts::size_type is the data type of any variable that keeps track of how many items
//     are in a bag_with_receipts.
//
//   static const size_type CAPACITY = _____
//     bag_with_receipts::CAPACITY is the maximum number of items that a bag_with_receipts can hold.
//
// CONSTRUCTOR for the bag_with_receipts class:
//   bag_with_receipts( )
//     Postcondition: The bag_with_receipts has been initialized as an empty bag_with_receipts.
//
// MODIFICATION MEMBER FUNCTIONS for the bag_with_receipts class:
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag_with_receipts.
//     The return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const value_type& target)
//     Postcondition: If target was in the bag_with_receipts, then one copy has been removed;
//     otherwise the bag_with_receipts is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the bag_with_receipts.
//
//   void operator +=(const bag_with_receipts& addend)
//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
//     Postcondition: Each item in addend has been added to this bag_with_receipts.
//
// CONSTANT MEMBER FUNCTIONS for the bag_with_receipts class:
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the bag_with_receipts.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the bag_with_receipts.
//
// NONMEMBER FUNCTIONS for the bag_with_receipts class:
//   bag_with_receipts operator +(const bag_with_receipts& b1, const bag_with_receipts& b2)
//     Precondition:  b1.size( ) + b2.size( ) <= bag_with_receipts::CAPACITY.
//     Postcondition: The bag_with_receipts returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag_with_receipts class:
//    Assignments and the copy constructor may be used with bag_with_receipts objects.

#ifndef MAIN_SAVITCH_BAG1_H
#define MAIN_SAVITCH_BAG1_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_3
{
    class bag_with_receipts
    { 
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        bag_with_receipts( ); 
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void remove(int receipt, value_type& copy_item);
        int insert(const value_type& entry);
        void operator +=(const bag_with_receipts& addend);
        void operator -=(const bag_with_receipts& subend);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
    private:
        value_type data[CAPACITY];  // The array to store items
        bool in_use[CAPACITY];      // parallel arrays
        size_type used;             // How much of array is used
    };

    // NONMEMBER FUNCTIONS for the bag_with_receipts class
    bag_with_receipts operator +(const bag_with_receipts& b1, const bag_with_receipts& b2);
    bag_with_receipts operator -(const bag_with_receipts& b1, const bag_with_receipts& b2);
}

#endif
