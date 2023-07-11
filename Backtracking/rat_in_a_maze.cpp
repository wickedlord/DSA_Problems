#include <bits/stdc++.h>
using namespace std; 

bool isSafe (int newx, int newy, vector < vector < int >> & arr, 
vector<vector<bool>> &visited, int n) 
{
    if ((newx>=0 && newx<n) && (newy>=0 && newy<n) && 
    (visited[newx][newy] != 1) && (arr[newx][newy] == 1)) {
        return true;
    }

    else return false;
}

void solve (int x, int y, vector < vector < int >> & arr, int n, string path,
vector<string> &ans, vector<vector<bool>> &visited) {
    if (x==n-1 && y==n-1) {
        ans.push_back(path);
        return;
    }

    //marking the current position as viisted
    visited[x][y] = 1;

    //there are 4 possible movements D,L,R,U

    //going for down
    if (isSafe(x+1,y,arr,visited,n)) {
        //path.push_back('D');
        solve(x+1,y,arr,n,path + 'D',ans,visited);
    }
    
    //going for left
    if (isSafe(x,y-1,arr,visited,n)) {
        //path.push_back('L');
        solve(x,y-1,arr,n,path + 'L',ans,visited);
    }

    //going for right
    if (isSafe(x,y+1,arr,visited,n)) {
        //path.push_back('R');
        solve(x,y+1,arr,n,path + 'R',ans,visited);
    }

    //going for up
    if (isSafe(x-1,y,arr,visited,n)) {
        //path.push_back('U');
        solve(x-1,y,arr,n,path + 'U',ans,visited);
    }

    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector <vector<bool>> visited(n,vector<bool> (n,0));
    string path = "";
    if (arr[0][0] == 0) {
        return ans;
    }

    int x = 0;
    int y = 0;
    solve(x,y,arr,n,path,ans,visited);
    return ans;
}