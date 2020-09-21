#include <iostream>
using namespace std;

int main () {
    // we can also do this space complexity of O(1) by just taking initial value of i as k and increment upto k+n
    // and taking i%n for the value.
    // current algorithm takes O(n) in time complexity and O(n) in space complaexity.
    int arr[] = {1, 3, 5, 7, 9};
    int size = *(&arr+1) - arr;
    int arrpro[2*size];
    for (int i = 0; i < 2*size; i++){
        int j = i%size;
        arrpro[i] = arr[j];
    }
    int n;
    cin >> n;
    while (n--){
        int k;
        cin >> k;
        k %= size;
        for (int i = 0; i < size; i++)
            cout << arrpro[k+i] << " ";
        
        cout << '\n';
    }

    // whenever see a question think as if we can improve the time complexity of it
    return 0;
}