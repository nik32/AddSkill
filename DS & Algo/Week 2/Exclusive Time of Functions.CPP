class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack< pair<int, int> > calls;
        string str, str2;
        int id;
        long t, time_execu = 0;
        char status;
        
        for(int i = 0 ; i < logs.size() ; i++)
        {
            stringstream s(logs[i]), x;
            s >> id;
            s >> str;
            status = str[1];
            x << str;
            while(getline(x, str2, ':'))
              if(stringstream(str2) >> t)
                    break;
            
            if(!calls.empty())
            {
                pair<int, int> last_id = calls.top();
                ans[last_id.first] += t - last_id.second + ((status == 'e') ? 1 : 0);
            }
            if(status == 's')
                calls.push(make_pair(id, t));
            else
            {
                calls.pop();
                if(!calls.empty())
                {
                    pair<int, int> last_id = calls.top();
                    calls.pop();
                    last_id.second = t + 1;
                    calls.push(last_id);
                }
            }
        }
        return ans;
    }
};
