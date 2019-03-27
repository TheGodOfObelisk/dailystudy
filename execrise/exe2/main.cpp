#include <iostream>
#include "note.h"

int main(){
    musical_note test;
    test.get_note_info();
    std::cout << "update it......" << std::endl;
    test.set_length(whole);
    test.set_value(-1);
    test.get_note_info();
}