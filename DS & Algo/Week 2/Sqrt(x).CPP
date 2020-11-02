class Solution {
public:
    int mySqrt(int x) {        
        unsigned long i, mid, l= 0, r = (x/2)+1;
        
        while(l <=r)
        {
            mid = (l+r)/2;
            if(mid < 100000 && mid * mid == x)//checked mid < 100000 to avoid overflow. You can choose a way smaller number. This was just an assured upper bound with whihc we can be assured of right ans.
                return mid;
            else if(mid >= 100000 || mid * mid > x)//if mid > 100000 then we are sure our ans is less than mid 
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(mid * mid < x)
            return mid;
        else
            return mid - 1;
            
    }
};
