#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int current;
	for(i=1;i<n;i++)
	{
		current=arr[i];
		j=i-1;
		while(arr[j]>current  && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=current;
	}
		for(i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	return 0;
}
