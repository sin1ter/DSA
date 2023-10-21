#include <bits/stdc++.h>
using namespace std;
/*int missing_number_usin_hash(int arr[], int n) {
    int mp[n + 1] = {0};
    for(int i = 0; i < n - 1; i++) {
        mp[arr[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        if(mp[i] == 0) {
            return i;
        }
    }
    return -1;
}*/
int missing_number(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }
    n = n * (n + 1) / 2;    
    return n - sum;
}
int missing_number_xor(int arr[], int n) {
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
        xor1 ^= (i + 1);
    }
    xor1 ^= n;
    return xor1 ^ xor2;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n - 1; i++) cin >> arr[i];
    // cout << missing_number_usin_hash(arr, n); // time complexity for this O(2n) and space complexity is O(n) for the hash
    // cout << missing_number(arr, n); //Time complexity for this is O(n) and space complexity for this is O(1) but because of the summation it will take space more which will not be stored in 'int' so have to use long long that's why xor is better.
    cout << missing_number_xor(arr, n); //Time complexity for this is O(n) and space complexity for this also O(1)
        return 0;
}
