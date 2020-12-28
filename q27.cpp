# include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first_valid = 0;
        int i,temp;
        for(i=0;i<nums.size();i++){
            if(nums[i] != val){
                first_valid++;
                temp = nums[i];
                nums[first_valid-1] = temp;
            }
        }
        return first_valid;

    }
};