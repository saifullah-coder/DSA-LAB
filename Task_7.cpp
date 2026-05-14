#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    if (size == 1)
        return arr[0];
    int maxRest = findMax(arr, size - 1);
    return arr[size - 1] > maxRest ? arr[size - 1] : maxRest;
}

int findMaxIndex(int arr[], int size, int maxVal, int i = 0) {
    if (arr[i] == maxVal)
        return i;
    return findMaxIndex(arr, size, maxVal, i + 1);
}

bool subsetSum(int arr[], int size, int target, int index = 0) {
    if (target == 0)
        return true;
    if (index == size || target < 0)
        return false;
    return subsetSum(arr, size, target - arr[index], index + 1) ||
           subsetSum(arr, size, target, index + 1);
}

void removeElement(int arr[], int& size, int index) {
    if (index == size - 1) {
        size--;
        return;
    }
    arr[index] = arr[index + 1];
    removeElement(arr, size, index + 1);
    size--;
}

int findMagicNumber(int arr[], int size) {
    if (size == 0)
        return -1;

    int maxVal = findMax(arr, size);
    int maxIdx = findMaxIndex(arr, size, maxVal);

    int remaining[100];
    int remainingSize = 0;

    for (int i = 0; i < size; i++) {
        if (i != maxIdx)
            remaining[remainingSize++] = arr[i];
    }

    if (subsetSum(remaining, remainingSize, maxVal))
        return maxVal;

    int newArr[100];
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (i != maxIdx)
            newArr[newSize++] = arr[i];
    }

    return findMagicNumber(newArr, newSize);
}

int main() {
    int arr[] = {2, 3, 5, 8, 13};
    int size = 5;
    int result = findMagicNumber(arr, size);
    if (result != -1)
        cout << "Magic number: " << result << endl;
    else
        cout << "No magic number found." << endl;
    return 0;
}
