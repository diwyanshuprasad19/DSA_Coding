ques:https://www.youtube.com/watch?v=BQ9E-2umSWc
best exapliantion:https://www.programiz.com/dsa/rabin-karp-algorithm


Case	Time Complexity	Space Complexity
Best Case	
𝑂
(
𝑛
+
𝑚
)
O(n+m)	
𝑂
(
1
)
O(1)
Worst Case	
𝑂
(
𝑛
⋅
𝑚
)
O(n⋅m)	
𝑂
(
1
)
O(1)

code:

/* Following program is a C++ implementation of Rabin Karp 
Algorithm given in the CLRS book */
#include <bits/stdc++.h> 
using namespace std; 

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 
		//quorient here as to make it managable
	// Calculate the hash value of pattern and first 
	// window of text 
	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	// Slide the pattern over text one by one 
	for (i = 0; i <= N - M; i++) 
	{ 

		// Check the hash values of current window of text 
		// and pattern. If the hash values match then only 
		// check for characters on by one 
		if ( p == t ) 
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M) 
				cout<<"Pattern found at index "<< i<<endl; 
		} 

		// Calculate hash value for next window of text: Remove 
		// leading digit, add trailing digit 
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			// We might get negative value of t, converting it 
			// to positive 
			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 

/* Driver code */
int main() 
{ 
	char txt[] = "GEEKS FOR GEEKS"; 
	char pat[] = "GEEK"; 
	int q = 101; // A prime number 
	search(pat, txt, q); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 



expaiantion for hash
The hash of a window in Rabin-Karp is computed as:

scss
Copy code
t = (character1 * d^(m-1) + character2 * d^(m-2) + ... + characterm * d^0) mod q
Where:

d is the base (e.g., 10).
q is a prime number used for modulo.
m is the size of the pattern/window.
Each character's contribution depends on its position (weighted by d).
Initial Window Hash ("123"):
For the window "123":

css
Copy code
t = (1 * d^2 + 2 * d^1 + 3 * d^0) mod q
Substituting:

lua
Copy code
t = (1 * 100 + 2 * 10 + 3) mod 13
t = (100 + 20 + 3) mod 13
t = 233 mod 13 = 6
Now, the hash value of the first window is t = 6.

Sliding to the Next Window ("233"):
We want the hash for "233" without recalculating it from scratch.

Step 1: Remove the Contribution of the First Character
The first character (1) in "123" contributes:

scss
Copy code
1 * d^(m-1) = 1 * 100 = 100
To "remove" this contribution from the hash t, subtract it:

makefile
Copy code
t_new = t - (1 * d^(m-1))
Substituting:

makefile
Copy code
t_new = 6 - 100 = -94
Step 2: Shift the Remaining Hash
After removing the first character, the remaining characters ("23") shift left by one position. Shifting is equivalent to multiplying the remaining hash by d:

makefile
Copy code
t_new = d * t_new
Substituting:

makefile
Copy code
t_new = 10 * (-94) = -940
Step 3: Add the Contribution of the New Character
The new character (3 from "233") enters the window at the last position. Its contribution is:

Copy code
3 * d^0 = 3
Add this to the shifted hash:

makefile
Copy code
t_new = d * (-94) + 3
Substituting:

makefile
Copy code
t_new = -940 + 3 = -937
Step 4: Take Modulo q
To keep the hash manageable and ensure it fits within the range 0 to q-1, take modulo q:

lua
Copy code
t_new = (-937) mod 13
Divide -937 by 13:

diff
Copy code
-937 ÷ 13 = -72 remainder 12
So:

makefile
Copy code
t_new = 12
Why Is This Equivalent to Recomputing the Hash?
If we recompute the hash for the new window "233" from scratch, we would do:

css
Copy code
t = (2 * d^2 + 3 * d^1 + 3 * d^0) mod q
Substituting:

lua
Copy code
t = (2 * 100 + 3 * 10 + 3) mod 13
t = (200 + 30 + 3) mod 13
t = 233 mod 13 = 12
This matches the value we computed using the rolling hash approach.

Summary:
The rolling hash saves time by reusing the previous hash value. Instead of recalculating the hash for each window, we:

Remove the contribution of the outgoing character.
Shift the remaining hash left by multiplying by d.
Add the contribution of the new incoming character.
Take modulo q to keep the hash manageable.
This makes the algorithm efficient and avoids recomputing the hash for every window from scratch.