#include <iostream>
#include <vector>
using namespace std;

bool candivide(const vector<long long>& houses, int k, long long max_sum){
    int segments=1;
    long long current_sum=0;

    for(int i=0; i<houses.size(); i++){
        if(houses[i]>max_sum){
            return false;
        }

        if(current_sum + houses[i]> max_sum){
            segments++;
            current_sum=houses[i];
            
            if(segments>k){
                return false;
            }

        }

        else{
            current_sum+=houses[i];
        }
    }
    return segments<=k;
}

int main(){
    int n,k;
    cin>> n>> k;

    vector<long long> houses(n);
    long long max_house= 0;
    long long total_sum=0;

    for(int i=0; i<n; i++){
        cin>> houses[i];
        total_sum+=houses[i];

        if(houses[i]>max_house){
            max_house=houses[i];
        }
    }

    long long left= max_house;
    long long right= total_sum;
    long long ans=total_sum;

    while(left<=right){
        long long mid= left+(right-left)/2;

        if(candivide(houses, k, mid)){
            ans=mid;
            right=mid-1;

        }
        else{
            left=mid+1;
        }
    }
    cout<< ans<< endl;
    return 0;
}