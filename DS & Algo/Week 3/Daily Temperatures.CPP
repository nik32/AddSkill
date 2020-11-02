class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int s = temps.size();
        vector<int> ans(s, 0);
        stack< pair<short,int> > temp_not_found;
        temp_not_found.push(make_pair(temps[0], 0));
        for(int i = 1 ; i < s ; i++)
        {
            while(!temp_not_found.empty())
            {
                pair<short, int> temp = temp_not_found.top();
                if(temp.first < temps[i])
                {
                    ans[temp.second] = i - temp.second;
                    temp_not_found.pop();
                }
                else
                    break;
            }
            temp_not_found.push(make_pair(temps[i], i));
        }
        return ans;
    }
};
