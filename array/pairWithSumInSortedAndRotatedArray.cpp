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

// am not coding but second approach would be to choose a number and apply binary search to the remaining part of the sum.
// time complexity would be O(nlogn) and space complexity is O(1) but iterative approach can be thought using while loop.
// but this approach only uses the fact that array is sorted and not rotated.

int findingIndexSmallest(int arr[], int n){
    int min = arr[0];
    int j = 0;
    for (int i = 0; i<n; i++){
        if (arr[i] < min){
            j = i;
            break;
        }
    }

    return j;
}

int* improvedSolution (int x, int arr[], int n){
    // improved solution is O(n) in time complexity but my solution is O(n) also in space complexity a better implementation 
    // than this might exist or I should say it exits.
    int index = findingIndexSmallest(arr, n);
    int* arr2 = new int[n];
    int k = n, b =0;
    while(k > 0){
        arr2[b] = arr[((b + index) >= n)? (b + index)%n : b + index]; 
        cout << arr2[b] << ' ';
        b++;
        k--;
    }

    int mid = (n-1)/2;
    int i = mid;
    int j = mid+1;
    int* ar = new int[2];

    while (i >= 0 && j <= n-1){
        if (arr2[i] + arr2[j] == x){
            ar[0] = arr2[i];
            ar[1] = arr2[j];
            return ar;
        }
        else if (arr2[i] + arr2[j] > x){
            i--;
        }
        else if (arr2[i] + arr2[j] < x){
            j++;
        }
    }

    ar[0] = 0;
    ar[1] = 0;

    return ar;
}

int main () {
    int arr[] = {11, 15, 6, 8, 9, 10};
    int n = *(&arr+1) - arr;
    int* ans = improvedSolution(17, arr, n);
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