class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size(), i = 1, last_indx = 0;
        while(i < size)
        {
            while(i < size && nums[last_indx] == nums[i])
                i++;
            if(i >= size)
                break;
            nums[++last_indx] = nums[i];
            i++;
        }
        return size ? last_indx+1 : size;
    }
};
