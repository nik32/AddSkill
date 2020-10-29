class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, size = nums.size(), cnt = 0, ans = 0;
        for(i = 0 ; i < size; i++)
        {
            if(!cnt)
                ans = nums[i];
            if(ans == nums[i])
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};
