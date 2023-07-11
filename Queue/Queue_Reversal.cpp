//using stack
#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    return q;
}

//using recursion
void solve (queue<int> &q) {
    int element = q.front();
    if (q.empty()) {
        return;
    }
    
    q.pop();
    solve(q);
    q.push(element);
}

queue<int> rev(queue<int> q)
{
    solve (q);
    return q;
}