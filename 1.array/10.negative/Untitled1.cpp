#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[n];
	int low=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
		swap(arr[i],arr[low]);
		low++;
	    }
	}
		for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	
	
	return 0;
}
