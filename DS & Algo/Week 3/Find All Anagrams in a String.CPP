/*Complexity of this solution is O(26s) whihc is O(s) where s = size of string s.
This is because complexity of anagram() is O(26) whihc is O(1) and we are calling it s-p-1 times which becomes O(s). 
*/
class Solution {
public:
    bool anagram(int *freq_s_sub, int *freq_p)
    {
        bool ans = 1;
        for(int i = 0 ; i < 26 && ans ; i++)
            if(freq_p[i] != freq_s_sub[i])
                ans = 0;
        return ans;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int i, len_p = p.length(), len_s = s.length(), freq_s_sub[26] = {0}, freq_p[26] = {0}, flag = 1;
        vector<int> ans;
        
        if(len_s < len_p)
            return ans;
        
        for(i = 0 ; i < len_p ; i++)
        {
            freq_s_sub[s[i] - 'a']++;
            freq_p[p[i] - 'a']++;
        }
        
        if(anagram(freq_s_sub, freq_p))    
            ans.push_back(i - len_p);
        
        for(int i = len_p ; i < len_s ; i++)
        {
            freq_s_sub[s[i - len_p] - 'a']--;
            freq_s_sub[s[i] - 'a']++;
            
            if(anagram(freq_s_sub, freq_p))    
                ans.push_back(i - len_p + 1);
        }
        
        return ans;
    }
};
