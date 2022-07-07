class Solution {
public:
    int dp[105][105];
    
    int findSoln(string &s1, string &s2, string &s3, int j, int k){
        int res = 0;
        
        if(dp[j][k] != -1) return dp[j][k];
        
        int i = j+k;
        
        if(i >= s3.size()) return 1;
        if(j < s1.size() && s3[i] == s1[j]){
            res = res | findSoln(s1, s2, s3, j+1, k);
        }
        if(k < s2.size() && s3[i] == s2[k]){
            res = res | findSoln(s1, s2, s3, j, k+1);
        }
        dp[j][k] = res;
        return res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        if(s1.size() + s2.size() != s3.size()) return false;
        
        return findSoln(s1, s2, s3, 0, 0);
    }
};