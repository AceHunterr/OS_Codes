#include <iostream>

using namespace std;

int main() {
    int n, m[20], i, j, sb[20], s[20], b[20][20], x;

    cout << "Enter no. of files: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter starting block and size of file " << i + 1 << ": ";
        cin >> sb[i] >> s[i];

        cout << "Enter blocks occupied by file " << i + 1 << ": ";
        cin >> m[i];

        cout << "Enter blocks of file " << i + 1 << ": ";
        for (j = 0; j < m[i]; j++) {
            cin >> b[i][j];
        }
    }

    cout << "\nFile\tIndex\tLength\n";
    for (i = 0; i < n; i++) {
        cout << i + 1 << "\t" << sb[i] << "\t" << m[i] << endl;
    }

    cout << "\nEnter file name: ";
    cin >> x;

    cout << "File name is: " << x << endl;
    i = x - 1;
    cout << "Index is: " << sb[i] << endl;
    cout << "Blocks occupied are: ";
    for (j = 0; j < m[i]; j++) {
        cout << b[i][j] << " ";
    }
    cout << endl;

    return 0;
}
