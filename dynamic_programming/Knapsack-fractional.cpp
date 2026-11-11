#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
};

bool compare(Item a, Item b) {
    return (double)a.profit / a.weight >
           (double)b.profit / b.weight;
}

int main() {
    int n, capacity;
    Item a[100];

    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> capacity;
    cout << "Enter weights and profits:\n";

    for (int i = 0; i < n; i++)
        cin >> a[i].weight >> a[i].profit;

    sort(a, a + n, compare);
    double totalProfit = 0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (a[i].weight <= capacity) {
            capacity -= a[i].weight;
            totalProfit += a[i].profit;
        } else {
            totalProfit += (double)a[i].profit *
                           capacity / a[i].weight;
            capacity = 0;
        }
    }

    cout << "Maximum profit: " << totalProfit;
    return 0;
}
