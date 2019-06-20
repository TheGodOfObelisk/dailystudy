#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    int i, j, k;
    vector<vector<int> > res;
    vector<int> tmp;
    for(i = 0; i < nums.size(); i++){
        for(j = i+1; j < nums.size(); j++){
            for(k = j+1; k < nums.size(); k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    tmp.push_back(nums[k]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> a;
    a.push_back(-1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(-1);
    a.push_back(-4);
    threeSum(a);
    return 0;
}