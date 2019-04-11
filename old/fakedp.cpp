#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

string ltos(unsigned long i);

int main(int argc, char const *argv[])
{
    std::cout << "It is a fake data process program." << std::endl;
    FILE *fout;
    fout = fopen("b.txt", "w+");
    //char * a = "89:ac:7a:0d:65:0b";
    //int b = 2;
    unsigned long c = 100034143;
    //string tmp = "hello world:" + string(a);
    // string tmp = "hello world:" + to_string(c);
    // string tmp = "hello world:" + itos(b);
    string tmp = "hello world:" + ltos(c);
    cout << tmp << endl;
    tmp.append("\n");
    cout << tmp << endl;
    printf("%s", tmp.c_str());
    fputs(tmp.c_str(), fout);
    fclose(fout);
    return 0;
}
//拉的翼神龙 the sun god of dragon
string ltos(unsigned long i){
    ostringstream os;
    os << i;
    string result;
    istringstream is(os.str());
    is >> result;
    return result;
}

    // string itos(int i)  
    // {  
    //     ostringstream os;  
    //     os<<i;  
    //     string result;  
    //     istringstream is(os.str());  
    //     is>>result;  
    //     return result;  
      
    // }  