#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>


#define arSize 1000
#define nameLength 35

using namespace std;

string trim(string);

bool exit(string);

void toLower(string *str);

bool is_number(const std::string &s);

struct city {
    string name;
    string country;
    double latitude;
    double longitude;
};

int main() {
    city cityAr1[arSize];
    string str;
    ifstream fin("world_cities.csv");
    if (!fin.good()) {
        cout << "Fail to open the file.";
        return 0;
    }
    int count = 0;
    while (getline(fin, str)) {
        if (count >= arSize) {
            cout << "Input fail since the array is full!\n";
            break;
        }
        istringstream sin(str);
        string name, country, latitude, longtitude;
        getline(sin, name, ',');
        getline(sin, country, ',');//This is to deal with the name of state .
        getline(sin, country, ',');
        getline(sin, latitude, ',');
        getline(sin, longtitude);
        sin.clear();
        if (name.length() > nameLength || country.length() > nameLength) {
            cout << "The length of names should not bigger than " << nameLength << ". This data is not loaded\n";
            continue;
        }
        cityAr1[count].name = trim(name);
        cityAr1[count].country = trim(country);
        cityAr1[count].latitude = stod(trim(latitude));
        cityAr1[count].longitude = stod(trim(longtitude));
        count++;
    }
    fin.close();

    //Part two;
    city city1;
    city city2;
    city cityAr2[arSize];
    copy(begin(cityAr1), end(cityAr1), begin(cityAr2));
    for (int i = 0; i < count; i++) {
        toLower(&(cityAr2[i].country));
        toLower(&(cityAr2[i].name));
    }
    bool loop = true;
    vector<city> list;

    while (loop) {
        list.clear();
        while (true) {
            cout << "Please input the first city: ";
            getline(cin, str);
            str = trim(str);
            toLower(&str);
            if (exit(str)) {
                loop = false;
                break;
            }
            if (str.length() < 3) {
                cout << "Please enter a name more than 3 letters.\n";
                continue;
            } else {
                for (int i = 0; i < count; i++) {
                    if (cityAr2[i].name.find
                    (str) != string::npos) {
                        list.push_back(cityAr1[i]);
                    }
                }
            }
            if (list.empty()) {
                cout << "Please input another name which is on the list.\n ";
                continue;
            } else {
                cout << "Please choose the right city:(please input the number!) \n";
                for (int i = 0; i < list.size(); i++) {
                    cout << i + 1 << ". " << list[i].name << ", " << list[i].country << ", latitude: "
                         << list[i].latitude
                         << ", longitude: " << list[i].longitude << "\n";
                }
                int num;
                getline(cin,str);
                str = trim(str);
                toLower(&str);
                if (exit(str)) {
                    loop = false;
                    break;
                }
                while (true) {
                    if (is_number(str)) {
                        num = stoi(str);
                        if (num <= list.size() && num >= 1)break;
                        else{
                            cout << "Please input the right number: ";
                            getline(cin,str);
                            str = trim(str);
                            toLower(&str);
                            if (exit(str)) {
                                loop = false;
                                break;
                            }
                        }
                    } else {
                        cout << "Please input the right number: ";
                        getline(cin,str);
                        str = trim(str);
                        toLower(&str);
                        if (exit(str)) {
                            loop = false;
                            break;
                        }
                    }
                }
                if(!loop)break;
                cout << "You have successfully chosen your first city.\n";
                city1.name = list[num - 1].name;
                city1.country = list[num - 1].country;
                city1.longitude = list[num - 1].longitude;
                city1.latitude = list[num - 1].latitude;
                cout << city1.name << ", " << city1.country << ", latitude: "
                     << city1.latitude << ", longitude: " << city1.longitude << "\n";
                break;
            }
        }
        if (!loop)break;
        list.clear();
        while (true) {
            cout << "Please input the second city: ";
            getline(cin, str);
            str = trim(str);
            toLower(&str);
            if (exit(str)) {
                loop = false;
                break;
            }
            if (str.length() < 3) {
                cout << "Please enter a name more than 3 letters.\n";
                continue;
            } else {
                for (int i = 0; i < count; i++) {
                    if (cityAr2[i].name.find(str) != string::npos) {
                        list.push_back(cityAr1[i]);
                    }
                }
            }
            if (list.empty()) {
                cout << "Please input another name which is on the list.\n";
                continue;
            } else {
                cout << "Please choose the right city:(please input the number!) \n";
                for (int i = 0; i < list.size(); i++) {
                    cout << i + 1 << ". " << list[i].name << ", " << list[i].country << ", latitude: "
                         << list[i].latitude
                         << ", longitude: " << list[i].longitude << "\n";
                }
                int num;
                getline(cin,str);
                str = trim(str);
                toLower(&str);
                if (exit(str)) {
                    loop = false;
                    break;
                }
                while (true) {
                    if (is_number(str)) {
                        num = stoi(str);
                        if (num <= list.size() && num >= 1)break;
                        else{
                            cout << "Please input the right number: ";
                            getline(cin,str);
                            str = trim(str);
                            toLower(&str);
                            if (exit(str)) {
                                loop = false;
                                break;
                            }
                        }
                    } else {
                        cout << "Please input the right number: ";
                        getline(cin,str);
                        str = trim(str);
                        toLower(&str);
                        if (exit(str)) {
                            loop = false;
                            break;
                        }
                    }
                }
                if(!loop)break;
                cout << "You have successfully chosen your second city.\n";

                city2.name = list[num - 1].name;
                city2.country = list[num - 1].country;
                city2.longitude = list[num - 1].longitude;
                city2.latitude = list[num - 1].latitude;
                cout << city2.name << ", " << city2.country << ", latitude: "
                     << city2.latitude << ", longitude: " << city2.longitude << "\n";
                break;
            }
        }
        if (!loop)break;
        double phi1, phi2, theta1, theta2, d, c;
        const double pi = 3.1415926535;

        phi1 = (90 - city1.latitude) / 180 * pi;
        phi2 = (90 - city2.latitude) / 180 * pi;
        theta1 = city1.longitude / 180 * pi;
        theta2 = city2.longitude / 180 * pi;
        c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
        d = acos(c) * 6371;
        cout << "The distance between " << city1.name << "(" << city1.country << ")" << " and " << city2.name << "("
             << city2.country << ")" << " is " << d << " km" << endl;
    }
    return 0;
}

string trim(string st) {
    while (isspace(st[0])) {
        st = st.substr(1, st.length() - 1);
    }
    while (isspace(st[st.length() - 1])) {
        st = st.substr(0, st.length() - 1);
    }
    return st;
}

bool exit(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (str.compare("bye") == 0)return true;
    else return false;
}

void toLower(string *str) {
    transform((*str).begin(), (*str).end(), (*str).begin(), ::tolower);
}

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}//This function is from stackoverflow :https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
