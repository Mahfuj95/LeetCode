class Solution {
public:
    int findDest(vector<vector<int>> &grid, int ball){
        int pX = 0, pY = ball;
        while(pX < grid.size() && pY < grid[0].size()){
            int nY = pY + grid[pX][pY];
            if(nY < 0 || nY >= grid[0].size()) return -1;
            if(grid[pX][pY] != grid[pX][nY]) return -1;
            
            pX ++;
            pY = nY;
        }
        return pY;
    }
    
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i = 0; i<grid[0].size(); i++){
            ans.push_back(findDest(grid, i));
        }
        
        return ans;
    }
};