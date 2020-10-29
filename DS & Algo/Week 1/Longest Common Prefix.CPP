class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, len = strs.size(), pal_len = 0;
        if(!len)
            return "";
        while(1)
        {
            char c = strs[0][pal_len];
            for(i = 0 ; i < len ; i++)
                if(strs[i].length() == pal_len || c != strs[i][pal_len])
                    return pal_len ? strs[0].substr(0, pal_len) : "";
            pal_len++;
        }
    }
};
