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
void print_pair(vector<pair<int,int>>a)
{
    cout<<"S --> ";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i].first<<","<<a[i].second<<" --> ";
    }
    cout<<"F";
}
bool solveMazeRecursive(int row, int col, vector<vector<char>>& maze,vector<pair<int,int>>& path) 
{
    if (maze[row][col] == 'X') return false;
    if (maze[row][col] == '.') return false;
    if (maze[row][col] == 'F') return true;
    maze[row][col] = '.';
    path.push_back(make_pair(row,col));
    // north
    if (solveMazeRecursive(row-1,col,maze,path)) return true;
    // east
    if (solveMazeRecursive(row,col+1,maze,path)) return true;
    // south
    if (solveMazeRecursive(row+1,col,maze,path)) return true;
    // west
    if (solveMazeRecursive(row,col-1,maze,path)) return true;
    maze[row][col] = 'b';
    path.pop_back();
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
    vector<pair<int,int>>path;
    bool a = solveMazeRecursive(1,1,mazee,path);
    for(int i=0;i<9;i++)
        print(mazee[i]);
    //cout<<a;
    print_pair(path);

}