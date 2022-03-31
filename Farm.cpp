#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> farm;
long int Sum (vector<int> farm) {
    long int sum = 0;
    for (int i = 0; i < farm.size(); i++)
        sum =sum+ farm[i];
    return sum;
}
void solve(int Row, int Column,long int& harvest) {
    long int sum = 0;
    int max_row = 0;
    int max_column = 0;
    int temp_row = 0;
    int temp_column = 0;
    for (int move = 0; move < 4; move++) {
        vector<long int> row_sums;

        for (int i = 0; i < Row; i++) {
            sum = Sum(farm[i]);
            row_sums.push_back(sum);
            sum = 0;
        }

        for (int i = 0; i < Row; i++) {
            if (row_sums[i] > max_row) {
                max_row = row_sums[i];
                temp_row = i;
            }
        }

        for (int j = 0; j < Column; j++) {
            for (int i = 0; i < Row; i++) {
                sum += farm[i][j];
            }
            if (sum > max_column) {
                max_column = sum;
                temp_column = j;
            }
            sum = 0;
        }
        if (max_column > max_row) {
            harvest += max_column;
            for (int i = 0; i < Row; i++) {
                farm[i][temp_column] = 0;
            }
        }
        else {
            harvest += max_row;
            for (int j = 0; j < Column; j++) {
                farm[temp_row][j] = 0;
            }
        }
        temp_row = 0;
        temp_column = 0;
        max_column = 0;
        max_row = 0;
    }
}
int main() {
    int Row, Column;
    int product;
    long int harvest = 0;
    cin >> Row >> Column;
    farm = vector<vector<int>>(Row, vector<int>(Column));
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            cin >> product;
            farm[i][j] = product;
        }
    }
    solve(Row, Column, harvest);
    cout << harvest;
    return 0;
} 
