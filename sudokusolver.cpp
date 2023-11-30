#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 9

void printGrid(const vector<vector<int>> &grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>> &grid, int row, int col, int num, int size)
{
    for (int x = 0; x < size; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int sqrtSize = sqrt(size);
    int startRow = row - row % sqrtSize;
    int startCol = col - col % sqrtSize;
    for (int i = 0; i < sqrtSize; i++)
        for (int j = 0; j < sqrtSize; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool findEmptyPosition(const vector<vector<int>> &grid, int &row, int &col, int size)
{
    for (row = 0; row < size; row++)
        for (col = 0; col < size; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool solveSudoku(vector<vector<int>> &grid, int size)
{
    int row, col;

    if (!findEmptyPosition(grid, row, col, size))
        return true;

    for (int num = 1; num <= size; num++)
    {
        if (isSafe(grid, row, col, num, size))
        {
            grid[row][col] = num;

            if (solveSudoku(grid, size))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

bool isValidRow(int board[9][9], int user1[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (user1[i][j] != board[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cout << "Do want to play or do you want to submit a puzzle? " << endl;
    cout << "1 (enter 1 if you want to play) " << endl;
    cout << "2 (enter 2 if you want to submit a puzzle) " << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        vector<vector<int>> sudoku1 = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};

        int sudoku1_solution[9][9] = {
            {5, 3, 4, 6, 7, 8, 9, 1, 2},
            {6, 7, 2, 1, 9, 5, 3, 4, 8},
            {1, 9, 8, 3, 4, 2, 5, 6, 7},
            {8, 5, 9, 7, 6, 1, 4, 2, 3},
            {4, 2, 6, 8, 5, 3, 7, 9, 1},
            {7, 1, 3, 9, 2, 4, 8, 5, 6},
            {9, 6, 1, 5, 3, 7, 2, 8, 4},
            {2, 8, 7, 4, 1, 9, 6, 3, 5},
            {3, 4, 5, 2, 8, 6, 1, 7, 9}};

        vector<vector<int>> sudoku2 = {
            {0, 2, 0, 0, 0, 0, 0, 5, 0},
            {8, 0, 0, 0, 0, 7, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 6, 0, 3},
            {4, 0, 0, 5, 0, 0, 0, 0, 2},
            {0, 0, 0, 0, 7, 0, 0, 0, 0},
            {9, 0, 0, 0, 8, 0, 0, 4, 0},
            {0, 0, 0, 0, 0, 1, 2, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 8, 0},
            {0, 9, 0, 0, 3, 0, 0, 1, 0}};

        int sudoku2_solution[9][9] = {
            {1, 2, 3, 4, 6, 8, 9, 5, 7},
            {8, 4, 6, 9, 5, 7, 1, 3, 2},
            {5, 7, 9, 1, 2, 3, 6, 8, 4},
            {4, 1, 8, 5, 9, 6, 7, 3, 2},
            {3, 6, 2, 8, 7, 4, 5, 9, 1},
            {9, 5, 7, 2, 8, 1, 3, 4, 6},
            {6, 8, 4, 3, 7, 2, 1, 9, 5},
            {7, 3, 1, 6, 4, 9, 2, 8, 0},
            {2, 9, 5, 7, 3, 8, 4, 1, 0}};

        vector<vector<int>> sudoku3 = {
            {0, 0, 0, 3, 0, 2, 0, 9, 0},
            {0, 4, 0, 0, 9, 0, 0, 5, 0},
            {0, 0, 8, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 9, 0, 5, 0, 2, 0},
            {7, 0, 0, 0, 0, 0, 0, 0, 8},
            {0, 2, 0, 8, 0, 6, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 5, 0, 0},
            {0, 9, 0, 0, 3, 0, 0, 6, 0},
            {0, 3, 0, 2, 0, 7, 0, 0, 0}};

        int sudoku3_solution[9][9] = {
            {4, 7, 6, 3, 8, 2, 1, 9, 5},
            {3, 4, 2, 1, 9, 7, 8, 5, 6},
            {9, 1, 8, 5, 6, 4, 2, 3, 7},
            {8, 6, 3, 9, 7, 5, 4, 2, 1},
            {7, 5, 1, 4, 2, 3, 6, 9, 8},
            {1, 2, 4, 8, 5, 6, 9, 7, 3},
            {6, 8, 7, 7, 1, 9, 5, 4, 2},
            {2, 9, 5, 6, 3, 8, 7, 1, 4},
            {5, 3, 9, 2, 4, 7, 8, 1, 6}};

        vector<vector<int>> sudoku4 = {
            {1, 0, 0, 0, 0, 0, 0, 0, 4},
            {0, 0, 2, 0, 0, 0, 5, 0, 0},
            {0, 0, 0, 7, 0, 6, 0, 8, 0},
            {0, 0, 0, 9, 0, 0, 0, 0, 2},
            {0, 5, 0, 0, 0, 0, 0, 4, 0},
            {0, 0, 9, 0, 8, 0, 0, 0, 4},
            {0, 6, 0, 3, 0, 7, 0, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 8, 0},
            {0, 9, 0, 0, 3, 0, 0, 1, 0}};

        int sudoku4_solution[9][9] = {
            {1, 3, 8, 6, 7, 2, 9, 5, 4},
            {4, 7, 2, 8, 9, 5, 5, 6, 1},
            {9, 5, 1, 7, 4, 6, 2, 8, 3},
            {3, 8, 4, 9, 1, 7, 6, 1, 2},
            {2, 5, 6, 1, 3, 8, 7, 4, 9},
            {1, 1, 9, 2, 8, 4, 3, 7, 6},
            {8, 6, 1, 3, 2, 9, 4, 7, 5},
            {7, 4, 3, 5, 6, 1, 1, 8, 2},
            {5, 9, 7, 4, 3, 8, 8, 1, 1}};

        int demo;
        cout << "We have 4 saved puzzles pick ramdomly(enter 1-4) : ";
        cin >> demo;
        int user[9][9];
        bool ans;

        if (demo == 1)
        {
            printGrid(sudoku1, 9);

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cin >> user[i][j];
                }
            }

            ans = isValidRow(sudoku1_solution, user);
        }

        else if (demo == 2)
        {
            printGrid(sudoku2, 9);

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cin >> user[i][j];
                }
            }

            ans = isValidRow(sudoku2_solution, user);
        }

        else if (demo == 3)
        {
            printGrid(sudoku3, 9);

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cin >> user[i][j];
                }
            }

            ans = isValidRow(sudoku3_solution, user);
        }

        else if (demo == 4)
        {
            printGrid(sudoku4, 9);

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cin >> user[i][j];
                }
            }

            ans = isValidRow(sudoku4_solution, user);
        }

        if (ans)
        {
            cout << "Your answer is correct." << endl;
        }
        else
            cout << "Your answer is wrong." << endl;
    }

    else if (n == 2)
    {
        cout << "Enter the sudoku puzzle :" << endl;
        vector<vector<int>> puzzle(9, vector<int>(9));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int temp;
                cin >> temp;
                if (temp >= 0 && temp <= 9)
                {
                    puzzle[i][j] = temp;
                }
                else
                {
                    cout << "Invalid value" << endl;
                    return 0;
                }
            }
        }

        if (solveSudoku(puzzle, 9))
        {
            cout << "Your answer is :" << endl;
            printGrid(puzzle, 9);
        }
        else
        {
            cout << "The puzzle is not solvable. " << endl;
        }
        return 0;
    }

    else
    {
        cout << "The value is invalid." << endl;
        return 0;
    }
}