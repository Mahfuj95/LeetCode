class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int a = nums[i] + k;
                int u = (upper_bound(nums.begin(), nums.end(), a) - nums.begin())-1;
                if(u != i && nums[u] == a){
                    ans ++;
                }
            }
        }
        return ans;
    }
};