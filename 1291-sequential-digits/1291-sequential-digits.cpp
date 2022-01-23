class Solution {
public:
    vector<int> findAns(int low, int high){
        vector<int> v;
        vector<int> ans;
        v.push_back(0);
        
        for(int i=1; i<9; i++){
            v.push_back(i);
        }
        
        int inc = 1;
        while(inc < 10){
            for(int i = 1; i<9-(inc-1); i++){
                v[i] = v[i] * 10;
                v[i] = v[i]+i+inc;
                
                if(v[i] >= low && v[i] <= high){
                    ans.push_back(v[i]);    
                }
            }
            inc ++;   
        }
        return ans;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        return findAns(low, high);        
    }
};