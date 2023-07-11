void insertAtBottom (stack<int>& myStack, int x) {
    // base case
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    //recursive call
    solve(myStack,x);

    myStack.push(num);
}