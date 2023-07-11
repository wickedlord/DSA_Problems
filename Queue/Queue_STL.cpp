#include <bits/stdc++.h>
using namespace std;

int main () {
    queue<int> q;

    q.push(11);
    q.push(14);
    q.push(16);

    cout << "size of queue is : " << q.size() << endl;

    cout << "front element is : " << q.front() << endl;

    q.pop();

    cout << "size of queue after pop is : " << q.size() << endl;

    if (q.empty()) {
        cout << "queue is empty.";
    }

    else cout << "queue is not empty.";
}