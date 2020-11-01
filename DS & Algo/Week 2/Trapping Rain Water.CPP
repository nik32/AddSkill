class Solution {
public:
    int min(int n1, int n2)
    {    return n1 > n2 ? n2 : n1 ;  }
    
    int trap(vector<int>& height) {
        int size = height.size();
        if(!size)
            return 0;
        
        /*  r_max[i] - gives max height among all the right side towers of tower i
            l_max[i] - gives max height among all the left side towers of tower i
        */
        
        int r_max[size], l_max[size], ans = 0, i, min_h;//this is laater because have variable lenght array bound we need some positive value (i.e. > 0) and if size = 0 then there will be error
        
        for(i = 0 ; i < size ; i++)// initializes values to 0
            r_max[i] = l_max[i] = 0;
        l_max[0] = height[0], r_max[size-1] = height[size-1];//explicitly initialized coz l_max at indx will be height of that tower and same for the r_max as there are no towers to their left or right
        
        for(i = size - 2 ; i >= 0 ; i--)
            r_max[i] = height[i] > r_max[i+1] ? height[i] : r_max[i+1];
        
        for(i = 1 ; i < size; i++)
            l_max[i] = height[i] > l_max[i-1] ? height[i] : l_max[i-1];
        
        for(i = 1; i < size - 1 ; i++)
            if((min_h = min(l_max[i], r_max[i]) - height[i]) /*formula*/ > 0 )
                ans += min_h; 
        
        return ans;
    }
};
