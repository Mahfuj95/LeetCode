class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int temp, cnt = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(i == 0){
                temp = nums[i];
            }
            
            if(nums[i] == temp) cnt ++;
            else cnt--;
            
            if(cnt == 0){
                temp = nums[i];
                cnt++;
            }
        }
        return temp;
    }
};