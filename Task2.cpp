#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int left, int right) {
    if (left > right) {
        return true;
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string s1 = "abcddcba";
    string s2 = "hello";

    if (isPalindrome(s1, 0, s1.size() - 1)) {
        cout << s1 << " is a palindrome." << endl;
    }
    else {
        cout << s1 << " is not a palindrome." << endl;
    }
    if (isPalindrome(s2, 0, s2.size() - 1)) {
        cout << s2 << " is a palindrome." << endl;
    }
    else {
        cout << s2 << " is not a palindrome." << endl;
    }
    return 0;
}