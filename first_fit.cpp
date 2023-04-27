#include <iostream>
#include <cstring>

using namespace std;

void firstFit(int blockSizes[], int numBlocks, int processSizes[], int numProcesses) {
    int allocation[numProcesses];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                allocation[i] = j;
                blockSizes[j] -= processSizes[i];
                break;
            }
        }
    }

    cout << "Process No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < numProcesses; i++) {
        cout << " " << i+1 << "\t\t" << processSizes[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

int main() {
    int blockSizes[] = {100, 500, 200, 300, 600};
    int processSizes[] = {212, 417, 112, 426};
    int numBlocks = sizeof(blockSizes) / sizeof(blockSizes[0]);
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    firstFit(blockSizes, numBlocks, processSizes, numProcesses);

    return 0;
}