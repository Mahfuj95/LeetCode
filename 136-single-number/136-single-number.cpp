class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int len = nums.size();
        
        for(int i=0; i<len; i++){
            if(len == 1 || (i == 0 && nums[i] != nums[i+1])){
                return nums[0];
            }else if(i == len-1 && nums[i] != nums[len-2]){
                return nums[len-1];
            }else if(i > 0 && i < len-1 && nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return 0;
    }
};