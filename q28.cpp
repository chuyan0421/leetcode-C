# include <stdio.h>
# include "string"
# include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int size_haystack = haystack.size();
        int size_needle = needle.size();

        if(size_needle==0){
            return 0;
        }

        if((size_haystack==0)||(size_haystack<size_needle)){
            return -1;
        }

        int flag = 0;
        for(int i=0;i<(size_haystack-size_needle+1);i++){
            for(int j=0;j<size_needle;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                // cout << haystack[i+j] << endl;
                // cout << needle[j] << endl;
                // cout << "--------------------" << endl;

                if((j==size_needle-1)&&(haystack[i+j]==needle[j])){
                    flag = 1;
                }
            }

            if(flag==1){
                return i;
            }    
                
        }
        return -1;

    }
};


int main(){
    Solution s = Solution();
    cout << s.strStr("abcd","abcd") << endl;
}