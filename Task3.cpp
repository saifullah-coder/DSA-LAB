#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    int maxRest = findMax(arr, size - 1);
    if (arr[size - 1] > maxRest) {
        return arr[size - 1];
    }
    else {
        return maxRest;
    }
}
int main() {
    int arr[] = { 12, 5, 18, 7, 3 };
    int size = 5;
    cout << "Maximum element: " << findMax(arr, size) << endl;
    return 0;
}