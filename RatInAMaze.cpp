class Solution{
  public:
    bool isSafe(int x,int y,vector<vector<int>>& maze,vector<vector<int>>& visited){
        int n=maze.size(),m=maze[0].size();
        if(x<0 || x>=n || y<0 || y>=m || maze[x][y]==0 || visited[x][y]==1){
            return false;
        }
        return true;
    }
    void solve(int x,int y,vector<vector<int>>& maze,vector<vector<int>>& visited,string path,vector<string>& ans){
        int n=maze.size(),m=maze[0].size();
        if(x==n-1 && y==m-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        if(isSafe(x+1,y,maze,visited)){
            path.push_back('D');
            solve(x+1,y,maze,visited,path,ans);
            path.pop_back();
        }
        if(isSafe(x,y+1,maze,visited)){
            path.push_back('R');
            solve(x,y+1,maze,visited,path,ans);
}       