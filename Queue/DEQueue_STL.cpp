#include <bits/stdc++.h>
using namespace std;

int main () {
    deque<int> q;

    q.push_back(13);
    q.push_back(15);
    q.push_front(11);

    cout << "Front element is : " << q.front() << endl;
    cout << "Back element is : " << q.back() << endl;

    q.pop_back();
    q.pop_front();

    cout << "After popping :" << endl;

    cout << "Front element is : " << q.front() << endl;
    cout << "Back element is : " << q.back() << endl;
}