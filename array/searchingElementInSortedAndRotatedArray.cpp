#include <iostream>
using namespace std;

int BST(int arr[], int i, int j, int key){
    int mid = (j+i)/2;
    if (mid == i){
        return i;
    }
    if (key < arr[mid]){
        return BST(arr, i, mid, key);
    }else if (key > arr[mid]) {
        return BST(arr, mid+1, j, key);
    }else {
        return mid;
    }
}

int findingHighestElement (int arr[], int i, int j){
    int mid = (j+i)/2;
    if (i-1 > 0 && arr[i-1] > arr[i]){
        return i-1;
    }

    if (arr[i] <= arr[mid] && j-i > 1){
        return findingHighestElement(arr, mid+1, j);
    }else if (arr[i] > arr[mid] && j-i > 2){
        return findingHighestElement(arr, i, mid);
    }else if (j-i == 1){
        if (arr[i] > arr[j])
            return i;
        else 
            return j;
    }
}

int findElement(int arr[], int key, int i, int j, int maxIndex){
    int val;
    if (key < arr[i] && key <= arr[j] && maxIndex < j){
        val = BST(arr, maxIndex+1, j, key);
    }else if (key > arr[i] && key <= arr[maxIndex]){
        val = BST(arr, i, maxIndex, key);
    }else {
        val = j+1;
    }

    return val;
    
}

int main () {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = *(&arr+1) - arr;
    int maxIndex = findingHighestElement (arr, 0, n-1);
    int element = 7;
    int eleIndex =  findElement(arr, element, 0, n-1, maxIndex);
    if (eleIndex > n-1)
        cout << "Not found";
    else 
        cout << eleIndex;
}
 
// in ths algorithm we don't know by how much array is rotated, we only know it was sorted prior to rotation
// we have to find a key in array in O(logn) time complexity