#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int memo[101][1001];

int knapsack(int capacity, int weights[], int values[], int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (memo[n][capacity] != -1) {
        return memo[n][capacity];
    }

    if (weights[n - 1] > capacity) {
        memo[n][capacity] = knapsack(capacity, weights, values, n - 1);
    } else {
        memo[n][capacity] = max(values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1),
                                knapsack(capacity, weights, values, n - 1));
    }

    return memo[n][capacity];
}

int main() {
    int capacity = 10;
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int n = sizeof(weights) / sizeof(weights[0]);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            memo[i][j] = -1;
        }
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("Maximum value: %d\n", maxValue);

    return 0;
}

