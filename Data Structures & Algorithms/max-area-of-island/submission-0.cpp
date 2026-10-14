class Solution {
public:

vector<pair<int,int>>dist={{-1,0},{0,-1},{0,1},{1,0}};



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
         int row=grid.size();
        int col= grid[0].size();
       
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int count=0;
dfs(grid,i,j,count);
maxi=max(maxi,count);
                }
            }
        } 
        return maxi;
    }

    void dfs(vector<vector<int>>& grid,int i,int j,int &count){
         int row=grid.size();
        int col= grid[0].size();

        if(i<0|| j<0 ||i>=row|| j>=col|| grid[i][j]==0)return;
                grid[i][j]=0;
                count+=1;
        for(int k=0;k<4;k++){
           

                dfs(grid,i+dist[k].first,j+dist[k].second,count);
            
        }


        
    }
};
