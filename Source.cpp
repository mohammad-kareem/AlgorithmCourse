#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long factorialIterative(int n) {

    long long result = 1;
    
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    
    return result;
}

long long factorialRecursive(int n) {

    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorialRecursive(n - 1);
}

void measureExecutionTime(int n, const char* functionName) {

    auto start = high_resolution_clock::now();

    if (strcmp(functionName, "iterative") == 0) {
        factorialIterative(n);
    }

    else if (strcmp(functionName, "recursive") == 0) {
        factorialRecursive(n);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution time for " << functionName << " factorial(" << n << "): "
        << duration.count() << " microseconds" << endl;
}

int main() {



    for (int n : {5, 10, 20, 100, 500, 1000, 5000, 10000}) {
        measureExecutionTime(n, "iterative");
        measureExecutionTime(n, "recursive");
        cout << endl;
    }

    int largeValue = 10000;
    measureExecutionTime(largeValue, "iterative");

    // Commented the line below because observed stack overflow
    // measureExecutionTime(largeValue, "recursive");

    return 0;
}
