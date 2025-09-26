#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool process(const vector<int>& bags, int h, long long k){
    long long total_hours=0;

    for(int i=0; i<bags.size(); i++){
        total_hours+=(bags[i]+k-1)/k;

        if(total_hours>h){
            return false;
        }
    }
    return total_hours<=h;
}

int main(){
    int n, h;
    cin>> n>> h;

    vector<int> bags(n);
    int max_bars=0;

    for(int i=0; i<n; i++){
        cin>> bags[i];
        if(bags[i]>max_bars){
            max_bars= bags[i];
        }

    }
    long long left =1;
    long long right=max_bars;
    long long ans=max_bars;

    while(left<=right){
        long long mid=left+(right-left)/2;

        if(process(bags, h, mid)){
            ans=mid;
            right=mid-1;

        }
        else{
            left=mid+1;
        }
    }
    cout << ans<< endl;
    return 0;
}