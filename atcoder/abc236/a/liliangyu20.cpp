#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int a, b;
    cin >> a >> b;
    swap(str[a - 1], str[b - 1]);

    cout << str;


    return 0;
}