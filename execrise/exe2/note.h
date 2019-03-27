#ifndef NOTE_H
#define NOTE_H

enum note_length {six_teenth, eighth, quarter, half, whole};

class musical_note{
public:
    musical_note(){
        val = -9;
        len = half;
    };
    void set_length(note_length a);
    void set_value(int a);
    void get_note_info();
    double note_frequency();
private:
    int val;
    note_length len;
};

#endif