#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<char> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i)<<" ";
	}
    cout<<endl;
}
bool solveMazeRecursive(int row, int col, vector<vector<char>>& maze) 
{
    if (maze[row][col] == 'X') return false;
    if (maze[row][col] == '.') return false;
    if (maze[row][col] == 'F') return true;
    maze[row][col] = '.';
    // north
    if (solveMazeRecursive(row-1,col,maze)) return true;
    // east
    if (solveMazeRecursive(row,col+1,maze)) return true;
    // south
    if (solveMazeRecursive(row+1,col,maze)) return true;
    // west
    if (solveMazeRecursive(row,col-1,maze)) return true;
    maze[row][col] = 'b';
    return false;
}

int main()
{
    vector<vector<char>>mazee={ {'X','X','X','X','X','X','X','X','X'},
                                {'X','S',' ',' ','X',' ',' ',' ','X'},
                                {'X','X','X',' ','X',' ','X',' ','X'},
                                {'X',' ','X',' ','X',' ','X',' ','X'},
                                {'X',' ','X',' ','X','X','X',' ','X'},
                                {'X',' ','X',' ',' ',' ',' ',' ','X'},
                                {'X',' ','X','X','X','X','X',' ','X'},
                                {'X','F',' ',' ',' ',' ',' ',' ','X'},
                                {'X','X','X','X','X','X','X','X','X'},
                                };
    bool a = solveMazeRecursive(1,1,mazee);
    for(int i=0;i<9;i++)
        print(mazee[i]);
    cout<<a;

}