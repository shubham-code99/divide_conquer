#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

void partition(vector<int> &arr, vector<int> &x,  int l, int r)
{
    int m, n;
    m=n=l;
    for(int i=l+1;i<=r;i++)
    {
        if(arr[i]<arr[l])
        {
            swap(arr[i],arr[n+1]);
            swap(arr[n+1],arr[m+1]);
            n+=1;
            m+=1;            
        }
        else if(arr[i]==arr[l])
        {
            swap(arr[i],arr[n+1]);
            n+=1;
        }
        
    }
    swap(arr[l],arr[m]);
    x[0]=m;
    x[1]=n;
}

void qsort(vector<int> &arr, int l, int r )
{
    while(l<r)
    {
        int pivot;
        int mid=l+((r-l)/2);
        vector<int> med,temp;
        med.push_back(arr[l]); 
        med.push_back(arr[mid]);
        med.push_back(arr[r]);
        temp=med;
        temp.push_back(l);
        temp.push_back(mid);
        temp.push_back(r);
        sort(med.begin(), med.end());
        for(int i=0;i<3;++i)
        {
            if(med[1]==temp[i])
                {
                    pivot=temp[i+3];
                    break;
                } 
        }
        swap(arr[pivot],arr[l]);
        vector<int> x(2);
        partition(arr,x,l,r);
        if((x[0]-l)<(r-x[0]))
        {
            qsort(arr,l,x[0]-1);
            l=x[0]+1;
        }
        else
        {
            qsort(arr,x[1]+1,r);
            r=x[1]-1;
        }
    }
}

int main()
{
    int n,a;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();++i)
    {
        cin>>arr[i];
    }
    qsort(arr, 0 , arr.size()-1);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";  
    return 0;
}

