#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(const vector<int>& row, int target, bool isevenrow){
    int left=0;
    int right= row.size()-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(row[mid]==target){
            return mid;
        }

        if(isevenrow){
            if(row[mid]>target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }

        }
        else{
            if(row[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;


    vector<int> numbers_to_find(t);
    for(int i=0;i<t; i++){
        cin>> numbers_to_find[i];
    }

    int n, m;
    cin>> n>> m;

    vector<vector<int> > snake_table(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> snake_table[i][j];
        }
    }

    for(int k=0; k<t; k++){
        int target_number= numbers_to_find[k];
        bool found =false;


        for(int i=0; i<n; i++){
            bool isevenrow=(i%2==0);

            int position_in_row=find(snake_table[i], target_number, isevenrow);

            if(position_in_row!=-1){
                cout << i<< " "<< position_in_row<< endl;
                found=true;
                break;
            }

        }
        if(!found){
            cout<< -1<< endl;

        }
    }

    return 0;
}