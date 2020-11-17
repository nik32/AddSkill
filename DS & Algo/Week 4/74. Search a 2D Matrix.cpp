class Solution {
public:
    bool binarySearch(const vector< vector<int> >& matrix, int *l, int r, int target, bool pass, int i)
    {
        int mid, mid_indx;
        while(*l <= r)
        {
            mid_indx = (*l + r) / 2;
            mid = pass ? matrix[i/*pass 1, i = row to search*/][mid_indx] : matrix[mid_indx][i/*in pass 0 i = col to search / rightmost col*/];
            
            if(mid == target)
                return 1;
            else if(mid > target)
                r = mid_indx - 1;
            else
                *l = mid_indx + 1;
        }
        
        //we are here means we couldn't find the position. So we need to find the posioin, where element would have been if it were present 
        if(!pass)//we need the posion only for pass 0
            *l = matrix[mid_indx][i] < target ? mid_indx + 1 : mid_indx;//So we simply check i
        
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size())
            return 0;
        
        int l = 0 , r = matrix.size() - 1, row;
        if(binarySearch(matrix, &l, r, target, 0, matrix[0].size() - 1))//pass 0 means search first the rightmost col
            return 1;
        
        /*if we are still here means we have to do pass 1. In pass 1 we search in the row which we got from pass 0 (row = l). And then we call BinarySearch() for searching the perticular row*/
        row = l;    //cout<<row;
        l = 0; r = matrix[0].size() - 1;
        return row < matrix.size() ? binarySearch(matrix, &l, r, target, 1, row) : 0;//if the row we want to search is more than rows available then it is clear the element is not present and thus return 0
    }
};
