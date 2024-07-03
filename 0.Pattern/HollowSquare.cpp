#include<bits/stdc++.h>
using namespace std;
void HollowSquare(int n){

    int top, bottom, left, right;

    for(int i = 0; i<2*n-1; i++){
        for(int j = 0; j<2*n-1; j++){
            top = i;
            bottom = j;
            left = (2*n-2)-i;
            right = (2*n-2)-j;

            cout<<n-(min(min(top, bottom), min(left, right)));

        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    HollowSquare(n);
    return 0;
}