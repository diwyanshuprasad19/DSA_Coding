Ques:https://www.youtube.com/watch?v=wiDLcGxhh80

sol:https://www.youtube.com/watch?v=wiDLcGxhh80

#include<bits/stdc++.h>
using namespace std;
/*
 single element always palindrome
 121 from left and right same hence palindrome
 12345 max no of merge function will be n-1 n is size;
 1+2->3+3->6+4->10+5 see 4 merge there but we need minimum

now here logic take 2 pointer and if same just i++ and j--;
ifarr[i]<arr[j] means that arr[i is smaller hence if we add it with next i+1 it might come same as arr[j] 
same logic for arr[j smaller

*/

check on youtube


int main()
{
	 int arr[] = {15, 4, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
	int i=0,j=n-1;
	int ans=0;
	while(i<=j)
	{
		if(arr[i]==arr[j])
		{
			i++;
			j--;
		}
		else if(arr[i]<arr[j])
		{
			i++;
			arr[i]=arr[i]+arr[i-1];
			ans++;
		}
		else
		{
			j--;
			arr[j]=arr[j]+arr[j+1];
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

Sample Inputs and Outputs
Sample Input 1:

ini
Copy
Edit
arr = {15, 4, 15}
Sample Output 1:

Copy
Edit
0
Explanation: Already palindrome, no merges needed.

Sample Input 2:

ini
Copy
Edit
arr = {1, 4, 5, 1}
Sample Output 2:

Copy
Edit
1
Explanation:

merge 4 + 5 → {1, 9, 1} → becomes palindrome.

Sample Input 3:

ini
Copy
Edit
arr = {11, 14, 15, 99}
Sample Output 3:

Copy
Edit
3
Explanation:


Time and Space Complexity
Metric	Complexity
Time Complexity	O(n) → single pass with two pointers
Space Complexity	O(1) → no extra space, in-place array updates