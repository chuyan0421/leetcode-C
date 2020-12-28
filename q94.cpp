// 给定一个二叉树，返回它的中序遍历

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x){
         this->val = x;
         this->left = NULL;
         this->right = NULL;

     }
 };
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> r; 
        TreeNode *current = root;
        while(current != NULL || !s.empty() ){
            while(current != NULL){

                // 走到最左节点
                cout << "to left" << endl;
                s.push(current);
                current = current->left;
            }
            if(!s.empty()){
                current = s.top();
                s.pop();
                r.push_back(current->val);               
                current = current->right;                             
            }
        }
        return r;

        
    }
};

int main(int argc, char *argv[]){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    a->right = b;
    b->left = c;
    cout << a->val << endl;
    
    Solution s = Solution();
    vector<int> result = s.inorderTraversal(a);
    cout << result[0] << endl;
    cout << result[1] << endl;
    cout << result[2] << endl;


}