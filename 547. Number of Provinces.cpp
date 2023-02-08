//547. Number of Provinces


class Solution {
public:

    void Dfs(int src, vector<vector<int>>& adjLs, vector<bool>& visited){
        visited[src]=true;
        for(int i: adjLs[src]){
            if(!visited[i]){
                Dfs(i,adjLs,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        //converting the matrix into the adjlist;
        int v=isConnected.size();
        vector<vector<int>> adjLs(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int count=0;
        //finding provinces
        vector<bool> visited(v);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                Dfs(i,adjLs,visited);
                count++;
            }
        }
        return count;

    }
};