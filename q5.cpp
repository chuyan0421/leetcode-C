# include <stdio.h>
# include <iostream>
# include <vector>
# include <math.h>


using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length_s = s.length();
        // vector<vector<int> > DP;
        vector<vector<int>> DP(length_s, vector<int>(length_s));
        vector<int> a;
        int i,j;
        int max_length=0;
        int flag_l=0;
        int flag_r=0;

        if(length_s == 0){
            return 0;
        }
        if(length_s == 1){
            return s;
        }

       
        // for(i=0;i<length_s;i++){
        //     for(j=0;j<length_s;j++){
        //         a.push_back(false);
        //     }
        //     DP.push_back(a);
        //     a.clear();
        // }

        for(i=0;i<length_s;i++){
            for(j=0;j<i+1;j++){
                // cout << j << endl;
                // cout << i << endl;

                if(j==i){
                    DP[j][i] = 1;                   
                }else if(j==i-1){
                    DP[j][i] = (s[j]==s[i]);
                    // cout << DP[1][2] << endl;

                }else{
                    DP[j][i] = DP[j+1][i-1] & (s[j]==s[i]);

                }
                if((DP[j][i]==1)&((i-j+1) > max_length)){
                    flag_l = j;
                    flag_r = i;
                    max_length = (i-j+1);
                }
                // cout << "---------------" << endl;
            }
        }
        // cout << DP[1][2] << endl;
        
        return s.substr(flag_l,max_length);


    }
};


int main(){
    Solution s = Solution();
    // cout << s.longestPalindrome("a") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;

}