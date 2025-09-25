#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin>> n>> m;

    vector<int> blocks(n);

    for(int i=0; i<n; i++){
        cin>> blocks[i];
    }

    vector<int> prefix(n);
    prefix[0]= blocks[0];

    for(int i=1; i<n; i++){
        prefix[i]= prefix[i-1]+ blocks[i];
    }

    for(int i=0; i<m; i++){
        int error_line;
        cin>> error_line;

        int l=0, r=n-1;
        int ans= -1;


        while(l<=r){
            int mid=(l+r)/2;

            if(prefix[mid] >= error_line){
                ans= mid+1;
                r= mid-1;

            }
            else{
                l=mid+1;
            }
        }
        cout<< ans<< endl;

    }
    return 0;
}