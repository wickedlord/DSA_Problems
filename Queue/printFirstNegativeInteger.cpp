#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<long long int> de;
    vector<long long> ans;
    

    // handling first case
    //only input index of elements in the dequeue which are negative.
    for (int i=0; i<K; i++) {
        if (A[i] < 0) {
            de.push_back(i);
        }
    }
    
    //if size is greater, we have to return the element which occurs first.
    if (de.size() > 0) {
        ans.push_back(A[de.front()]);
    }
    else ans.push_back(0);
    
    //solving for  remaining part
    
    for (int i=K; i<N; i++) {
        
        //checking for the removal of element
        if (!de.empty() && i-de.front() >= K /*this is used to check whether the element is to be included in the current window or not*/) {
            de.pop_front();
        }
        
        if (A[i] < 0) {
            de.push_back(i);
        }
        
        if (de.size() > 0) {
        ans.push_back(A[de.front()]);
        }
        
        else ans.push_back(0);
    }
    
    return ans;
}