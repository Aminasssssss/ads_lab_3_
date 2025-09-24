#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin>> n>> k;

    vector<int> max_x(n), max_y(n);

    for(int i=0; i<n; i++){
        int x1,y1,x2,y2; 
        cin>> x1>> y1>> x2>> y2;
        
        max_x[i]=x2;
        max_y[i]=y2;


    }

    long long left=1;
    long long right= 1000000000;
    long long ans= right;

    while(left<=right){
        long long mid=(left+right)/2;

        int count=0;
        for(int i=0; i<n; i++){
            if(max_x[i]<=mid && max_y[i]<=mid){
                count++;
            }
        }
        if(count>=k){
            ans=mid;
            right= mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<< ans<< endl;
    return 0;

}