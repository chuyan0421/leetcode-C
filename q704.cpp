#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // cout << "search" << endl;
        // cout << nums.size() << endl;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            // int除法，直接取整
            int mid = (right + left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid -1;
            }else{
                return mid;
            }
        }
        cout << "cann't find target" << endl;
        return -1;
        
    };
};


int main(int argc, char *argv[]){
    vector<int> nums ;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);
    int target = 7;

    Solution s = Solution();
    int resutlt = s.search(nums,target);
    cout << resutlt << endl;


}