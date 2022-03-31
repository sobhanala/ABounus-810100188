#include <iostream>
#include <vector>
using namespace std;
void initialize_farm(int Row, int Column, vector<vector<int>>& farm) {
    farm = vector<vector<int>>(Row, vector<int>(Column));
}
void get_input(int& Row, int& Column, vector<vector<int>> &farm) {
    cin >> Row >> Column;
    int product;
    initialize_farm(Row, Column,farm);
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            cin >> product;
            farm[i][j] = product;
        }
    }
}
long int Sum (vector<int> farm) {
    long int sum = 0;
    for (int i = 0; i < farm.size(); i++)
        sum =sum+ farm[i];
    return sum;
}
pair<int, int> find_max_row(int Row, vector<vector<int>> farm) {
    vector<long int> row_sums;
    pair<int, int> answer;
    int max_row = 0;
    long int sum = 0;
    int temp_row = 0;
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
    answer.first = max_row;
    answer.second = temp_row;
    return answer;
}
pair<int, int> find_max_column(int Row,int Column,vector<vector<int>> farm) {
    int max_column = 0;
    int temp_column = 0;
    long int sum = 0;
    pair <int, int> value;
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
    value.first = max_column;
    value.second = temp_column;
    return value;
}
void harvesting_column(int Row,int temp_column, vector<vector<int>>& farm) {
    for (int i = 0; i < Row; i++) {
        farm[i][temp_column] = 0;
    }
}
void harvesting_row(int Column, int temp_row, vector<vector<int>>& farm) {
    for (int j = 0; j < Column; j++) {
        farm[temp_row][j] = 0;
    }
}
long int do_moves(int Row, int Column, vector<vector<int>>&farm) {
    long int harvest = 0;
    long int sum = 0;
    int max_row = 0;
    int max_column = 0;
    int temp_row = 0;
    int temp_column = 0;
    for (int move = 0; move < 4; move++) {
        vector<long int> row_sums;
        max_row=find_max_row(Row, farm).first;
        temp_row = find_max_row(Row, farm).second;
        max_column = find_max_column(Row, Column, farm).first;
        temp_column= find_max_column(Row, Column, farm).second;
        if (max_column > max_row) {
            harvest += max_column;
            harvesting_column(Row, temp_column, farm);
        }
        else {
            harvest += max_row;
            harvesting_row(Column, temp_row, farm);
        } 
        temp_row = 0;
        temp_column = 0;
        max_column = 0;
        max_row = 0;
    }
    return harvest;
}
int main() {
    int Row, Column;
    vector<vector<int>> farm;
    long int harvest = 0;
    get_input(Row, Column,farm);
    cout << do_moves(Row, Column,farm);
    return 0;
} 
