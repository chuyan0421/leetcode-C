// 两数相加
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例：
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

#include <stdio.h>
#include <string> 
#include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = (l1->val + l2->val)%10;
        int carry = (l1->val + l2->val)/10;
        ListNode * result = new ListNode(sum);
       
        ListNode * result_flag = result;
        ListNode * l1_flag = l1;
        ListNode * l2_flag = l2;

        while(l1_flag->next || l2_flag->next ){

            if(l1_flag->next && l2_flag->next){
                l1_flag = l1_flag->next;
                l2_flag = l2_flag->next;
                sum = (carry + l1_flag->val + l2_flag->val)%10;
                carry = (carry + l1_flag->val + l2_flag->val)/10;
            }else if(!l1_flag->next && l2_flag->next){
                cout << "l1_flag is null" << endl;

                l2_flag = l2_flag->next;
                sum = (carry  + l2_flag->val)%10;
                carry = (carry + l2_flag->val)/10;

            }else if(l1_flag->next && !l2_flag->next){
                cout << "l2_flag is null" << endl;
                l1_flag = l1_flag->next;
                sum = (carry  + l1_flag->val)%10;
                carry = (carry + l1_flag->val)/10;
            }else{
                sum = 0;
                carry = 0;
            }
            result_flag->next = new ListNode(sum);
            result_flag = result_flag->next;        
            
        }
        if (carry != 0){
            result_flag->next = new ListNode(carry);
        }

        return result;

                
    }
};


int main(int argc, char *argv[]){
    ListNode * a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);

    ListNode * b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);

    Solution s = Solution();

    ListNode * c = s.addTwoNumbers(a, b);

    cout << (c->val) << endl;
    cout << (c->next->val) << endl;
    cout << (c->next->next->val) << endl;
    cout << (c->next->next->next) << endl;

}


