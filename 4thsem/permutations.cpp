#include<bits/stdc++.h>

using namespace std;

void permute(vector<int>& curr,int index,int n,vector<int>& visited){
    if(curr.size() == n){
        for(auto it: curr){
            cout << it << " ";
        }
        cout<<"\n";
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            curr.push_back(i+1);
            visited[i] = 1;
            permute(curr,i+1,n,visited);
            curr.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    vector<int> curr;
    vector<int> visited(3,0);
    permute(curr,0,3,visited);

    return 0;
}
