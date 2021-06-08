#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;


int candiate(vector<int> &arr)
{
    int maj_index=0,count=1;
    for(int i=1;i<arr.size();++i)
    {
        if(arr[i]==arr[maj_index])
        {
            count+=1;
        }
        else
        {
            count-=1;
        }
        if (count == 0) 
        {
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}
int majority(vector<int> &arr)
{
    int can=candiate(arr);
    int count=0;
    for(int i=0;i<arr.size();++i)
    {
        if(arr[i]==can)
        {
            count+=1;
        }
    }
    if(count>(arr.size()/2))
        return 1;
    else
        return 0;
}
int main()
{
    int n,a;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<majority(arr);
    return 0;
}