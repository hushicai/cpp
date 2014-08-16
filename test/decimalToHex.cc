#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int i = 0;
    cout << "decimal: ";
    if (!(cin >> i)) {
        return -1;
    }

    stringstream ss;

    do {
        ss << hex << i % 16;
        i /= 16;
    } while(i != 0);

    string s = ss.str();
    reverse(s.begin(), s.end());

    cout << "hex: " << s << endl;

    return 0;
}
