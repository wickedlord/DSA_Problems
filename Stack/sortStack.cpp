#include <bits/stdc++.h>

void sortedInsert(stack<int> &stack, int num) {
	// base case
	if (stack.empty() || stack.top() < num) { // ye check krne ke liye ki hum insert kr
                                            // skte hai ya nhi, ie, ya to stack
                                            // khaali ho ya fir jo uske top pr element
                                            // hai jo sbse bada hai vo num se chhota ho
		stack.push(num);
		return;
	}

// agar element top pr bada ho num se, to use nikaal kr rkh do aur baaki check kr lo
	int element = stack.top();
	stack.pop();

	sortedInsert(stack, num);
    
    // kaam khtm hone ke baad usko lete jaana.
	stack.push(element);
}

void sortStack(stack<int> &stack)
{
	//base case
	if (stack.empty()) {
		return;
	}

	int num = stack.top();
	stack.pop();

    // bacha hua stack sort krke la dega
	sortStack(stack);

    // jo element top pr tha usko sorted way mai insert kr dega
	sortedInsert(stack, num);
}