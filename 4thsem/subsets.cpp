#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int> &array,int index,int size,vector<int>& curr){
    if(index == size){
        for(auto it: curr){
            cout<< it << " ";
        }
        cout<<"\n";
        return;
    }
    
    curr.push_back(array[index]);
    subsets(array,index+1,size,curr);
    curr.pop_back();
    subsets(array,index+1,size,curr);
}

int main(){
    vector<int> array= {1,2,3};
    int n = array.size();
    vector<int> curr;
    subsets(array,0,n,curr);
}
