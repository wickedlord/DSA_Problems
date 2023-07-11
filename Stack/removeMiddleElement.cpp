/* here we will use recursion to find the middle element and remove it
to do so, use count to count the number of items in the stack from the top to bottom
when equal to size/2, pop it*/

#include <bits/stdc++.h>
void solve (stack<int>&inputStack, int size, int count) {
   //base case
   if (count == size/2) {
      inputStack.pop();
      return ;
   }

   int num = inputStack.top(); //removing the element after traversed
   inputStack.pop(); 

   //recursive call
   solve(inputStack, size, count+1);

   //on coming back from recursion
   inputStack.push(num); // getting the element back from recursion after coming back
} 
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve (inputStack, N, count);
   
}