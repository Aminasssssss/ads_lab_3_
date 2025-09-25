#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>> n;

    vector<int> competitors(n);
    for(int i=0; i<n; i++){
        cin>> competitors[i];
    }

    sort(competitors.begin(), competitors.end());

    vector<long long> pre_sum(n);
    
    pre_sum[0] =competitors[0];

    for(int i=1; i<n; i++){
        pre_sum[i]= pre_sum[i-1]+competitors[i];
    }

    int p;
    cin>> p;

    for(int round=0; round<p; round++){
        int mark_power;
        cin>> mark_power;


        int left= 0;
        int right=n-1;
        int ans =-1;

        while(left<=right){
            int mid=(left+right)/2;

            if(competitors[mid]<= mark_power){
                ans=mid;
                left= mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(ans==-1){
            cout <<"0 0"<< endl;
        }
        else{
            cout<< ans+1<< " "<< pre_sum[ans]<< endl;
        }
    }
    return 0;
}