# include <stdio.h>
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        int flag = 0;
        for(int i =1;i<nums.size();i++){
            if(nums[flag] != nums[i]){
                flag++;
                nums[flag] = nums[i];
            }
            
        }
        flag++;
        return flag;


    }
};

int main(){

    vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(2);
    // test = [1,1,2];

    // int test[3] = {1,1,2};


    Solution s = Solution();
    // vector<int> &ref_test = test;
    int result = s.removeDuplicates(test);
    cout << result << endl;

}