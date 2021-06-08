#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int> &arr,int l, int m, int r)
{
    vector<int> a1;
    vector<int> a2;
    int count=0;
    int l1=l,m1=m,r1=r;
    while(l1<=m1)
    {
        a1.push_back(arr[l1]);
        l1+=1;
    }
    m1+=1;
    while(m1<=r1)
    {
        a2.push_back(arr[m1]);
        m1+=1;
    }
    int i=0,j=0,k=l;
    while((i<a1.size())&&(j<a2.size()))
    {
        if(a1[i]<=a2[j])
        {
            arr[k]=a1[i];
            i+=1;                     
        }
        else
        {
            arr[k]=a2[j];
            j+=1;   
            count=count+(a1.size()-i);                   
        }
        k+=1;   
                    
    }
    while(i<a1.size())
    {
        arr[k]=a1[i];        
        i++;
        k++;
    }
    while(j<a2.size())
    {
        arr[k]=a2[j];
        j++;
        k++;
    }
    
    return count;
       
}

int mergesort(vector<int> &arr,int l, int r)
{
    if(l>=r)
        return 0;
    int m=l+(r-l)/2;
    int count=0;
    count+=mergesort(arr,l,m);
    count+=mergesort(arr,m+1,r);
    
    count+=merge(arr,l,m,r); 
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int a;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<mergesort(arr,0,arr.size()-1)<<endl;
    
    return 0;
}