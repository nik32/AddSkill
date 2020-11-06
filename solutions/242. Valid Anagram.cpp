class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq_s[26] = {0}, freq_t[26] = {0}, i;
        
        for(i = 0 ; i < s.size() ; i++)
            freq_s[s[i] - 'a']++;
        
        for(i = 0 ; i < t.size() ; i++)
            freq_t[t[i] - 'a']++;
        
        for(i = 0 ; i < 26 ; i++)
            if(freq_s[i] != freq_t[i])
                return 0;
        
        return 1;
    }
};
