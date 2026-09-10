class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftrow(n,0), upperD(2*n-1,0), lowerD(2*n-1,0); 
        solve(0,board, ans,leftrow, upperD, lowerD,n);
        return ans;
    }
    void solve(int col,vector<string>& board, vector<vector<string>>& ans, vector<int>& leftrow, vector<int>& upperD, vector<int>& lowerD, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerD[row+col]==0 && upperD[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerD[row+col]=1;
                upperD[n-1+col-row]=1;
                solve(col+1, board,ans, leftrow, upperD, lowerD,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerD[row+col]=0;
                upperD[n-1+col-row]=0;
            }
        }
    }
};