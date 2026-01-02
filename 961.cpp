class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int>arr(10001,0);
        for(int i=0;i<nums.size();i++){
            if(arr[nums[i]]>0){
                return nums[i];
            }
            arr[nums[i]]++;
        }
        return -1;
    }
};