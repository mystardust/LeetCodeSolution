#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> c(9, unordered_map<int, int>());
        vector<unordered_map<int, int>> r(9, unordered_map<int, int>());
        vector<unordered_map<int, int>> g(9, unordered_map<int, int>());
        char numChar = 0;
        int num = 0;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                numChar = board[i][j];
                if(numChar != '.'){
                    num = numChar - '0';
                    if(++c[i][num]>1) return false;                    
                    if(++r[j][num]>1) return false;
                    if(++g[getGridNum(i,j)][num]>1)return false;
                }
            }
        }
        return true;
    }
    
    inline int getGridNum(int i, int j){
        return (i/3)*3 + j/3;
    }
};