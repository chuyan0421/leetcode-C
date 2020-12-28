// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

// 示例 1:

// 输入: 123
// 输出: 321
//  示例 2:

// 输入: -123
// 输出: -321
// 示例 3:

// 输入: 120
// 输出: 21

#include <stdio.h>
#include <limits.h>
#include <string> 
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = x;
        int result = 0;

        while (temp != 0){
            if ((result > INT_MAX/10) || (result == INT_MAX/10 && temp % 10 > 7)){
                return 0;
            }

            if ((result < INT_MIN/10) || (result == INT_MIN/10 && temp % 10 < -8)){
                return 0;
            }

            result = result * 10 + temp % 10;
            temp = temp / 10;           
        }
        return result;
    }

};

int main(int argc, char *argv[]){
    Solution s;

    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    s.reverse(123456);
    s.reverse(-123);
    s.reverse(120);
}