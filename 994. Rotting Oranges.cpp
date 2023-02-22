//994. Rotting Oranges



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        q.push({-1,-1});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==-1){
                count++;
                if(!q.empty()) q.push({-1,-1});
                
                continue;
            }
            if(row-1>=0 && row-1<n && col>=0 && col<m && grid[row-1][col]==1 && !visited[row-1][col]){
                grid[row-1][col]=2;
                q.push({row-1,col});
                visited[row-1][col]=true;
            }
            if(row+1>=0 && row+1<n && col>=0 && col<m && grid[row+1][col]==1 && !visited[row+1][col]){
                grid[row+1][col]=2;
                q.push({row+1,col});
                visited[row+1][col]=true;
            }
            if(row>=0 && row<n && col-1>=0 && col-1<m && grid[row][col-1]==1 && !visited[row][col-1]){
                grid[row][col-1]=2;
                q.push({row,col-1});
                visited[row][col-1]=true;
            }
            if(row>=0 && row<n && col+1>=0 && col+1<m && grid[row][col+1]==1 && !visited[row][col+1]){
                grid[row][col+1]=2;
                q.push({row,col+1});
                visited[row][col+1]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return count-1;
    }
};