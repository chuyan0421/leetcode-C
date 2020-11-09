// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-parentheses


#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length_s = s.length();
        stack<char> stack_s;
        int i = 0;
        char temp ;
        while(i<length_s){
            if(s[i] == '(' || s[i] == '[' || s[i]== '{'){
                stack_s.push(s[i]);
            }else if(s[i] == ')' || s[i] == ']' || s[i]== '}'){
                if(!stack_s.empty()){
                    temp = stack_s.top();
                    stack_s.pop();
                }else{
                    // 如果栈为空，出错，返回false
                    return false;
                }

                if( !((s[i] == ')' && temp =='(') || (s[i] == ']' && temp =='[')  || (s[i] == '}' && temp =='{') )){
                    //如果从栈里出来的字符与当前字符不匹配，则返回错误
                    return false;
                }

            }

            i++;

        }
        if(!stack_s.empty()){
            return false;
        }else{
            return true;
        }

        

    }
};

int main(int argc, char *argv[]){

    Solution s = Solution();

    string a = "())";
    cout << s.isValid(a) << endl;



}
