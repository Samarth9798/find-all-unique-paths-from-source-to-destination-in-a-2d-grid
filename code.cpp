//by Samarth Tandon
//Date: 1/11/2019 Time: 18:23:55

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//here we start from node (0,0) and goto node (N - 1, M - 1) 

//NOTE:-> '0' means the path is not block and '1' means the path is blocked

#include<bits/stdc++.h>

using namespace std;

int grid[10000][10000];

int visited[10000][10000];

void countpaths(int N, int M, int x, int y, int& count)
{
    if(x == N - 1 and y == M - 1) //if we reach to node (N - 1, M - 1)
    {
        count++;
        return;
    }
    
    visited[x][y] = 1; //mark the current node as visited
    
    if(x >= 0 and y >= 0 and x < N and y < M and grid[x][y] == 0) 
    {
        if(x + 1 < N and !visited[x + 1][y]) //go down
            countpaths(N, M, x+1, y, count);
            
        if(x - 1 >= 0 and !visited[x - 1][y]) //go up
                countpaths(N, M, x-1, y, count);
           
        if(y + 1 < M and !visited[x][y + 1]) //go right
                countpaths(N, M, x, y+1, count);
                
        if(y - 1 >= 0 and !visited[x][y - 1]) //go left
                countpaths(N, M, x, y-1, count);
                
    }
    
    visited[x][y] = 0; //mark the current node as unvisited for backtrack
}


int main()
{
    int T;
    
    int N,M;
    
    int i,j;
    
    cin >> T; //input the no of test cases
    
    while(T--) //loop the no of test cases
    {
        cin >> N >> M; //input the size of grid
        
        memset(visited, 0, sizeof(visited) ); //set all positions as unvisited (0)
        
        int count = 0; //set the initial count to 0
        
        //input the grid
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                cin >> grid[i][j]; 
            }
        }
        
        countpaths(N, M, 0, 0, count); //count no of unique paths
        
        cout << count << endl; //output the ans
    }
    
}
