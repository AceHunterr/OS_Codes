#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

// Shared variables
atomic<int> turn{0};
atomic<bool> flag0{false}, flag1{false};

void p0() {
    flag0 = true;
    turn = 1;
    while (flag1 && turn == 1) {}
    // Critical section
    cout << "Process 0 entered critical section" << endl;
    // End of critical section
    flag0 = false;
}

void p1() {
    flag1 = true;
    turn = 0;
    while (flag0 && turn == 0) {}
    // Critical section
    cout << "Process 1 entered critical section" << endl;
    // End of critical section
    flag1 = false;
}

int main() 
{
    // Create processes
    thread t0(p0);
    thread t1(p1);

    // Join processes
    t0.join();
    t1.join();

    return 0;
}