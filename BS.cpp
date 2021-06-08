#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int> &a, int low, int high,int key)
{
    if((key<a[low])||(key>a[high]))
    return -1;
    int mid=(low+((high-low)/2));
    if(a[mid]==key)
    return mid;
    if(a[mid]<key)
        return bs(a,mid+1,high,key);
    else if(a[mid]>key)
        return bs(a,low,mid-1,key);
    return -1;
}
int main()
{
    vector<int> a;
    int n , v;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>v;
        a.push_back(v);
    }
    int s;
    cin>>s;
    vector<int> s2;
    for(int i=0;i<s;i++)
    {
        cin>>v;
        s2.push_back(v);
    }
    for(int i=0;i<s;++i)
    {
        cout<<bs(a,0,a.size()-1,s2[i])<<" ";
    }
    return 0;
}