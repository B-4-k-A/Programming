class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
	    int sum = 0;
        for(auto i : nums) {
            sum += i;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }

};