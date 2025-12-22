class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check squares first
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (!isValidSquare(board, i*3, j*3)) 
                    return false;
            }
        }

        // Check for rows
        for (int i=0; i<9; i++)
            if (!isValidRow(board, i)) return false;

        // Check for cols
        for (int i=0; i<9; i++)
            if (!isValidCol(board, i)) return false;

        return true;
    }
private:
    bool isValidSquare(vector<vector<char>>& board, int i, int j) {
        bool cache[10];
        memset(cache, false, sizeof(cache));
        for (int k=0; k<3; k++) {
            for (int l=0; l<3; l++) {
                int num = board[i+k][j+l] - '0';
                if (1 <= num && num <= 9) {
                    if (cache[num]) return false;
                    cache[num] = true;
                }
            }
        }
        return true;
    }
    bool isValidRow(vector<vector<char>>& board, int row) {
        bool cache[10];
        memset(cache, false, sizeof(cache));
        for (int i=0; i<9; i++) {
            int num = board[row][i] - '0';
            if (1 <= num && num <= 9) {
                if (cache[num]) return false;
                cache[num] = true;
            }
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board, int col) {
        bool cache[10];
        memset(cache, false, sizeof(cache));
        for (int i=0; i<9; i++) {
            int num = board[i][col] - '0';
            if (1 <= num && num <= 9) {
                if (cache[num]) return false;
                cache[num] = true;
            }
        }
        return true;
    }
};

// This is just logic code
// Check the squares first then check the columns and rows
// row first - col second
