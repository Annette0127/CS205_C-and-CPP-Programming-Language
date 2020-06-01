#include "UTF8string.hpp"
#include <cstring>
#include <string>
#include "utf8.h"

#include <iostream>

using namespace std;

string UTF8string::getStr() const {
    return str;
}

UTF8string::UTF8string(string s) {
    str = s;
}

UTF8string::UTF8string() {
    str = "";
}

UTF8string::UTF8string(char s[]) {
    str = string(s);
}

size_t UTF8string::length() const {
    char const *input = str.c_str();
    unsigned long codepoint;
    int bytes_in_char;
    size_t length = 0;

    unsigned char *p;
    p = (unsigned char *) (&input[0]);
    while (*p) {
        codepoint = utf8_to_codepoint(p, &bytes_in_char);
        if (codepoint) {
            length++;
            _utf8_incr(p);
        } else {
            p++;
        }
    }
    return length;
}

size_t UTF8string::bytes() const {
    return str.length();

}

long UTF8string::find(string substr) const {
    long find = str.find(substr);
    if (find == string::npos)
        return find;//not find

    char const *input = str.substr(0,find).c_str();
    unsigned long codepoint;
    int bytes_in_char;
    unsigned long result = 0;

    unsigned char *p;
    p = (unsigned char *) (&input[0]);
    while (*p) {
        codepoint = utf8_to_codepoint(p, &bytes_in_char);
        if (codepoint) {
            result++;
        }
        _utf8_incr(p);
    }
    return result;

}

void UTF8string::replace(UTF8string to_remove, UTF8string replacement) {
    while (str.find(to_remove.getStr()) != string::npos)
        str = str.replace(str.find(to_remove.getStr()), to_remove.bytes(), replacement.getStr());
}

ostream &operator<<(ostream &os, const UTF8string &s) {
    return os << s.str;
}

UTF8string operator+(const UTF8string &s1, const UTF8string &s2) {
    UTF8string u(s1.str + s2.str);
    return u;
}

void operator+=(UTF8string &s1, const UTF8string &s2) {
    s1.str = s1.str + s2.str;
}


UTF8string operator*(const UTF8string &s, int time) {//if time<0,it will return “”.
    UTF8string u;
    for (int i = 1; i <= time; i++) {
        u.str = u.str + s.str;
    }
    return u;
}

UTF8string operator*(int time, const UTF8string &s) {
    return s * time;
}

UTF8string UTF8string::operator!() const {
    char const *input = str.c_str();
    string result = "";
    int bytes_in_char;
    unsigned long codepoint;

    unsigned char *p;
    p = (unsigned char *) (&input[0]);
    while (*p) {
        codepoint = utf8_to_codepoint(p, &bytes_in_char);
        if (codepoint) {
            string block = "";
            for (int i = 0; i < bytes_in_char; ++i) {
                block += p[i];
            }
            result = block + result;
            p += bytes_in_char;
        } else {
            p++;
        }
    }
    UTF8string resultUTF8(string);
    return result;
}
