/*logic is that opening and closing both brackets of all the types should be there.
and the closing bracket of same type should come right after opening one.
*/

bool isValidParenthesis(string expression)
{
    stack<char> s;

    for (int i=0; i<expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else {
          if (!s.empty()) {
            char top = s.top();
            if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')) {
              s.pop();
            } else {
              return false;
            }
          }

          else {
            return false;
          }
        }
    }

    if (s.empty()) {
        return true;
    }
    else {
        return false;
    }
}