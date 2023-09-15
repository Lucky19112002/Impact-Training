#include <bits/stdc++.h>
using namespace std;

int BinaryAdd(int a, int b) {
    int ans = 0;
    int carry = 0;

    while (a > 0 || b > 0 || carry > 0) {
        int bitA = a % 2;
        int bitB = b % 2;
        int sum = bitA + bitB + carry;

        ans = ans * 10 + (sum % 2);
        carry = sum / 2;

        a /= 2;
        b /= 2;
    }

    // Reverse the answer
    int reversedAns = 0;
    while (ans > 0) {
        reversedAns = reversedAns * 10 + (ans % 10);
        ans /= 10;
    }

    return reversedAns;
}

int main() {
    int a, b;
    cout << "Enter two binary numbers: ";
    cin >> a >> b;

    int result = BinaryAdd(a, b);

    cout << "Sum of the binary numbers: " << result << endl;

    return 0;
}
