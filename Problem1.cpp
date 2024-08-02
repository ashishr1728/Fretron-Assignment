// No accident please

#include <bits/stdc++.h>
using namespace std;
const int n = 10;

// Function to draw the grid and paths
void path(const vector<vector<pair<int, int>>>& flights) {
    // Create an empty grid
    char mat[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = '.';
        }
    }

    // Draw each flight path
    for (size_t i = 0; i < flights.size(); ++i) {
        char m = 'A' + i; // Different marker m for each flight
        for (size_t j = 0; j < flights[i].size() - 1; ++j) {
            int x1 = flights[i][j].first;
            int y1 = flights[i][j].second;
            int x2 = flights[i][j + 1].first;
            int y2 = flights[i][j + 1].second;

            // Draw the starting point
            mat[y1][x1] = m;

            // Draw horizontal line
            if (y1 == y2) {
                for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
                    mat[y1][x] = '-';
                }
            }
            // Draw vertical line
            else if (x1 == x2) {
                for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
                    mat[y][x1] = '|';
                }
            }
            // Draw diagonal line
            else {
                int x_axis = (x2 > x1) ? 1 : -1;
                int y_axis = (y2 > y1) ? 1 : -1;
                int x = x1;
                int y = y1;
                while (x != x2 || y != y2) {
                    mat[y][x] = '*';
                    if (x != x2) x += x_axis;
                    if (y != y2) y += y_axis;
                }
                mat[y2][x2] = m; // Mark the end point
            }
        }
    }

    // Print the grid
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    // Define flight paths as vectors of pairs (coordinates)
    vector<vector<pair<int, int>>> flights = {
        {{1, 1}, {2, 2}, {3, 3}}, // Flight 1
        {{1, 1}, {2, 4}, {3, 2}}, // Flight 2
        {{1, 1}, {4, 2}, {3, 4}}  // Flight 3
    };

    // Draw the grid with the flight paths
    path(flights);

    return 0;
}