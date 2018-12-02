#include <iostream>
// #include <string>
#include <vector>
#include <math.h>
#include <assert.h>

using namespace std;

int reverse(int);

int main(void){
    cout << reverse(-1563847412) << endl;;
	return 0;
}

int reverse(int x){
    vector<int> nList;
    int res = 0;
    bool isP;
    int n = 0;
    if(x == 0) return x;
    if(x > 0) {
        isP = true;
    } else {
        isP = false;
        x = -x;
    }
    while(x > 0){
        nList.push_back(x % 10);
        x = x/10;
        n++;
    }
    int k = 0;
    while(k < n){
        res = res + pow(10, k) * nList[n - 1 -k];
        assert((res > 0 && isP) || (res < 0 && !isP));
        k++;
    }
    if(isP && res < 0) return 0;
    if(!isP) return -res;
    return res;
}