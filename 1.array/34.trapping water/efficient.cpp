#include<bits/stdc++.h>
using namespace std;


int maxWater(int arr[],int n)
{
  int left[n];
  int right[n];
  left[0]=arr[0];
  int res=0;
  for(int i=1;i<n;i++ )
  {
  	left[i]=max(left[i-1],arr[i]);
  }
  right[n-1]=arr[n-1];
  for(int i=n-2;i>=0;i--)
  {
  	right[i]=max(right[i+1],arr[i]);
  }
  int var;
  for(int i=1;i<n-1;i++)
  {
  	var=min(left[i],right[i]);
  	if(var>arr[i]);
  	res+=var-arr[i];
  }
  return res;
	
}

int main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << maxWater(arr, n);
     
    return 0;
}
	
	

