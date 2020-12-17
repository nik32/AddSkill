//recodrd this for the string processing functions learnt - like find(), n_pos, strtok, size_ etc
//like - https://www.geeksforgeeks.org/string-find-in-cpp/
//https://youtu.be/bXkWuUe9V2I
//http://www.cplusplus.com/reference/string/string/find/
//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
​
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
​
        unordered_map<string, int> dom_counts;
        vector<string> ans;
        string dom_name, str;
        int i, count;
        size_t pos;
        
        for(i = 0 ; i < cpdomains.size() ; i++)
        {
            str = cpdomains[i].substr(0, cpdomains[i].find(" "));
            count = stoi(str);
            
            dom_name = cpdomains[i].substr(cpdomains[i].find(" ") + 1);
            
            if(dom_counts.find(dom_name) == dom_counts.end())
                dom_counts.insert(make_pair(dom_name, 0));
            dom_counts[dom_name] += count;
            
            for(pos = dom_name.find(".") ; pos != string::npos ; pos = dom_name.find("."))
            {
                dom_name = dom_name.substr(pos + 1);
                if(dom_counts.find(dom_name) == dom_counts.end())
                    dom_counts.insert(make_pair(dom_name, count));
                else
                    dom_counts[dom_name] += count; 
            }
        }
        
        for(unordered_map<string, int>::iterator itr = dom_counts.begin() ; itr != dom_counts.end() ; itr++)
            ans.push_back(to_string(itr->second) + " " + itr->first);
        
        return ans;
    }
};
