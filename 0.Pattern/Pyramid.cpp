#include<iostream>
using namespace std;
int main()
{
    int row;
    cin>>row;
   
    for(int i = 1; i<=row; i++)
    {
        for(int space = 1;space<=row-i; space++)
        cout<<" ";

        for(int col = 1; col<=(2*i)-1; col++){
            cout<<"*";
        }
        cout<<endl;
    }
}