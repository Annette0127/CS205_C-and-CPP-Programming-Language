#include <iostream>
#include <math.h>

using namespace std;
string city1, city2, rub;
double longitude1, latitude1, latitude2, longitude2, phi1, theta1, phi2, theta2, c, d;
double pi = M_PI;

string trim(string);

int main() {
    cout << "The first city:";
    getline(cin, city1);
    city1 = trim(city1);
    if (city1.length() == 0) {
        cout << "Input is not correct.";
        return 0;
    }
    cout << "The latitude and longitude of first city:";
    cin >> latitude1 >> longitude1;
    if (!cin.fail()) {
        if (latitude1 < -90 || latitude1 > 90) {
            cout << "Input is not correct.";
            return 0;
        }
        if (longitude1 < -180 || longitude1 > 180) {
            cout << "Input is not correct.";
            return 0;
        }
        getline(cin, rub);
        rub = trim(rub);
        if (rub.size() != 0) {
            cout << "Input is not correct.";
            return 0;
        }
        cout << "The second city:";
        getline(cin, city2);
        city2 = trim(city2);
        if (city2.length() == 0) {
            cout << "Input is not correct.";
            return 0;
        }
        cout << "The latitude and longitude of second city:";
        cin >> latitude2 >> longitude2;
        if (!cin.fail()) {
            getline(cin, rub);
            rub = trim(rub);
            if (rub.size() != 0) {
                cout << "Input is not correct.";
                return 0;
            }
            if (latitude2 < -90 || latitude2 > 90) {
                cout << "Input is not correct.";
                return 0;
            }
            if (longitude2 < -180 || longitude2 > 180) {
                cout << "Input is not correct.";
                return 0;
            }
            phi1 = (90 - latitude1) / 180 * pi;
            phi2 = (90 - latitude2) / 180 * pi;
            theta1 = longitude1 / 180 * pi;
            theta2 = longitude2 / 180 * pi;
            c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
            d = acos(c) * 6371;
            cout << "The distance between " << city1 << " and " << city2 << " is " << d << " km" << endl;
            return 0;
        } else {
            cout << "Input is not correct.";
            return 0;
        };
    } else {
        cout << "Input is not correct.";
        return 0;
    }
}

string trim(string st) {
    while (st[0] == ' ') {
        st = st.substr(1, st.length() - 1);
    }
    while (st[st.length() - 1] == ' ') {
        st = st.substr(0, st.length() - 2);
    }
    return st;
}
