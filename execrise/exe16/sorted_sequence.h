// FILE: sorted_sequence1.h
// CLASS PROVIDED: sorted_sequence (part of the namespace main_savitch_3)
// There is no implementation file provided for this class since it is
// an exercise from Section 3.2 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the sorted_sequence class:
//   typedef ____ value_type
//     sorted_sequence::value_type is the data type of the items in the sorted_sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sorted_sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sorted_sequence.
//
//   static const size_type CAPACITY = _____
//     sorted_sequence::CAPACITY is the maximum number of items that a sorted_sequence can hold.
//
// CONSTRUCTOR for the sorted_sequence class:
//   sorted_sequence( )
//     Postcondition: The sorted_sequence has been initialized as an empty sorted_sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sorted_sequence class:
//   void start( )
//     Postcondition: The first item on the sorted_sequence becomes the current item
//     (but if the sorted_sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sorted_sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sorted_sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sorted_sequence. In either case, the newly
//     inserted item is now the current item of the sorted_sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sorted_sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sorted_sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sorted_sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sorted_sequence.
//
// VALUE SEMANTICS for the sorted_sequence class:
//    Assignments and the copy constructor may be used with sorted_sequence objects.

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_3
{
    class sorted_sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        sorted_sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void remove_current( );
        void insert_head(const value_type& entry);
        void remove_head();
        void insert_tail(const value_type& entry);
        void end();
        sorted_sequence operator -(sorted_sequence& entry);
        void operator -=(sorted_sequence& entry);
        value_type operator [](size_type index) const;
        // void operator =(const sorted_sequence& entry);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
}

#endif

