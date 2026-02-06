class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        long long int i = 0;
        long long int j = nums.size() - 1;

        long long int minval = 100000000000000000;

        while ((long long int)nums[i] * k < nums[j])
        {
            i++;
        }
        minval = i;

        while (j > 0 && i >= 0)
        {

            j--;

            while (i >= 0 && ((long long int)nums[i] * k >= nums[j]))
                i--;
            i++;
            minval = fmin(minval, nums.size() - (j - i + 1));
        }

        return minval;
    }
};