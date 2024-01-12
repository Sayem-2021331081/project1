#include<bits/stdc++.h>
using namespace std;


#define MAX_SIZE 9

vector<vector<int>> readFromFile(const string &fileName) {
    // Create a vector to store the grid
    vector<vector<int>> grid;

    // Open the file
    ifstream inFile(fileName);

    // Check if the file is open
    if (inFile.is_open()) {
        // Read values from the file
        int val;
        while (inFile >> val) {
            // If grid is empty or back vector has 9 elements, add a new vector to grid
            if (grid.empty() || grid.back().size() == 9) {
                grid.push_back(vector<int>());
            }

            // Add the read value to the back vector of grid
            grid.back().push_back(val);
        }

        // Close the file
        inFile.close();
    } else {
        // If file could not be opened, display an error message
        cout << "Unable to open file: " << fileName << endl;
    }

    // Return the grid
    return grid;
}


void printGrid(const vector<vector<int>>& grid, int size) {
    // iterate over grid rows
    for (int i = 0; i < size; i++) {
        // iterate over grid columns
        for (int j = 0; j < size; j++){
          if(grid[i][j] == 0){
            cout<< ". ";
            continue;
          }
            cout << grid[i][j] << " "; // print grid cell value
        }
        cout << endl; // end grid row
    }
}

bool isSafe(const vector<vector<char>>& grid, int row, int col, char num, int size) {
    // Check the number in the same row
    for (int x = 0; x < size; x++)
        if (grid[row][x] == num) return false;

    // Check the number in the same column
    for (int x = 0; x < size; x++)
        if (grid[x][col] == num) return false;

    // Check the number in the same square
    int sqrtSize = sqrt(size);
    int startRow = row - row % sqrtSize;
    int startCol = col - col % sqrtSize;
    for (int i = 0; i < sqrtSize; i++)
        for (int j = 0; j < sqrtSize; j++)
            if (grid[i + startRow][j + startCol] == num) return false;

    // The number is safe
    return true;
}

bool findEmptyPosition(const vector<vector<int>>& grid, int& row, int& col, int size) {
    // Iterate through the grid
    for (row = 0; row < size; row++)
        for (col = 0; col < size; col++)
            // Return true if empty position is found
            if (grid[row][col] == 0)
                return true;
    // Return false if no empty position is found
    return false;
}

bool solveSudoku(vector<vector<char>>& grid, int size) {
    // find an empty cell to fill
    int row, col;
    if (!findEmptyPosition(grid, row, col, size))
        return true; // if no empty cell found, the puzzle is solved

    // iterate through all possible numbers for the current cell
    for (char num = '1'; num <= '9'; num++) {
        // check if the current number is safe to place
        if (isSafe(grid, row, col, num, size)) {
            grid[row][col] = num; // place the current number in the cell

            // recursively solve the rest of the grid
            if (solveSudoku(grid, size))
                return true;

            // undo the current choice if it leads to a dead-end
            grid[row][col] = '.';
        }
    }

    return false; // return false if no solution is found
}



bool isValidRow(vector<vector<int>>problem, vector<vector<int>>board) {
  for(int i = 0;i < 9;i++){
    for(int j = 0;j < 9;j++){
      if(problem[i][j]){
        if(problem[i][j] != board[i][j]) return false;
      }
    }
  }

  // Check each row
  for (int i = 0; i < MAX_SIZE; ++i) {
        unordered_set<int> rowSet;
        for (int j = 0; j < MAX_SIZE; ++j) {
            if (rowSet.find(board[i][j]) != rowSet.end()) {
                return false;  // Duplicate in the row
            }
            rowSet.insert(board[i][j]);
        }
    }

    // Check each column
    for (int j = 0; j < MAX_SIZE; ++j) {
        unordered_set<int> colSet;
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (colSet.find(board[i][j]) != colSet.end()) {
                return false;  // Duplicate in the column
            }
            colSet.insert(board[i][j]);
            
        }
    }

    // Check each 3x3 subgrid
    for (int blockRow = 0; blockRow < 3; ++blockRow) {
        for (int blockCol = 0; blockCol < 3; ++blockCol) {
            unordered_set<int> subgridSet;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int row = blockRow * 3 + i;
                    int col = blockCol * 3 + j;
                    if (subgridSet.find(board[row][col]) != subgridSet.end()) {
                        return false;  // Duplicate in the subgrid
                    }
                    subgridSet.insert(board[row][col]);
                }
            }
        }
    }

    return true;  // No duplicates found
}


int main()
{
  cout << "Do want to play or do you want to submit a puzzle? " << endl;
  cout << "1 (enter 1 if you want to play) " << endl;
  cout << "2 (enter 2 if you want to submit a puzzle) " << endl;
  int n;
  cin >> n;
  if(n == 1){ // playing Mode
    vector<vector<int>> sudoku1 = readFromFile("sudoku1.txt");

    vector<vector<int>> sudoku2 = readFromFile("sudoku2.txt");

    vector<vector<int>> sudoku3 = readFromFile("sudoku3.txt");

    vector<vector<int>> sudoku4 = readFromFile("sudoku4.txt");


    int demo;
    cout << "We have 4 saved puzzles pick ramdomly(enter 1-4) : ";
    cin >> demo;
    vector<vector<int>> user(9, vector<int>(9, 0));
    bool ans;


    if(demo == 1){ //playing with number 1 puzzle
      printGrid(sudoku1, 9);
    

      for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
          cin >> user[i][j];
        }
      }

      ans = isValidRow(sudoku1, user);
      
    }

    else if(demo == 2){ // playing with number 2 puzzle 
      printGrid(sudoku2, 9);
    

      for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
          cin >> user[i][j];
        }
      }

      ans = isValidRow(sudoku2, user);
      
    }

    else if(demo == 3){ // playing with number 3 puzzle
      printGrid(sudoku3, 9);
    

      for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
          cin >> user[i][j];
        }
      }

      ans = isValidRow(sudoku3, user);
      
    }

    else if(demo == 4){ // playing with number 4 puzzle
      printGrid(sudoku4, 9);
    

      for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
          cin >> user[i][j];
        }
      }

      ans = isValidRow(sudoku4, user);
      
    }

    if(ans){
      cout << "Your answer is correct." << endl;
    }
    else cout << "Your answer is wrong."<< endl;
  }


  else if(n == 2){ // submit puzzle Mode
    cout << "Enter the sudoku puzzle :"<< endl;
    vector<vector<char>> puzzle(9, vector<int>(9));
    for(int i = 0;i < 9;i++){
      for(int j = 0;j < 9;j++){


        char temp;
        cin >> temp;
        if(temp >= '0' && temp <= '9'){
          puzzle[i][j] = temp;
        }
        else{
          cout << "Invalid value"<< endl;
          return 0;
        }
      }
    }

    if(solveSudoku(puzzle, 9)){
      cout << "Your answer is :"<< endl;
      printGrid(puzzle, 9);
    }
    else{
      cout << "The puzzle is not solvable. "<< endl;
    }
    return 0;

  }
  
  else {
    cout << "The value is invalid." << endl;
    return 0;
  }

}
