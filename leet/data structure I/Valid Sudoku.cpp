class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool ans= true;
        
        //EACH ROW
        vector<char> row;
        for(int i=0; i<9; i++)
        {
            int index = -1;
            row = board[i];
            sort(row.begin(), row.end());
            
            //check index at which '.' end
            for(int j=0; j<9; j++)
            {
                if(row[j] != '.')
                {
                    index = j;
                    break;
                }
            }
            if(index == -1)
            {
                continue;
            }
            
            //check for duplicates
            for(int j=index; j<8; j++)
            {
                if(row[j] == row[j+1])
                {
                    return false;
                }
            }            
        }
        
        //EACH COLUMN
        //make col empty at end of loop
        vector<char> col;
        for(int i=0; i<9; i++)
        {
            //adding column to col
            for(int j=0; j<9; j++)
            {
                if(board[j][i] != '.')
                {
                    col.push_back(board[j][i]);
                }
            }
            
            if(col.size()==0)
            {
                continue;
            }
            
            sort(col.begin(), col.end());
            
            //checking for duplicates
            for(int j=0; j<col.size()-1; j++)
            {
                if(col[j] == col[j+1])
                {
                    return false;
                }
            }
            col = {};
        }
        
        //EACH BOX
        vector<char> box;
        int k =0;
        int l =0;
        for(int i=0; i<9; i++)
        {
            //adding elements to box
            for(int j=0; j<9; j++)
            {
                if(board[k][l] != '.')
                {
                    box.push_back(board[k][l]);
                }
                l += 1;
                if(j==2 || j==5 || j==8)
                {
                    l = l-3;
                    k+=1;
                }
            }
            if(k>8)
            {
                k = 0;
                l += 3;
            }
            
            if(box.size()==0)
            {
                continue;
            }
            
            sort(box.begin(),box.end());
            
            //checking for duplicates
            for(int j=0; j<box.size()-1;j++)
            {
                if (box[j]==box[j+1])
                {
                    return false;
                }
            }       
            box = {};
        }
        return ans;   
        
    }
};
