Ques:https://www.geeksforgeeks.org/detect-if-two-integers-have-opposite-signs/

Code:

#include <iostream>
using namespace std;

bool oppositeSigns(int x, int y) {
    return ((x ^ y) < 0);
}

int main() {
    int x = 100, y = -100;
    if (oppositeSigns(x, y))
        cout << "Signs are opposite\n";
    else
        cout << "Signs are not opposite\n";
    return 0;
}


Time & Space Complexity
Metric	Value
Time Complexity	O(1)
Space Complexity	O(1)
