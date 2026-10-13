class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a, int b) {
            return abs(a)<abs(b);
         });
        int s=nums.size();
        int n=s/2;
        long long sum=0;
        for(int x=0;x<n;x++)
        {
            sum-=1LL*nums[x]*nums[x];
        }
        for(int y=n;y<s;y++)
        {
            sum+=1LL*nums[y]*nums[y];
        }
        return sum;
        
    }
};