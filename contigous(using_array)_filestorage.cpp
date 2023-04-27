					
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, i, j, x;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> b(n), sb(n), t(n);
    vector<vector<int>> c(n, vector<int>());

    for (i = 0; i < n; i++) {
        cout << "Enter the number of blocks occupied by file " << i + 1 << ": ";
        cin >> b[i];
        cout << "Enter the starting block of file " << i + 1 << ": ";
        cin >> sb[i];
        t[i] = sb[i];
        for (j = 0; j < b[i]; j++) {
            c[i].push_back(sb[i]++);
        }
    }

    cout << "Filename\tStart block\tLength\n";
    for (i = 0; i < n; i++) {
        cout << setw(8) << i + 1 << "\t" << setw(8) << t[i] << "\t" << setw(6) << b[i] << "\n";
    }

    cout << "Enter file name: ";
    cin >> x;
    cout << "File name is: " << x << "\n";
    cout << "Length is: " << b[x - 1] << "\n";
    cout << "Blocks occupied: ";
    for (i = 0; i < b[x - 1]; i++) {
        cout << c[x - 1][i] << " ";
    }
    cout << "\n";

    return 0;
}