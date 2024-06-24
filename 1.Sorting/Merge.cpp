#include<bits/stdc++.h>
using namespace std;
void combine(int &a, int low, int mid, int high){
    int temp[high+1];
    int k = 0;
    while(low<=mid+1 and mid)

}
int mergesort(int a[], int low , int high)
{
    int mid = (low + high)/2;
    if(low == high)
    return ;
    mergesort(a, low, mid+1);
    mergesort(a, mid+1, high);
    combine(a, low, mid, high);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)
    cin>>a[i];
    cout<<"Before Sorting .....";
    for(int val:a)
    cout<<val<<" ";
    cout<<endl;
    int low = 0, high = n-1;
    mergesort(a, low, high);
}