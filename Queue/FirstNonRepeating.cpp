#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
		    string ans;
		    unordered_map <char,int> count;
		    queue<char> q;
		    
		    for (int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while (!q.empty()) {
		            if (count[q.front()] > 1) {
		                q.pop();
		            }
		            
		            else {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if (q.empty()) {
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}