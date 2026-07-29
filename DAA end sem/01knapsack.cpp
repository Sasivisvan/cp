#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack (Container Loading) Problem
void maximizeProfit(int maxCapacity, vector<int> &weights,
                    vector<int> &profits) {
  int numItems = weights.size();

  // Create a 2D Dynamic Programming table
  // dp[i][w] will store the max profit for the first 'i' items with a weight
  // limit of 'w'
  vector<vector<int>> dp(numItems + 1, vector<int>(maxCapacity + 1, 0));

  // Step 1: Build the table from bottom up
  for (int i = 1; i <= numItems; i++) {
    for (int w = 1; w <= maxCapacity; w++) {
      // If the current item's weight is less than or equal to the current
      // capacity 'w'
      if (weights[i - 1] <= w) {
        // We choose the maximum of:
        // 1. Taking the item: Profit of current item + max profit of remaining
        // capacity
        // 2. Not taking the item: Max profit without this item
        dp[i][w] =
            max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
      } else {
        // If it's too heavy, we can't include it
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  // The maximum possible profit is stored in the bottom-right cell
  int maxProfit = dp[numItems][maxCapacity];
  cout << "Maximum Profit Achieved: $" << maxProfit << "\n\n";

  // Step 2: Backtrack to find out WHICH items were selected
  cout << "--- Items Loaded ---\n";
  int currentProfit = maxProfit;
  int currentWeightLimit = maxCapacity;

  for (int i = numItems; i > 0 && currentProfit > 0; i--) {
    // If the profit came from the row above, we didn't include item 'i'
    if (currentProfit == dp[i - 1][currentWeightLimit]) {
      continue;
    } else {
      // We included item 'i'
      cout << "Item " << i << " (Weight: " << weights[i - 1]
           << " tons, Profit: $" << profits[i - 1] << ")\n";

      // Deduct this item's profit and weight to trace the rest
      currentProfit -= profits[i - 1];
      currentWeightLimit -= weights[i - 1];
    }
  }
}

int main() {
  // Total weight the cargo ship/container can hold
  int maxCapacity = 50;

  // The available items waiting on the dock
  vector<int> weights = {10, 20, 30};
  vector<int> profits = {60, 100, 120};

  cout << "Container Maximum Capacity: " << maxCapacity << " tons\n\n";

  maximizeProfit(maxCapacity, weights, profits);

  return 0;
}
