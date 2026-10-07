#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int distance[100][100];

    cout << "Enter adjacency matrix:" << endl;
    cout << "Use 99999 for infinity." << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distance[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (distance[i][k] != 99999 &&
                    distance[k][j] != 99999 &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {

                    distance[i][j] =
                        distance[i][k] + distance[k][j];
                }
            }
        }
    }

    cout << "Shortest distance matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == 99999)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}