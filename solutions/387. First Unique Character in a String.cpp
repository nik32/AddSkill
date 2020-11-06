class Solution {
public:
    int firstUniqChar(string s) {
        int freq_s[26] = {0}, occ_in_s[26], min_indx = 1000000, i;
        for(i = 0 ; i < 26 ; i++)
            occ_in_s[i] = -1;
        
        for(i = 0 ; i < s.size() ; i++)
        {
            freq_s[s[i] - 'a']++;
            if(occ_in_s[s[i] - 'a'] == -1)
                occ_in_s[s[i] - 'a'] = i;
        }
        
        for(i = 0 ; i < 26 ; i++)
            if(freq_s[i] == 1)
                min_indx = occ_in_s[i] < min_indx ? occ_in_s[i] : min_indx;
        
        return min_indx == 1000000 ? -1 : min_indx;
    }
};
