Ques:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

Expaliantion:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/5816678/video-sell-a-stock-immediately/

Code:

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={1, 5, 2, 3, 7, 6, 4, 5};
	int n=sizeof(arr)/sizeof(arr[0]);
	 int profit=0;
	 int j=0;
	 for(int i=1;i<n;i++)
	 {
	 	if(arr[i-1]>arr[i])
	 	j=i;
	 	
	 	if(arr[i-1]<=arr[i] && (i+1==n || arr[i]>arr[i+1]))
	 	profit+=(arr[i]-arr[j]);
	 }
	
	cout<<profit;
	
	return 0;
}

O(n)
