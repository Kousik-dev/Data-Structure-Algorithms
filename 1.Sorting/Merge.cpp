#include<bits/stdc++.h>
using namespace std;
void combine(vector<int> &a, int low, int mid, int high){
    vector<int>temp;
    int left = low, right = mid+1;
    while(left<= mid and right<=high){
        if(a[left]<=a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low ; i<=high; i++){
        a[i] = temp[i-low];
    }
    

}
void mergesort(vector<int>&a, int low , int high)
{
    if(low >= high)
    return;
    int mid = (low + high)/2;
    mergesort(a, low , mid);
    mergesort(a, mid+1, high);
    combine(a,low, mid, high);
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i<n; i++)
    cin>>a[i];
    cout<<"Before Sorting"<<endl;
    for(int val:a)
    cout<<val<<" ";
    cout<<endl;
    int low = 0, high = n-1;
    mergesort(a, low, high);
    cout<<"After Sorting"<<endl;
    for(int val:a)
    cout<<val<<" ";
}