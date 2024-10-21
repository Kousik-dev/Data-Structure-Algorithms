#include<iostream>
using namespace std;
int main(){

    int n = 5;
    int size = 2*n-1;

    for(int i = 1; i<=size; i++){
        for(int j = 1; j<=size; j++){
            int a = max(abs(i-n), abs(j-n))+1;
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}