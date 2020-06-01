#ifndef ASSIGNMENT_5_UTF8STRING_HPP
#define ASSIGNMENT_5_UTF8STRING_HPP

#include <string>


class UTF8string {
private:
    std::string str;

public:
    UTF8string(std::string s);

    UTF8string(char s[]);

    UTF8string();

    size_t length() const;

    size_t bytes() const;

    long find(std::string substr) const;

    void replace(UTF8string to_remove, UTF8string replacement);

    std::string getStr() const;//The get method;

    friend std::ostream &operator<<(std::ostream &os, const UTF8string &s);

    friend UTF8string operator+(const UTF8string &s1, const UTF8string &s2);

    friend void operator+=(UTF8string &s1, const UTF8string &s2);

    friend UTF8string operator*(const UTF8string &s, int time);

    friend UTF8string operator*(int time, const UTF8string &s);

    UTF8string operator!() const;

};


#endif //ASSIGNMENT_5_UTF8STRING_HPP
