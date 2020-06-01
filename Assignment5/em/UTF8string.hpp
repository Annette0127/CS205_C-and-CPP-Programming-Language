#ifndef UTF8STRING_HPP
#define UTF8STRING_HPP

#include <iostream>
#include <string>

// THIS FILE DOESN'T NEED TO BE MODIFIED
// YOU NEED TO WRITE UTF8string.cpp

class UTF8string {
      std::string  m_s;

  public:
      // Constructors - No code required
      UTF8string(){ };
      UTF8string(const char *s) {m_s = std::string(s);};
      UTF8string(const std::string s) {m_s = s;};
      // 
      // The four following functions need to be coded
      // in UTF8string.cpp
      //
      size_t  length();  // Number of UTF-8 characters in the string
      size_t  bytes();   // Number of bytes in the string
      // IMPORTANT: for find(), 1st character = 1 (not zero)
      // Return 0 if not found
      int     find(std::string substr);
      void    replace(UTF8string remove, UTF8string replacement);
      // ---------------------------------------
      // value() is for checking what was done
      // No code required
      std::string  value() {return m_s;};

      UTF8string& operator+=(const UTF8string &addElement);
      UTF8string operator!()const;

      //used for !UTF8string,just a recurrence-function
      friend void recu(unsigned char *p,unsigned char *result);

      friend UTF8string operator+(const UTF8string &LEFT,const UTF8string &RIGHT);
      friend std::ostream& operator<<(std::ostream& os,const UTF8string &str);
      friend UTF8string operator*(const UTF8string &str,int times);
      friend UTF8string operator*(int times,const UTF8string &str);
};

#endif
