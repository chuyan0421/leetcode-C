// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:

// 输入: 121
// 输出: true
// 示例 2:

// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 示例 3:

// 输入: 10
// 输出: false
// 解释: 从右向左读, 为 01 。因此它不是一个回文数。


#include <stdio.h>
#include <limits.h>
#include <string> 
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        int temp = x;
        if (x < 0){
            return false;
        }

        int result = 0;

        while (temp != 0){
            if ((result > INT_MAX/10) || (result == INT_MAX/10 && temp % 10 > 7)){
                return false;
            }

            if ((result < INT_MIN/10) || (result == INT_MIN/10 && temp % 10 < -8)){
                return false;
            }

            result = result * 10 + temp % 10;
            temp = temp / 10;           
        }
        if (result == x){
            return true;
        }else{
            return false;
        }


    }
};

int main(int argc, char *argv[]){
    Solution s;


    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(10) << endl;
}


