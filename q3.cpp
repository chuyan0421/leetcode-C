#include <stdio.h>
#include <string> 
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int result_left=0;
        int result_length=1;
        int string_length = s.length();
        int i,j,k,same_flag,temp_length;

        for(i=0;i<string_length;i++){

            same_flag = 0;
            temp_length = 1;
            // 查询j数据与[i,j-1]这个区间的数据是否相同，如果不相同，那么result_left位置不变，result_length加1
            for(j=i+1;j<string_length;j++){
                for (k=i;k<j;k++){                   
                    if(s[k]==s[j]){
                        same_flag = 1;
                        k++;
                        break;
                    }
                }


                cout << i << endl;
                cout << j << endl;
                cout << k-1 << endl;
                cout << same_flag << endl;
                cout << "------------" << endl;

                if(same_flag == 0){
                    if(result_length < j-i+1){                    
                        result_length = j-i+1;
                        result_left = i;                    
                    }

                }else{                   
                    if(result_length < j-i){                    
                        result_length = j-i;
                        result_left = i;                    
                    }

                    // 原本i的新位置为k
                    i = k-1;
                    cout << "break" << endl;
                    break;
                }

            }

        }

        cout << "end of iterator" << endl;
        cout << result_left << endl; 
        cout << result_length << endl;       
        
    }
};

int main(int argc, char *argv[]){
    // cout << "hello world" << endl;
    string a = "abcabcbb";
    // cout << a[0] << endl;
    // cout << a[1] << endl;
    // cout << (a[0] == a[1])<< endl;
    // cout << a.length() << endl;


    Solution s = Solution();
    s.lengthOfLongestSubstring(a);


}