#include "note.h"
#include <iostream>
#include <cmath>
#include <assert.h>

void musical_note::set_length(note_length a){
    len = a;
}

void musical_note::set_value(int a){
    assert(a >= -9 && a <= 2);
    val = a;
}

void musical_note::get_note_info(){
    std::cout << "*********Musical Note Info**********" << std::endl;
    std::cout << "Musical Note Length: ";
    switch(len){
        case six_teenth:
            std::cout << "six_teenth" << std::endl;
            break;
        case eighth:
            std::cout << "eighth" << std::endl;
            break;
        case quarter:
            std::cout << "quarter" << std::endl;
            break;
        case half:
            std::cout << "half" << std::endl;
            break;
        case whole:
            std::cout << "whole" << std::endl;
            break;
        default:
            std::cout << "Unknownor occurred!" << std::endl;
    }
    std::cout << "Musical Note Number: " << val << std::endl;
    std::cout << "Musical Note Type: ";
    switch(val){//可以考虑使用map容器
        case -9:
            std::cout << "C" << std::endl;
            break;
        case -8:
            std::cout << "C#" << std::endl;
            break;
        case -7:
            std::cout << "D" << std::endl;
            break;
        case -6:
            std::cout << "C#" << std::endl;
            break;
        case -5:
            std::cout << "E" << std::endl;
            break;
        case -4:
            std::cout << "F" << std::endl;
            break;
        case -3:
            std::cout << "F#" << std::endl;
            break;
        case -2:
            std::cout << "G" << std::endl;
            break;
        case -1:
            std::cout << "G#" << std::endl;
            break;
        case 0:
            std::cout << "A" << std::endl;
            break;
        case 1:
            std::cout << "A#" << std::endl;
            break;
        case 2:
            std::cout << "B" << std::endl;
            break;
        default:
            std::cout << "Unknownor occurred!" << std::endl;
    }
    std::cout << "Musical Note Frequency: " << note_frequency() << std::endl;
}

double musical_note::note_frequency(){
    double tmp = (double)val;
    return 440 * (pow(2, (tmp / 12)));
}