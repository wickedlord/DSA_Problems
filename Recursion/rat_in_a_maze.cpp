#include <bits/stdc++.h>
using namespace std;

bool isSafe (vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited) {
    if ((m[x][y]==1) && (visited[x][y]==0) && (0<x) && (x<n) && (0<y) && (y<n)) {
        return true;
    }
    else return false;
}

void solve (vector<vector<int>>& m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string>& ans) {
    if ((x==n-1) && (y==n-1)) {
        cout << path << endl;
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;

    //down
    int newx = x+1;
    int newy = y;
    if (isSafe(m,n,newx,newy,visited)) {
        path.push_back('D');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    //left
    newx = x;
    newy = y-1;
    if (isSafe(m,n,newx,newy,visited)) {
        path.push_back('L');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    //right
    newx = x;
    newy = y+1;
    if (isSafe(m,n,newx,newy,visited)) {
        path.push_back('R');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    //up
    newx = x-1;
    newy = y;
    if (isSafe(m,n,newx,newy,visited)) {
        path.push_back('U');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    visited[x][y] = 0;
}

void display(vector<string> ans) {
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

vector<string> findPath (vector<vector<int>>& m, int n) {
    //jisme final answer ko store krenge
    vector<string> ans;

    //initial points
    int srcx=0;
    int srcy=0;

    // agr phle hi 0 hai to aage nhi ja skte
    if (m[0][0]==0) {
        return ans;
    }

    // creating a visited array to mark which positions i have visited
    // and initialising them with 0
    vector<vector<int>> visited = m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j]=0;
        }
    }

    //the path we are taking will be stored here
    string path = "";
    solve(m,n,srcx,srcy,visited,path,ans);
    sort(ans.begin(), ans.end());
    display(ans);
    return ans;
}

int main () {
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    findPath(m,n);
}