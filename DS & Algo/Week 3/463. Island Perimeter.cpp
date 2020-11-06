//This can also be optimised because the cell[] space is not required.
​
/*The logic is - 
    1) you first mark all the grids in a 1-D array. 
    2) Then for each cell (let's say i), if it is a land, you just use the conditions to find -
    "which side of the cell (out of up, down, left right) has water next to it (becuase if there is water then that side of the cell(i) is at corner and will be considered for perimeter)"
*/
​
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cell[10010] = {0}, i, j, cell_cnt = 0, ans = 0, row = grid.size(), col = grid[0].size();
        for(i = 0 ; i < row; i++)
            for(j = 0 ; j < col ; j++)
                cell[cell_cnt++] = grid[i][j];
        
        for(i = 0 ; i < cell_cnt ; i++)
        {
            if(!cell[i])//if cell if filled with water we don't need to check only
                continue;
            
            //In all the conditions below - 1st condition (and 2nd when there are 3 conditions) is for checking the edge cells which are implicitly surrounded by water. And 2nd condtion for non edge cells, and to check if it is surrounded with a cell with land or water 
            if(i % col == 0 || i - 1 < 0 || !cell[i-1])//conditions for left side
                ans++;//this i % col condition is needed for case like [[1], [1]] in which if we just use i-1 < 0 (which was the only condtion originally to check for cells on edge of grid) then i-1 will not lead us to previous land which will give wrong ans
            if((i+1) % col == 0 || i + 1 >= row * col || !cell[i+1])//conditions for right side
                ans++;//reason for (i+1)%col is same as above
            if(i + col >= row * col || !cell[i + col] ) //conditions for down side
                ans++;
            if(i - col < 0 || !cell[i - col])//conditions for up side
                ans++;
