#include <iostream>
using namespace std;

string diamond(int size) {
    string result = "";
    // Up
    for (int i = 1; i <= size; i++) {
        for (int p = 0; p < (size - i); p++) {
            result += ' ';
        }
        for (int j = 0; j < (2 * i - 1); j++) {
            result += '*';
        }
        result += '\n';
    }
    // Down
    for (int i = size - 1; i >= 1; i--) {
        for (int p = 0; p < size - i; p++) {
            result += ' ';
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            result += '*';
        }
        result += '\n';
    }
    return result;
}

int main(void) {
    cout << "Enter the size of the diamond: ";
    int size = 10;
    cin >> size;
    cout << diamond(size);
    return 0;
}