#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

/**
 * Calculate the n-th Fibonacci term recursively.
 *
 * @param n The index of the term in the sequence.
 * @return The value of the n-th term.
 */
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/**
 * Calculate the n-th Fibonacci term iteratively.
 *
 * @param n The index of the term in the sequence.
 * @return The value of the n-th term.
 */
int fibonacciIterative(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

/**
 * Measure the execution time of a function for Fibonacci calculation.
 *
 * @param function Pointer to the function that calculates Fibonacci (recursive or iterative).
 * @param timeLimit The maximum execution time in seconds.
 * @return The number of terms calculated within the time limit.
 */
int measureTime(int (*function)(int), int timeLimit) {
    auto start = steady_clock::now();
    int n = 0;
    while (true) {
        if (duration_cast<seconds>(steady_clock::now() - start).count() >= timeLimit)
            break;
        function(n++);
    }

    return n;
}

/**
 * Main function.
 */
int main() {
    const int intervals[] = {15, 30, 45, 60, 75, 90, 105, 120};
    const int numIntervals = sizeof(intervals) / sizeof(intervals[0]);

    cout << "Time (s)\tRecursive\tIterative" << endl;

    // For each time interval
    for (int i = 0; i < numIntervals; ++i) {
        int timeLimit = intervals[i];
        int recursiveNumbers = measureTime(fibonacciRecursive, timeLimit);
        int iterativeNumbers = measureTime(fibonacciIterative, timeLimit);

        // Print the time and the number of terms calculated for each method
        cout << timeLimit << "\t\t" << recursiveNumbers << "\t\t" << iterativeNumbers << endl;
    }

    return 0;
}
