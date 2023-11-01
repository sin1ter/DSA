// Find the Majority Element that occurs more than N / 2 times.
#include<bits/stdc++.h>
using namespace std;

// int majority_element(int arr[], int n) {
//     map<int, int> mpp;
//     for(int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }
//     n = n / 2;
//     for(auto x: mpp) {
//         if(x.second > n) {
//             return x.first;
//         }
//     }
//     return -1;
// }

int moores_voting_algo(int arr[], int n) { // for this time complexity is O(n) and space complexity is O(1).
    int count = 0;
    int element;
    for(int i = 0; i < n; i++) { 
        if(count == 0) {
            count = 1;
            element = arr[i];
        }
        else if(element == arr[i]) {
            count++;
        }
        else count--;
    }
    int count1 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == element) count++;
    }
    if(count1 > (n / 2)) return element;
        return element;
        
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k = moores_voting_algo(arr, n);
    cout << k;
}
