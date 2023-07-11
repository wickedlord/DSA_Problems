//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0; //to find the requirement of petrol to cross certain number of blocks
       int start = 0; //from where we have to start the journey
       int balance = 0; // = petrol - distance
       
       for (int i=0; i<n; i++) {
           balance += p[i].petrol - p[i].distance;
           if (balance < 0) { // means we can't go further
               deficit += balance; // to calculate requirement of petrol
               start = i+1; // proceed from further block
               balance = 0;
           }
       }
       
       if (deficit + balance >= 0) {
           return start;
       }
       
       else return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends