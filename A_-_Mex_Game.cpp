#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> alice;
    vector<int> bob;
    for(int i = 0; i < n+1; i++)
    {
        if(s[i]=='A')
        {
            alice.push_back(i);
        }
        else 
        {
            bob.push_back(i);
        }
        
    }

    if(alice.size()==0)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"Bob"<<endl;
        }
        return 0;
        
    }
    if(bob.size()==0)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"Alice"<<endl;
        }
        return 0;
        
    }
    
    
    

    for(int i = 1; i < n+1; i++)
    {
        int x=(i+1)/2;
        int y=i-x;
        if(x>=bob.size()){
            cout<<"Alice"<<endl;
            continue;
        }
        if(y>=alice.size()){
            cout<<"Bob"<<endl;
            continue;
        }
        int mini=min(alice[y],bob[x]);
        
        if(s[mini]=='A')
        {
            cout<<"Alice"<<endl;
        }
        else
        {
        cout<<"Bob"<<endl;
        }
        

    }
    
    return 0;
}
