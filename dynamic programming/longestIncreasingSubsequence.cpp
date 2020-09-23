#include <iostream>
using namespace std;

int solution(int arr[], int n){
    // what i did is i just concerned about state i, at i I tried to find max length for which i can include i, finding transition was a tough part.
    // time complexity of algorithm is O(n^2) let's see if we can improve it.
    int dp[n] = {0};
    dp[0] = 1;
    int mj = dp[0];
    for (int i = 0; i < n; i++){
        int max = 0;
        for (int j = i-1; j >= 0; j-- ){
            if (arr[i] > arr[j] & max < dp[j])
                max = dp[j];
        }
        dp[i] = max+1;
        if (dp[i] > mj)
            mj = dp[i];
    }

    return mj;
}

int main() {
    int arr[] = {50, 3, 10, 7, 40, 80};
    int n = *(&arr+1) - arr;
    int result = solution(arr, n);
    cout << result;
    return 0;
}

/* the question is finding longest subsequence from sequence such that all elements are sorted */
// correct way to approach dp solution is to think what is important so far.
/* state at every point should be independent of what is yet to come or to be computed on the basis of state at present */