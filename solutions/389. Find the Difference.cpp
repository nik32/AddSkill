class Solution {
public:
    char findTheDifference(string s, string t) {
        int i, freq_s[26] = {0}, freq_t[26] = {0}, len = s.length();
        
        for(i = 0; i < len ; i++)
            freq_s[s[i] - 'a']++;
        
        for(i = 0; i <= len ; i++)
            freq_t[t[i] - 'a']++;
        
        for(i = 0 ; i < 26 ; i++)
            if(freq_t[i] != freq_s[i])
                break;
        
        return 'a' + i;
    }
};
