#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    long long f;
    cin>> n>> f;

    vector<int> c(n);
    int max_c=0;
    for(int i=0; i<n; i++){
        cin>> c[i];

        if(c[i]>max_c){
            max_c=c[i];
        }
    }
    int left= 1;
    int right= max_c;
    int ans= max_c;


    while(left<=right){
        int capacity= (left+right)/2;

        long long total_flights= 0;
        for(int i=0; i<n; i++){
            int flights_for_island= c[i]/capacity;

            if(c[i]%capacity!=0){
                flights_for_island++;
            }
            total_flights+=flights_for_island;
        }
        if(total_flights<=f){
            ans=capacity;
            right=capacity-1;
        }
        else{
            left= capacity+1;
        }
    }

    cout<< ans<< endl;

    return 0;
}