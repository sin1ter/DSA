#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
    // Time complexity for this is O(2N) and space complexity is O(N).
}

vector<int> findMissingRepeatingNumbersUsingMath(vector<int> a) {
    long long n = a.size();
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for(int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long v1 = S - SN;
    long long v2 = S2 - S2N;
    v2 = v2 / v1;
    long long x = (v2 + v1) / 2;
    long long y = (v2 - v1) / 2;
    
    return {(int)x, (int)y};
    //Time complexity is O(N) and space complexity is O(1)
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans = findMissingRepeatingNumbersUsingMath(arr);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

