//This can be space optimised by using a bitmap instead of 2-D array.
​
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_valid[10][10] = {0}, col_valid[10][10] = {0}, box_valid[9][10] = {0}, i, j, rows = board.size(), cols = board[0].size(), box_cnt = 0, box_cnt2;
        
        for(i = 0 ; i < rows ; i++, box_cnt2 = 0)
        {
            if(i % 3 == 0)
                box_cnt = (i / 3) * 3;
            for(j = 0 ; j < cols ; j++)
            {
                if(j % 3 == 0)
                    box_cnt2 = box_cnt + (j / 3);
                if(board[i][j] == '.')
                    continue;
                if(row_valid[i][board[i][j] - '0'] || col_valid[j][board[i][j] - '0'] || box_valid[box_cnt2][board[i][j] - '0'])
                    return 0;
                row_valid[i][board[i][j] - '0']++, col_valid[j][board[i][j] - '0']++, box_valid[box_cnt2][board[i][j] - '0']++;
            }
        }
        
        return 1;
    }
};
