#include<bits/stdc++.h>
using namespace std;

class Sudoku{
public:
    bool solver_algo(vector<vector<char>>& board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board,ch,i,j)){
                            board[i][j] = ch;
                            if(solver_algo(board)) 
                            return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char>> &board,char ch,int row,int col){
         for(int i=0; i<9; i++){
            if(board[i][col] == ch ||
             board[row][i] == ch ||
             board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }
    void printSudoku(vector<vector<char>>& sudoku) {
    int n = sudoku.size();
    
    // Print the top border
    for (int i = 1; i < n; ++i) {
        cout << " - ";
    }
    cout << "\n";
    
    // Print the Sudoku grid with borders
    for (int i = 0; i < n; ++i) {
        cout << "| ";
        for (int j = 0; j < n; ++j) {
            cout << sudoku[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << "| ";
            }
        }
        cout << "\n";
        
        if ((i + 1) % 3 == 0 && i != n - 1) {
            for (int i = 1; i < n; ++i) {
                cout << " - ";
            }
            cout << "\n";
        }
    }
    
    // Print the bottom border
     for (int i = 1; i < n; ++i) {
        cout << " - ";
    }
    cout << "\n";
}
    void solveSudoku(vector<vector<char>>& board) {
        solver_algo(board);
        printSudoku(board);
    }
};

int main(){
    vector<vector<char>> board(9,vector<char>(9,'.'));
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Read the matrix from the file
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!(inputFile >> board[i][j])) {
                std::cerr << "Error reading the matrix from the file." << std::endl;
                inputFile.close();
                return 1;
            }
        }
    }

    // Close the input file
    inputFile.close();
    Sudoku s;
    s.solveSudoku(board);
    return 0;
}

