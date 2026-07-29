#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Define a structure to hold item details together
struct Item {
  int profit;
  int weight;

  // Constructor
  Item(int p, int w) : profit(p), weight(w) {}
};

// Custom comparison function for the greedy strategy
// Sorts items by their profit-to-weight ratio in descending order
bool compareItems(Item a, Item b) {
  double ratio1 = (double)a.profit / (double)a.weight;
  double ratio2 = (double)b.profit / (double)b.weight;
  return ratio1 > ratio2;
}

// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int capacity, vector<Item> &items) {
  // Step 1 & 2: Sort items by ratio (highest to lowest)
  sort(items.begin(), items.end(), compareItems);

  double totalProfit = 0.0;
  int currentWeight = 0;

  cout << "--- Loading Sequence ---\n";

  // Step 3 & 4: Iterate through sorted items
  for (int i = 0; i < items.size(); i++) {
    // If the whole item can fit, take it all
    if (currentWeight + items[i].weight <= capacity) {
      currentWeight += items[i].weight;
      totalProfit += items[i].profit;
      cout << "Took 100% of item " << i + 1 << " (Weight: " << items[i].weight
           << ", Profit: $" << items[i].profit << ")\n";
    }
    // If it can't fit entirely, take the exact fraction that fills the bag
    else {
      int remainingCapacity = capacity - currentWeight;
      double fraction = (double)remainingCapacity / (double)items[i].weight;

      totalProfit += items[i].profit * fraction;
      cout << "Took " << (fraction * 100) << "% of item " << i + 1
           << " (Weight taken: " << remainingCapacity << ", Profit added: $"
           << (items[i].profit * fraction) << ")\n";

      // The knapsack is now exactly full, so we stop
      break;
    }
  }

  return totalProfit;
}

int main() {
  int capacity = 50;

  // Creating items: {profit, weight}
  vector<Item> items = {
      Item(60, 10),  // Ratio: 6
      Item(100, 20), // Ratio: 5
      Item(120, 30)  // Ratio: 4
  };

  cout << "Knapsack Capacity: " << capacity << "\n\n";

  double maxProfit = fractionalKnapsack(capacity, items);

  cout << "\nMaximum Total Profit: $" << maxProfit << "\n";

  return 0;
}
