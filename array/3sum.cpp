//Given an array of N integer. The task is to return an array of all unique triplets such that i!= j, j!=k, k!= i and their sum is equal to zero.
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_force(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



vector<vector<int>> tbetter_force(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int k = -(arr[i] + arr[j]);
            if (hashset.find(k) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> two_pointer(vector<int>& arr, int n) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 and arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) {
                j++;
            }
            else if(sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp); 
                j++;
                k--;
                while(j < k and arr[j] == arr[j - 1]) j++;
                while(j < k and arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> result = two_pointer(arr, n);
    for(auto x: result) {
        cout << "[";
        for(auto i: x) {
            cout << i << ' ';
        }
        cout << "]";
    }
    cout << '\n';
}