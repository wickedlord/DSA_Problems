#include <bits/stdc++.h>
using namespace std;


//approacch is very weird due to the constraint of not using a queue and only a stack
void interleave (queue<int> &q) {
    stack<int> s;
    int size = q.size();
    int count = 0;

    while (count != size/2) {
        int element = q.front();
        s.push(element);
        q.pop();
        count++;
    }

    while (!s.empty()) {
        int element = s.top();
        q.push(element);
        s.pop();
    }

    count = 0;
    while (count != size/2) {
        int element = q.front();
        q.pop();
        q.push(element);
        count++;
    }

    count = 0;
    while (count != size/2) {
        int element = q.front();
        s.push(element);
        q.pop();
        count++;
    }
    
    while (!s.empty()) {
        int stacK_element = s.top();
        q.push(stacK_element);
        s.pop();

        int queue_element = q.front();
        q.pop();
        q.push(queue_element);
    }
}

int main () {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    //the constraint is that we cannot use a queue in between, only stack is allowed.
    interleave(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}