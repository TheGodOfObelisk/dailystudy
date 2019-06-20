#ifndef MAIN_SAVITCH_set1_H
#define MAIN_SAVITCH_set1_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_3
{
    class set
    { 
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        set( ) { used = 0; } 
        // MODIFICATION MEMBER FUNCTIONS
        bool erase(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const set& addend);
        void operator -=(const set& subend);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
        bool contains(const value_type& target) const;
    private:
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
    };

    // NONMEMBER FUNCTIONS for the set class
    set operator +(const set& b1, const set& b2);
    set operator -(const set& b1, const set& b2);
}

#endif
