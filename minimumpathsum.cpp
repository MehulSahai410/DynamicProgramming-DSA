class Solution {
public:
    int f(int i,int j, vector<vector<int>> &dp,vector<vector<int>>&Grid)
    {
        if(i==0 && j==0)
        return Grid[0][0];//final jaha pahunche woh return krhe hai
        if(i<0||j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,dp,Grid);
        int left=f(i,j-1,dp,Grid);
        return dp[i][j]=Grid[i][j]+min(up,left);//min sum for the ans
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
        
    }
};