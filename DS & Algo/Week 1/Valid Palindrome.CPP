class Solution {
public:
    bool isNum(char n1, char n2){ return (n1 > 47 && n1 < 58) || (n2 > 47 && n2 < 58);}
    
    bool isNotNumOrAlph(char c) { return (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122);   }
    
    bool isPalindrome(string s) {
        int strt, end = s.length() - 1;
        if(!end)
            return 1;
        
        bool flag = 1;
        for(strt = 0 ; strt < end && flag ; strt++, end--)
        {
            while(strt < end && isNotNumOrAlph(s[strt]))
                strt++;
            while(end >= 0 && isNotNumOrAlph(s[end]))
                end--;
            if(strt >= end)
                break;
            if(s[strt] != s[end] && (abs(s[strt] - s[end]) != 32 || isNum(s[strt],s[end])))
                flag = 0;
        }
        return flag;
    }
};
