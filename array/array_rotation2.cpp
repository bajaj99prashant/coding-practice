#include <iostream>
using namespace std;

void reverseArray (int arr[], int i, int j){
    int a = 0;
    while(i+a < j-1-a){
        int temp = arr[i+a];
        arr[i+a] = arr[j-1-a];
        arr[j-1-a] = temp;
        a++;
    }
}

void reversalAlgorithm(int arr[], int n, int d){
    // reversal algorithm for array rotation uses the fact to reverse two parts of array and than reversing the whole array.
    // time complexity is O(n)
    reverseArray(arr, 0, d);
    reverseArray(arr, d, n);
    reverseArray(arr, 0, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
}
 
int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = *(&arr+1) - arr;
    int d = 5;
    reversalAlgorithm(arr, n, d);
    return 0;
}