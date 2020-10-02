#include <iostream>
using namespace std;

// in this question we have to merge two sorted arrays without any extra space
// we have to merge both the arrays in place and sort them
 
int BST(int arr[], int low, int high, int val){
    if (low == high){
        return low;
    }
    int mid = (high-low)/2;
    if (arr[mid] < val && arr[mid+1] > val)
        return mid;
    if (arr[mid] < val)
        return BST(arr, mid+1, high, val);
    if (arr[mid] >= val)
        return BST(arr, low, mid, val);
}

void merge(int arr1[], int arr2[], int n, int m){
    // time complexity of the given algorithm is O(n*log(m)) and space complexity is O(1)
    int* first = arr1;
    int* second = arr2;
    int maxi = n, maxj = m;
    int i = 0, j = 0;

    /* what doesn't works here is the fact that every element in j will be sorted after one iteration */
    // we have to maintain the sorting order in second array in order to merge the arrays.
    // what we can do is maintain the order of elements to be changed in the order.

    while (i < maxi){
        if (second[j] < first[i]){
            int temp = first[i];
            first[i] = second[j];
            int k = BST(second, 0, maxj-1, temp);
            for (int a = 0; a < k; a++)
                second[a] = second[a+1];
            second[k] = temp;
        }
            i++;
    }

    for (i = 0; i < maxi; i++)
        cout << first[i] << ' ';
    for (j = 0; j < maxj; j++)
        cout << second[j] << ' ';
}

int main() {
    int arr1[] = {10, 12};
    int n = *(&arr1+1) - arr1;
    int arr2[] = {5, 18, 20};
    int m = *(&arr2+1) - arr2;

    merge(arr1, arr2, n, m);

    return 0;
}