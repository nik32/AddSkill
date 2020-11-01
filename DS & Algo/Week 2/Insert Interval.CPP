class Solution {
public:
    void insertIntoIntervals(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n = intervals.size();
        intervals.push_back({newInterval[0],newInterval[1]});
        int i = n-1;
        while(i >= 0 && intervals[i][0] > newInterval[0])
        {
            intervals[i+1][0] = intervals[i][0], intervals[i+1][1] = intervals[i][1];
            i--;
        }
        i++;
        intervals[i][0] = newInterval[0], intervals[i][1] = newInterval[1];         
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i, size = intervals.size();
        vector< vector<int> > ans;
        
        insertIntoIntervals(intervals, newInterval);//Just add newInterval into its correct position in sorted intervals. Will take O(n) in worst case.
        size++;
        for(i = 0 ; i < size ; i++)
            printf("[%d, %d], ",intervals[i][0],intervals[i][1]);
        
        i = 0;
        while(i < size)
        {
            int j = i + 1;
            if(j < size && intervals[j][0] <= intervals[i][1]) 
            {
                vector<int> merged_interval = {intervals[i][0], max(intervals[i][1], intervals[j][1])};
                intervals[j][0] = merged_interval[0];
                intervals[j][1] = merged_interval[1];
            }
            else 
                ans.push_back({intervals[i][0], intervals[i][1]});

            i++;
        }
        
        return ans;
        
    }
};
