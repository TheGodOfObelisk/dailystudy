#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows){
    if(numRows == 1) return s;
    if(numRows >= s.length()) return s;
    char t[s.length() + 1] = {0};
    int j = 0, index = 0;
    // if(numRows == 2){
    //     for(int i = 0; 2 * i < s.length(); i++)
    //         t[index++] = s[2 * i];
    //     for(int i = 0; (2 * i + 1) < s.length(); i++)
    //         t[index++] = s[2 * i + 1];
    // }
    while(j < numRows){
        if(j == 0){// the first line
            for(int i = 0; 2*i * (numRows - 1) < s.length(); i++){
                cout << "11 before assignment, the value of index is " << index << endl;
                t[index++] = s[2 * i * (numRows - 1)];
            }
        }
        else if(j == numRows - 1){// the last line
            for(int i = 0; (2 * i + 1) * (numRows - 1) < s.length(); i++){
                cout << "22 before assignment, the value of index is " << index << endl;
                t[index++] = s[(2 * i + 1) * (numRows - 1)];
            }
        }
        else{
            for(int i = 0; (2 * i * (numRows -1) - j) < s.length() || (2 * i * (numRows -1) + j) < s.length(); i++){
                if(((2 * i) * (numRows -1) - j) < s.length() && ((2 * i) * (numRows -1) - j) >= 0){
                    cout << "33 before assignment, the value of index is " << index << endl;
                    t[index++] = s[(2 * i) * (numRows -1) - j];
                }
                if(s[2 * i * (numRows -1) + j] != '\0'){
                    cout << "44 before assignment, the value of index is " << index << endl;
                    t[index++] = s[2 * i * (numRows -1) + j];
                }
            }
        }
        j++;
    }
    return string(t);
}

int main(void){
    string t = "ABCDEFGHIJKLMN";
    string res = convert(t, 4);
    cout << res << endl;
	return 0;
}