//  Problem statement

// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
// For Example :

// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.





#include <bits/stdc++.h> 
bool f(int ind, int target, vector<int> &arr,vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(ind ==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool NotTake=f(ind-1,target, arr,dp);
    bool take=false;
    if(arr[ind]<=target) 
    take=f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]= take|NotTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool> (k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool NotTake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target) 
            take=dp[ind-1][target-arr[ind]];
            dp[ind][target]= take|NotTake;
        }
    }
    return dp[n-1][k];
}