Ques: https://www.geeksforgeeks.org/factorial-large-number/

Code:

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(int N) {
    vector<int> result;
    result.push_back(1);  // Initialize with 1

    for (int num = 2; num <= N; num++) {
        int carry = 0;
        for (int i = 0; i < result.size(); i++) {
            int product = result[i] * num + carry;
            result[i] = product % 10;        // store last digit
            carry = product / 10;            // keep the carry
        }
        // Store remaining carry
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    return result;  // result is in reverse order
}

int main() {
    int N = 100;
    vector<int> result = factorial(N);

    cout << "Factorial of " << N << " is: ";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}

Sample Input:

N = 5

✅ Sample Output:

Factorial of 5 is: 120

Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(N × D), where D = number of digits in result
Space Complexity	O(D) – because we store the result digit by digit