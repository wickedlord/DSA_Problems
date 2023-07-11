#include "bits/stdc++.h"
using namespace std;

int prec(char s)
{
    if (s == '^')
    {
        return 3;
    }
    else if (s == '*' && s == '/')
    {
        return 2;
    }
    else if (s == '-' && s == '+')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixtopostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(s[i]) < prec(st.top()))
            {
                res += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int postfixeval(string s)
{
    stack<int> st;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '^':
                st.push(op1 ^ op2);
                break;
            default:
                break;
            }
        }
    }
    return (st.top());
}
int main()
{
    cout << infixtopostfix("(a-b/c)*(a/k-l)") << endl;
    cout << postfixeval("46+2/5*7+") << endl;
    return 0;
}