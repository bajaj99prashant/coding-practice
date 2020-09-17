#include <iostream>
using namespace std;

int* trivialApproach(int x, int arr[], int n){
    // a trivial approach is to store element in list while looping them and then telling wheather a pair is formed or not
    // the time complexity for the approach would be O(n^2) and space complexity would be O(n)
    // this approach can't be best because it doesn't use the fact that array is sorted and rotated
    int* result = new int[2];
    int pr[n] = {0};
    pr[0] = arr[0];
    for (int i = 1; i<n; i++){
        int j = 0;
        while(pr[j] > 0){
            if (pr[j] + arr[i] == x){
                result[0] = pr[j];
                result[1] = arr[i];
                return result;
            }
            j++;
        }
        pr[j] = arr[i];
    }

    result[0] = 0;
    result[1] = 0;

    return result;
    // it is brute force solution a better solution is always made with optimizations

}

int main () {
    int arr[] = {11, 15, 6, 8, 9, 10};
    int n = *(&arr+1) - arr;
    int* ans = trivialApproach(23, arr, n);
    if (ans[0] == 0 && ans[1] == 0 )
        cout << "not found";
    else
        cout << "pair is (" << ans[0] << ", " << ans[1] << ")";
    return 0;
}

/*
    Given an array that is sorted and then rotated around an unknown point.
    Find if the array has a pair with a given sum ‘x’. 
    It may be assumed that all elements in the array are distinct.
*/