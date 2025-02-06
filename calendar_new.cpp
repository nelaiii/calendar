#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cassert>
#include <windows.h>
using namespace std;

// тестовый набор
//vector <pair <int, int>> tested_set = { {1, 1919},{2, 1939},  {2, 2024}, {7, 1990}, {1, 2000}, {8, 2040}, {12, 1936}, {4, 2032}, {10, 1975}, {11, 1964}, {6, 2061}, {9, 2015}, {4, 1953}, {2, 2051}, {7, 2005}, {1, 1920}, {3, 1922}, {12, 2069} };
//vector <int> num_of_days_check = { 31, 28, 29, 31, 31, 31, 31, 30, 31, 30, 30, 30, 30, 28,31, 31, 31, 31 };
//vector <int> weekday_check = { 2, 2, 3, 6, 5, 2, 1, 3, 2, 6, 2, 1, 2, 2, 4, 3, 2, 6};
//Ямщикова
int leap_year(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
//Велиев Февзи
int number_of_days_in_a_month(int month, int year) {
    vector <int> num = {31, 28  + leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return num[month-1];
}

//Фесенкo Елизавета
int weekday(int month, int year) {
    int result = 2;
    if (month -1 == 0 and year == 1919){
        return result;
    }
    while (month-1 > 0) {
        result += number_of_days_in_a_month(month-1, year);
        month--;
    }
    while (year -1 > 1919) {
        if (leap_year(year-1)) { result += 366; }
        else { result += 365; }
        year--;
    }
    return (result+1)%7;
}

//Ямщикова Наталья
void calendar(int month, int year) {
    int k = weekday(month, year);
    int n = number_of_days_in_a_month(month, year);
    string months[] = {"ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ","НОЯБРЬ", "ДЕКАБРЬ"};
    cout << months[month - 1] << " " << year << endl;
    string days = " ПН  ВТ  СР  ЧТ  ПТ  СБ  ВС";
    cout << days << endl;
    for (int j = 0; j < k; j++) {
        cout << "   " << " ";
    }
    for (int i = 0; i < n; i++) {
        if (k != 6) {
            if (i + 1 < 10) {
                cout << "  " << i+1 << " ";
            } else cout << " " << i+1 << " ";
        } else {
            cout << " " << i+1 << endl;
            k = -1;
        }
        k++;
    }
}
// тестирующая функция
//void testing_num_days() {
   // for (size_t i = 0; i < tested_set.size(); ++i)
      //  assert((number_of_days_in_a_month(tested_set[i].first, tested_set[i].second) == num_of_days_check[i]) && (weekday(tested_set[i].first, tested_set[i].second) == weekday_check[i]));
    //cout << "Тесты пройдены!" << endl;
//}
//Ямщикова + Фесенко
void check_and_run(string month, string year){
    int flag = 1, flag_for_str, count;
    while (flag) {
        count = 0, flag_for_str = 1;
        while (month[count] != '\0') {
            if (month[count] < '0' || month[count] > '9') {flag_for_str = 0; }
            count++;}
        count = 0;
        while (year[count] != '\0') {
            if (year[count] < '0' || year[count] > '9') {flag_for_str = 0; }
            count++; }
        if (flag_for_str) {
            if (stoi(month) < 1 or stoi(month) > 12 or stoi(year) < 1919 or stoi(year) > 2069) {
                cout << "Введенные данные некорректны. Попробуйте снова:" << endl;
                cin >> month >> year;
                flag = 1;
            } else {calendar(stoi(month), stoi(year));; flag = 0;}
        } else {cout << "Введенные данные некорректны. Попробуйте снова:" << endl;
            cin >> month >> year;}
    }
}
// тестовые наборы для gcd и lcm
vector<pair<int, int>> tested_set = {{1,    7},
                                     {8,    98},
                                     {1234, 33}};
vector<int> gcd_check = {1, 2, 1};
vector<int> lcm_check = {7, 392, 40722};
//void testing() {
    //for (size_t i = 0; i < tested_set.size(); ++i)
        //assert(gcd(tested_set[i]) == gcd_check[i] && lcm(tested_set[i]) == lcm_check[i]);
    //cout << "Тесты пройдены!" << endl;
//}
//Ямщикова + Фесенко
int maimnn() {
    SetConsoleOutputCP(CP_UTF8);
//testing_num_days();

    cout << "Введите номер месяца (1-12) и года (1919-2069):" << endl;
    string month, year;
    cin >> month >> year;
    check_and_run(month, year);
}