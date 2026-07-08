class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       queue<pair<int,int>>q;
       int count=0;
       int n=grid.size();
       int m=grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
       }
     
       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};
       while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.first;
        int c=it.second;
         for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
           if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   grid[nr][nc]==1 && vis[nr][nc]==0){
                vis[nr][nc]=1;
                  q.push({nr,nc});
            }
         }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                count++;
            }
        }
       }
         return count;
    }
};