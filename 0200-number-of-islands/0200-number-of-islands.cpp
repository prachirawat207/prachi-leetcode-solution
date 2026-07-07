class Solution {
public:
void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
    int m=grid.size();
      int n=grid[0].size();
    if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0'||vis[i][j]==1){
        return;
    }
    vis[i][j]=1;
    dfs(i-1,j,grid,vis);
    dfs(i,j-1,grid,vis);
    dfs(i+1,j,grid,vis);
    dfs(i,j+1,grid,vis);
}
    int numIslands(vector<vector<char>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      int count=0;
      vector<vector<int>>vis(m,vector<int>(n,0));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]&&grid[i][j]=='1'){
                count++;
                dfs(i,j,grid,vis);
            }
        }
      } //
      return count; 
    }
};