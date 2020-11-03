/*

*NOTE - a break_point is when a brick ends and a new brick starts.

LOGIC -
    1. in this I am just calculating - "at which width there are maximum break_points*". 
    2. For the above I am using a map (named break_point) which will store data as follows - {Key(width) : Value(the number of break_points at the width given as key)}
    3. The minimum number of bricks we need to cross will be total num of rows - max num of break points. This is because of all the total rows, we are not crossing a brick at a break_point. And max total num of such break_points is stored in max_bp. So once we remove max_bp from total num of rows we will have the num of row in which we will cross a brick which is our ans.
    
    */
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> break_point;
        int width_sum, i, j, max_bp = 0;
        
        for(i = 0 ; i < wall.size() ; i++)
            for(j = 0, width_sum = 0 ; j < wall[i].size() - 1 ; j++)//size() - 1 because the edge isn't a break point 
            {
                width_sum += wall[i][j];
                if(break_point.find(width_sum) == break_point.end())
                    break_point.insert(make_pair(width_sum, 1));
                else
                    break_point[width_sum]++;
                
                max_bp = break_point[width_sum] > max_bp ? break_point[width_sum] : max_bp;
            }
        
        return wall.size() - max_bp;//3. above
    }
};
