#include <iostream>
using namespace std;

int main () {
    // time complexity of the algorithm is O(n)
    // space algorithm is O(1)
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int max_so_far = 0, max_ending_here = 0;
        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            if (i == 0)
                max_so_far = k;
            max_ending_here += k;
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }

        cout << max_so_far << '\n';
    }
}