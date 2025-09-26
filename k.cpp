#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<long long>& arr, long long k, int L){
    long long current_sum=0;

    for(int i=0; i<L; i++){
        current_sum+= arr[i];
    }

    if(current_sum>=k){
        return true;
    }

    for(int i=L; i<arr.size(); i++){
        current_sum+= arr[i];
        current_sum-= arr[i-L];

        if(current_sum>= k){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    long long k;
    cin>> n>> k;

    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin>> arr[i];

    }
    int left= 1;
    int right= n;
    int ans= n;

    while(left<=right){
        int mid= left+(right-left)/2;

        if(check(arr, k, mid)){
            ans=mid;
            right=mid-1;

        }
        else{
            left= mid+1;

        }
    }
    cout<< ans<< endl;

    return 0;

}