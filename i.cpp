#include <iostream>
#include <vector>
using namespace std;
bool find(const vector<int>& a, int x){
    int l=0;
    int r=a.size()-1;

    while(l<=r){
        int mid=(l+r)/2;

        if(a[mid]==x){
            return true;
        }
        if(a[mid]<x){
            l=mid+1;
        }
        else{
            r=mid-1;
        }

    }
    return false;
}

int main(){
    int n;
    cin>> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    int x;
    cin>>x;

    if(find(a, x)){
        cout<<"Yes"<< endl;
    }
    else{
        cout<<"No"<< endl;
    }
    return 0;
    
}