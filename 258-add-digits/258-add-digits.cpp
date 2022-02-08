class Solution {
public:
    
    int findSum(int num, int sum){
        if(num > 0){
            sum += num%10;
            num /= 10;
            return findSum(num, sum);
        }
        
        if(sum > 9){
            return findSum(sum, 0);
        }
        return sum;
    }
    
    int addDigits(int num) {
        return findSum(num, 0);
    }
};