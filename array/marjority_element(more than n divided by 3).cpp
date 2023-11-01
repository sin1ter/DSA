#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElementUsingMap(vector<int>& arr, int n) {
    map<int, int> mpp;
    vector<int> ans;
    int occur = int(n / 3) + 1;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == occur) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// using the extended Boyer Moore's Voting algo
vector<int> majorityElementBoyersMoorVotingAlgo(vector<int>& arr, int n){   
    int element1 = 0, element2 = 0;
    int count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(count1 == 0 and arr[i] != element2) {
            count1 = 1;
            element1 = arr[i];
        }
        else if(count2 == 0 and arr[i] != element1) {
            count2 = 0;
            element2 = arr[i];
        }
        else if(arr[i] == element1) {
            count1++;
        }
        else if(arr[i] == element2) {
            count2++;
        }
        else {
            count1--, count2--;
        }
    }
    vector<int> ans;
    count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == element1) count1++;
        if(arr[i] == element2) count2++;
    }
    int occur = int(n / 3) + 1;
    if(count1 >= occur) ans.push_back(element1);
    if(count2 >= occur) ans.push_back(element2);

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = majorityElementBoyersMoorVotingAlgo(arr, n);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
}