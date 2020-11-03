
/*The idea is similar to find all anagrams in the sense that in this also you are comparing the frequency arrays of the strings, but the implementation of doing change - 
    1. In this instead of comparing the freq array directly using loops. You are making a string of the array (so that it could be stored in hash as key and could be found in O(1)). Beware while writing the array to string conversion functions! read comments to understand more.
    2. Now you simply see if the string (representing frequency array) is in the hashmap. If present then the actual input string has to be inserted in the map corresponding to its freq arra string
    */

class Solution {
public:
    string convertToString(int *freq_arr)
    {
        string ans = "";
        for(int i = 0 ; i < 26 ; i++)
            ans = ans + to_string(freq_arr[i]) + "-";//you add the '-' at the end to make the string identical to arr which, if not done, can lead problems in case like -  ["abbbbbbbbbbb", "aaaaaaaaaaab"]
        return ans;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> same_ana;//will store the {key(the string representing freq of a group of anagrams) : value(all the strings, which have freq arr same as key, and are thus anagrams)
        vector< vector<string> > ans;
        string str_i_freq;
        int freq_arr[26];
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            for(int t = 0 ; t < 26 ; t++)//initialize freq_arr to zero
                freq_arr[t] = 0;
            
            for(int j = 0 ; j < strs[i].length() ; j++)//counting frequency
                freq_arr[strs[i][j] - 'a']++;
            
            str_i_freq = convertToString(freq_arr);
            
            if(same_ana.find(str_i_freq) == same_ana.end())//if the freq_str is not found in map
                same_ana.insert(make_pair(str_i_freq, vector<string> ()));//then add it to map
            same_ana[str_i_freq].push_back(strs[i]);//add the actual string (whihc has the freq arr same as str_i_freq) in the vector    
        }
        
        for(unordered_map<string, vector<string> >::iterator itr = same_ana.begin(); itr != same_ana.end() ; itr++)
            ans.push_back(itr->second);
        
        return ans;
    }
};
