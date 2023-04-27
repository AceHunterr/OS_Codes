#include<iostream>
using namespace std;

struct File {
    string name;
    int start, size, blocks[10];
}; 

int main() {
    int i, j, n;

    cout << "Enter the number of files: ";
    cin >> n;

    File files[n]; 
    for(i = 0; i < n; i++) {
        cout << "Enter file name: ";
        cin >> files[i].name;

        cout << "Enter starting block: ";
        cin >> files[i].start;

        files[i].blocks[0] = files[i].start; 

        cout << "Enter number of blocks: ";
        cin >> files[i].size;

        cout << "Enter block numbers: ";
        for(j = 1; j <= files[i].size; j++) {
            cin >> files[i].blocks[j];
        }
    }

    cout << "File\tStart\tSize\tBlocks\n";

    for(i = 0; i < n; i++) {
        cout << files[i].name << "\t" << files[i].start << "\t" << files[i].size << "\t";

        for(j = 0; j <= files[i].size; j++) {
            cout << files[i].blocks[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
