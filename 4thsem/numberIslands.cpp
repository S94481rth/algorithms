//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis, int row, int col){
      vis[row][col] = 1;
      int n = grid.size();
      int m = grid[0].size();
      for(int delRow = -1;delRow<=1; delRow++){
          for(int delCol = -1;delCol<=1;delCol++){
              
              int newRow = row + delRow;
              int newCol = col + delCol;
              
              if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && 
                  grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                    dfs(grid,vis,newRow,newCol);      
                }
          }
      }
  }
  
  void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis, int row, int col){
      vis[row][col] = 1;
      queue<pair<int,int>> q;
      q.push({row,col});
      int n = grid.size();
      int m = grid[0].size();
      
      while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          
          q.pop();
          
          for(int delRow = -1;delRow <= 1;delRow++){
              for(int delCol = -1; delCol <= 1;delCol++){
                  int newRow = row + delRow;
                  int newCol = col + delCol;
                  if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && 
                  grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                      q.push({newRow,newCol});
                      vis[newRow][newCol] = 1;
                  }
              }
          }
      }
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        //number of rows
        int n = grid.size();
        //number of columns
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        int count = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    dfs(grid,vis,row,col);
                    //bfs(grid,vis,row,col);
                    //both work!
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
