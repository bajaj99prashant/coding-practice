#include <iostream>
using namespace std;

void arrayRotationMyApproach (int arr[], int d, int n){
    // my tc is O(d) but this is not exact rotation
    // think of it like we have to rotate a certain portion of array only
    // if memory of array is not an issue
    // apart from the same array we can create the temporary array of d elements and shift elements in original array but t.c is O(n)
    for(int i = 0; i < d; i++)
        arr[n+i] = arr[i];

    // printing elements
    for(int i = d; i < n+d; i++)
        cout << arr[i] << ' ';
}

void jugglingAlgorithm (int arr[], int d, int n){
    // what this algortihm does is it shifts the array by gcd(n, d) times in every inner loop and runs outer loop by d times
    // t.c is O(n/gcd(n, d)*d) 

    // calculating gcd
    int num = n, div = d, rem = num%div;
    while (rem != 0){
        num = div;
        div = rem;
        rem = num%div;
    }
    int gcd = div;
    int shifEle = n/gcd;

    // shifting elements
    for (int i = 0; i < d; i++){
        int temp = arr[i];
        int k = i;
        for (int j = 0; j < shifEle; j++){
            if (j == shifEle-1)
                arr[k] = temp;
            else
                arr[k] = arr[k+d];
            k += d;
        }
    }

    // printing elements modifed
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

}

int main() {
    int n;
    cin >> n;
    int arr[100] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int d;
    cin >> d;
    jugglingAlgorithm(arr, d, n);
    return 0;
}

// another approach is looping outer loop d times and shifting n-1 elements in inner loop t.c O(n*d)