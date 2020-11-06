class Solution {
public:
    int min(int n1,int n2){     return n1 < n2 ? n1 : n2;   }
    
    vector<string> commonChars(vector<string>& A) {
        int i, j, ans_freq[26] = {0};
        vector<string> ans;
        
        for(i = 0 ; i < A[0].length() ; i++)
            ans_freq[A[0][i] - 'a']++;
        
        for(i = 1 ; i < A.size() ; i++)
        {
            int temp_freq[26] = {0};
            for(j = 0 ; j < A[i].length() ; j++)
                temp_freq[A[i][j] - 'a']++;
           
            for(j = 0 ; j < 26 ; j++)
                ans_freq[j] = min(ans_freq[j], temp_freq[j]);
        }
                     
        for(i = 0 ; i < 26 ; i++)
            while(ans_freq[i]--)
                ans.push_back(string (1, 'a' + i));
        
        return ans;
    }
};
