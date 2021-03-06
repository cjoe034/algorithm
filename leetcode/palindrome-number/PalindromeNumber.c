#include <stdbool.h>    // bool
#include <stdio.h>      //printf

bool isPalindrome(int x) {
    if (x < 0) { return false; }
    int  k = 1;
    while (x / k >= 10) {
        k *= 10;
    }
    while (x / k == x % 10) {
        x = x - (x/k)*k; // remove the highest number
        x /= 10; // remove the lowest number
        k = k / 100;
        if (k <= 1) { return true; }
    }
    return false;
}
int main(int argc, char const *argv[]) {
    int nums[] = {
        0, 1, 9, // less than 10
        -2, -101, // negtive
        101, 1001, 121, 1221, // old and even
        10, 100, 100101 // not palindrome
    };
    bool results[] = {
        true, true, true, // less than 10
        false, false, // negtive is not palindrom
        true, true, true, true, // old and even
        false, false, false
    };
    int count = sizeof(nums)/sizeof(nums[0]);
    int failed = 0;
    bool result;
    int i;
    for (i = 0; i < count; i++) {
        result = isPalindrome(nums[i]);
        if (result != results[i]) {
            failed++;
            printf("Test: %d, expect: %d, while returned: %d\n", nums[i], results[i], result);
        }
    }
    printf("Test %d cases, %d success, %d failed\n", count, (count-failed), failed);
}
