#include <stdio.h>

int main()
{
    int num_processes = 5;
    int num_resources = 3;
    int i, j, k;

    int allocation_matrix[5][3] = {
        { 0, 0, 1 }, // P0
        { 3, 0, 0 }, // P1
        { 1, 0, 1 }, // P2
        { 2, 3, 2 }, // P3
        { 0, 0, 3 }  // P4
    };

    int max_matrix[5][3] = {
        { 7, 6, 3 }, // P0
        { 3, 2, 2 }, // P1
        { 8, 0, 2 }, // P2
        { 2, 1, 2 }, // P3
        { 5, 2, 3 }  // P4
    };

    int available_resources[3] = { 2, 3, 2 };

    int finish[num_processes];
    for (k = 0; k < num_processes; k++) {
        finish[k] = 0;
    }

    int need[num_processes][num_resources];
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_resources; j++) {
            need[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
        }
    }

    int safe_sequence[num_processes];
    int ind = 0;

    for (k = 0; k < num_processes; k++) {
        for (i = 0; i < num_processes; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > available_resources[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safe_sequence[ind++] = i;
                    for (j = 0; j < num_resources; j++) {
                        available_resources[j] += allocation_matrix[i][j];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    printf("The safe sequence is: ");
    for (i = 0; i < num_processes - 1; i++) {
        printf("P%d -> ", safe_sequence[i]);
    }
    printf("P%d", safe_sequence[num_processes - 1]);
    
    return 0;
}