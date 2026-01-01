class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        if(nums.size()==3)return max(nums[1],nums[0]+nums[2]);
        vector<int> dp={nums[0],max(nums[0],nums[1])};
        int sum1;int sum2;
        for(int i=2; i<nums.size();i++){
            dp.push_back(max(nums[i]+dp[i-2],dp[i-1]));
        }
        // for(int i=0; i<dp.size();i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        return max(dp[dp.size()-1],dp[dp.size()-2]);
    }
};