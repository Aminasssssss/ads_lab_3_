#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, q;
    cin>> n>> q;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }

    sort(a.begin(), a.end());

    for(int i=0; i<q; i++){
        int l1, r1;
        cin >> l1>> r1;
        int l2, r2;
        cin>> l2>> r2;

        vector<int>::iterator start1= lower_bound(a.begin(), a.end(), l1);
        vector<int>::iterator end1= upper_bound(a.begin(), a.end(), r1);

        int count1 =end1-start1;

        vector<int>::iterator start2= lower_bound(a.begin(), a.end(), l2);
        vector<int>::iterator end2= upper_bound(a.begin(), a.end(), r2);

        int count2= end2-start2;

        int intersect_start =max(l1, l2);
        int intersect_end= min(r1,r2);
        int count_intersect=0;

        if(intersect_start<= intersect_end){
            vector<int>::iterator start_inter= lower_bound(a.begin(), a.end(), intersect_start);

            vector<int>::iterator end_inter= upper_bound(a.begin(), a.end(), intersect_end);

            count_intersect= end_inter-start_inter;
        }

        int ans=count1+count2- count_intersect;
        cout<< ans<< endl;


    }
    return 0;
}