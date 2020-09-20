/* we have to find max value sum(i*arr[i]) when array is allowed to be rotated */
/* brute force solution is O(n^2) */
#include <iostream>
using namespace std;

int maxValueSum(int arr[], int n){
    int sum = 0;
    int sumZero = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        sumZero += i*arr[i];
    }

    int sumPre = sumZero;
    int sumMax = sumZero;

    for (int i = 0; i < (n-1); i++){
        sumPre = (sum - arr[n-1-i]) + sumPre - (arr[n-1-i]*(n-1));
        if (sumPre > sumMax)
            sumMax = sumPre;
    }

    return sumMax; 
    // the time complexity for the algorithm is O(n) and space complexity is O(1)
    // what we did is we found the equation sum depending upon previous sum by calculating how much it changed on a rotation.
}

int main() {
    int arr[] = {3, 2, 1};
    int n = *(&arr+1) - arr;
    int result = maxValueSum(arr, n);
    cout << result;
    return 0;
}