class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1, p2;
        p1 = p2 = 0;
        
        int p1len = nums1.size();
        int p2len = nums2.size();
        int total = p1len + p2len;
        
        int i = 0;
        int curNum = 0;
        double sum = 0;
        while(true){
            if(p1 >= p1len && p2 >= p2len) break;
            
            i++;
            if(p2 >= p2len || (p1 < p1len && nums1[p1] < nums2[p2])){
                curNum = nums1[p1];
                p1 ++;
            }else{
                curNum = nums2[p2];
                p2 ++;
            }
            
            if(total%2 == 0 && i == total/2){
                sum += curNum;    
            }else if(i == ((total/2) + 1)){
                sum += curNum;
                break;
            }
            
        }
        
        if(total%2 == 0) return sum/2;
        return sum;
    }
};