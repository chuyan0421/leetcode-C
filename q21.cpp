#include <stdio.h>
#include <iostream>

using namespace std;

//   Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* list_a = new ListNode();
        list_a->next = l1;

        ListNode* list_b =new ListNode();
        list_b->next = l2;

        ListNode* list_result = new ListNode();
        ListNode* list_temp = new ListNode();
        list_temp->next = list_result;
        int val_a, val_b;

        while((list_a->next != nullptr) || (list_b->next != nullptr) ){
            if(list_a->next == nullptr){
                // 如果list_a.next 为空，那么list_temp指向list_b.next->next
                // val_b = list_b->next->val;
                list_temp->next->next = list_b->next;
                break;
            }else if(list_b->next == nullptr){
                // 如果list_b->next 为空，那么list_temp指向list_a->next->next
                // val_a = list_a->next->val;
                list_temp->next->next = list_a->next;
                // list_temp->next = list_temp->next->next;            
                break;
            }else{
                // 如果list_a->next,list_b->next都不为空，则对值进行比较
                val_a = list_a->next->val;
                val_b = list_b->next->val;
                if (val_a <= val_b){

                    list_temp->next->next = list_a->next;
                    list_temp->next = list_temp->next->next;            
                    list_a->next = list_a->next->next;

                }else{
                    list_temp->next->next = list_b->next;
                    list_temp->next = list_temp->next->next;
                    list_b->next = list_b->next->next;
                }
            }

        }
        return list_result->next;
        
    }
};



int main(){
    ListNode* test_a = new ListNode(1);
    test_a->next = new ListNode(2);
    test_a->next->next = new ListNode(3);
    cout << (test_a->val) << endl;
    cout << (test_a->next->val) << endl;
    cout << (test_a->next->next->val) << endl;


}