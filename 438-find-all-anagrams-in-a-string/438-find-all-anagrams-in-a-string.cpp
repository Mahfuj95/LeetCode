class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
        string str;
        int len = s.size();
        int tgtLen = p.size();
        vector<int> ans;
        
        map<char, int> tMap;
        map<char, int> cMap;
        
        for(int i = 0; i<tgtLen; i++){
            tMap[p[i]]++;
        }
        
        for(int i = 0; i<len; i++){
            cMap[s[i]]++;
            if(i+1 >= tgtLen){
                
                bool flag = true;
                for(int j = 0; j<26; j++){
                    char tgt = 'a' + j;
                    if(cMap[tgt] < tMap[tgt]){
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    ans.push_back(i-(tgtLen-1));
                }
                cMap[s[i-(tgtLen-1)]]--;
            }
            
        }
        return ans;
    }
};