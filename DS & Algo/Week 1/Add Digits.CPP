class Solution {
public:
    int addDigits(int num) {
        int n = num, sum;
        while(n > 9)
        {
            sum = 0;
            while(n != 0)
            {
                int rem = n % 10;
                sum+=rem;
                n /= 10;
            }
            n = sum;
        }
        return n;
    }
};
