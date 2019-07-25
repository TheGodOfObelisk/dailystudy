// FILE: sorted_sequence_test.cxx
// An interactive test program for the new sorted_sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sorted_sequence.h"  // With value_type defined as double
using namespace std;
using namespace main_savitch_3;

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

void show_sorted_sequence(sorted_sequence display);
// Postcondition: The items on display have been printed to cout (one per line).

double get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.


int main( )
{
    sorted_sequence test, test1, test2; // A sorted_sequence that we’ll perform tests on
    char choice;   // A command character entered by the user
    
    cout << "I have initialized an empty sorted_sequence of real numbers." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case '!': test.start( );
                      break;
            case '@': test.end();
                      break;
            case '+': test.advance( );
                      break;
            case '?': if (test.is_item( ))
                          cout << "There is an item." << endl;
                      else 
                          cout << "There is no current item." << endl;
                      break;
            case 'C': if (test.is_item( ))
                           cout << "Current item is: " << test.current( ) << endl;
                      else
                          cout << "There is no current item." << endl;
                      break;
            case 'P': show_sorted_sequence(test);
                      break;
            case 'S': cout << "Size is " << test.size( ) << '.' << endl;
                      break;
            case 'I': test.insert(get_number( ));
                      break;
            case 'R': test.remove_current( );
                      cout << "The current item has been removed." << endl;
                      break;
            case 'H': test.insert_head(get_number());
                      break;
            case 'L': test.remove_head();
                      cout << "The item in the head has been removed." << endl;
                      break;     
            case 'Z': test.insert_tail(get_number());
                      cout << "A new item has been inserted into the tail." << endl;
                      break;
            case 'T': test1.insert(1);
                      test1.insert(2);
                      test1.insert(3);
                      cout << "test:" << endl;
                      show_sorted_sequence(test);
                      cout << "test1:" << endl;
                      show_sorted_sequence(test1);
                      test2 = test - test1;
                      cout << "test2 = test - test1, its result is" << endl;
                      show_sorted_sequence(test2);
                      test -= test1;
                      cout << "test -= test1, its result is" << endl;
                      show_sorted_sequence(test);
                      break;
            case 'G': cout << "The item is " << test[get_number()] << endl;
                      break;
            case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " !   Activate the start( ) function" << endl;
    cout << " @   Activate the end() function" << endl;
    cout << " +   Activate the advance( ) function" << endl;
    cout << " ?   Print the result from the is_item( ) function" << endl;
    cout << " C   Print the result from the current( ) function" << endl;
    cout << " P   Print a copy of the entire sorted_sequence" << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Activate the remove_current( ) function" << endl;
    cout << " H   Insert a new item with insert_head() function" << endl;
    cout << " L   Remove an item with remove_head() function" << endl;
    cout << " Z   Insert a new item with insert_tail() function" << endl;
    cout << " T   Test the operator - and -=" << endl;
    cout << " G   Test the operator []" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

void show_sorted_sequence(sorted_sequence display)
// Library facilities used: iostream
{
    for (display.start( ); display.is_item( ); display.advance( ))
        cout << display.current( ) << endl;
}

double get_number( )
// Library facilities used: iostream
{
    double result;
    
    cout << "Please enter a real number for the sorted_sequence: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
