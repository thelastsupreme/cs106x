int countMazeSolutionsHelper(Grid<bool>& maze, int startRow,int startCol, int endRow, int endCol) 
{
    if (!maze[startRow][startCol])
     {
        return 0;
    }
    if (startRow == endRow && startCol == endCol)
    {
        return 1; //reached our goal
    }
    maze[startRow][startCol] = false; // choose
    int numSolutions = countMazeSolutionsHelper(maze, startRow + 1,startCol, endRow, endCol);
    numSolutions += countMazeSolutionsHelper(maze, startRow - 1,startCol, endRow, endCol);
    numSolutions += countMazeSolutionsHelper(maze, startRow,startCol + 1, endRow, endCol);
    numSolutions += countMazeSolutionsHelper(maze, startRow,startCol - 1, endRow, endCol);
    maze[startRow][startCol] = true; // unchoose
    return numSolutions;
}