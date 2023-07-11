#include "bits/stdc++.h"
using namespace std;
class stac
{
private:
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    stac()
    {
        n = 0;
    }
    void push(int x)
    {
        q2.push(x);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        q1.pop();
        n--;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return n;
    }
    bool empty()
    {
        if (n == 0)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        cout << "stack is not empty" << endl;
        return 1;
    }
};
int main()
{
    stac st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << st.top() << endl;
    cout << st.empty() << endl;
    return 0;
}