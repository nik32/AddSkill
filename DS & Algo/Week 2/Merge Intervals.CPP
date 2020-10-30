  
class Solution {
public:
    static bool comparator(vector<int>& i1, vector<int>& i2)
    {   return i1[0] < i2[0];   }
    
    int max(int n1, int n2) {   return n1 > n2 ? n1 : n2;   }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        
        int i = 0, size = intervals.size();
        vector< vector<int> > ans;
        while(i < size)//Iterate till we exhaust all the intervals
        {
            int j = i + 1;//consider the next interval
            if(j < size && intervals[j][0] <= intervals[i][1])//if we have next interval & it does overlap with our current interval(i) then - (1) merge the intervals & (2)place the merged interval at the next index (to check if it merges with the next and so on) 
            {
                //(1)
                vector<int> merged_interval = {intervals[i][0], max(intervals[i][1], intervals[j][1])}; //This is just for more clarity. Code can be made without this extra vector to save space
                
                //(2)
                intervals[j][0] = merged_interval[0];
                intervals[j][1] = merged_interval[1];
            }
            else //It(interval i) dosen't merge with next interval and thus we can add it in our ans
                ans.push_back({intervals[i][0], intervals[i][1]});
                
            i++;
        }
        return ans;
    }
};
