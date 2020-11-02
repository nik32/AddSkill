class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dup_files;
        vector<vector<string>> ans;
        for(int i = 0 ; i < paths.size() ; i++)
        {
            string files = paths[i], dir, file_and_cont;
            stringstream f(files);
            getline(f, dir, ' ');
            while(getline(f, file_and_cont, ' '))
            {
                string file_name, file_path, cont;
                stringstream fc(file_and_cont); 

                getline(fc, file_name, '(');
                getline(fc, cont, ')');

                file_path = dir + '/' + file_name;
                if(dup_files.find(cont) == dup_files.end())
                    dup_files.insert(make_pair(cont, vector<string> ()));
                dup_files[cont].push_back(file_path);
            }
        }
        for(unordered_map< string, vector<string> >::iterator itr = dup_files.begin() ; itr != dup_files.end() ; itr++)
            if(itr->second.size() > 1)
                ans.push_back(itr->second);
        return ans;
    }
};
