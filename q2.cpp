#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr,  int l, int r)
{
    /*
    int m,o,p;
    m=l+1;
    m=o=p;
    int a=l+1;
    while(a<=r)
    {
        if(arr[p]<=arr[l])
        {
            swap(arr[o],arr[p]);
            o+=1;
            p+=1;
        }
        else
        {
            p+=1;
        }
        a+=1;
    }
    swap(arr[l],arr[o-1]);
    return o-1;
    */
   int x = arr[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (arr[i] <= x) {
      j++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[l], arr[j]);
  return j;
}

void qsort(vector<int> &arr, int l, int r )
{
    if(l>=r)
        return;
    int mid=l+((l+r)/2), pivot;
    vector<int> med,temp;
    med.push_back(arr[l]); 
    med.push_back(arr[mid]);
    med.push_back(arr[r]);
    temp.push_back(arr[l]); 
    temp.push_back(arr[mid]);
    temp.push_back(arr[r]);
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
    int m=partition(arr,l,r);
    qsort(arr,l,m-1);
    qsort(arr,m+1,r);    
}


int main()
{
    int n;
    cin>>n;
    int a;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
    {
        a=((rand()%(n-1+1))+1);
        arr[i]=a;
    }
    qsort(arr, 0 , arr.size()-1);
    for(int i=0;i<arr.size();++i)
        cout<<arr[i]<<" ";    
    return 0;
}