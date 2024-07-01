#include<iostream>
using namespace std;
int main(){
    int row;
    cin>>row;

    for(int i = row ; i>=1; i--){
        for(int space = 1; space<=row-i; space++)
        cout<<" ";
        for(int j = 1; j<=(2*i)-1; j++)
        cout<<"*";
        cout<<endl;
    }
}