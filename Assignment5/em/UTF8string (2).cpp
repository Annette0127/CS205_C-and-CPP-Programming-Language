//
// Created by lenovo on 2017/12/2.
//

#include "UTF8string.hpp"
#include "utf8.h"
#include <cstring>

//used for !UTF8string,just a recurrence-function
void recu(unsigned char *p,unsigned char *result){
    int len=isutf8(p);
    if(*p=='\0')
        return;
    if(len){
        recu(p+len,result);
        strncat((char *)result,(char *)p,(size_t)len);
    }
}
// The four following methods need to be coded
// in UTF8string.cpp
size_t  UTF8string::length(){
    return (size_t)utf8_charlen((unsigned char*)this->m_s.c_str());
}  // Number of UTF-8 characters in the string

size_t  UTF8string::bytes(){
    return this->m_s.length();
}   // Number of bytes in the string

// IMPORTANT: for find(), 1st character = 1 (not zero)
// Return 0 if not found
int     UTF8string::find(std::string substr){
    unsigned char *p;
    if((p=utf8_search((const unsigned char*)this->m_s.c_str(),(const unsigned char*)substr.c_str()))){
        return (int)(1+this->length()-utf8_charlen(p));
    } else
        return 0;
}
void    UTF8string::replace(UTF8string remove, UTF8string replacement){
    std::string tmp=this->m_s;
    unsigned char *p;
    unsigned long delete_index;
    unsigned long delete_len=remove.bytes();
    while((p=utf8_search((const unsigned char*)tmp.c_str(),(const unsigned char*)remove.m_s.c_str()))){
        delete_index=tmp.length()-strlen((const char*)p);
        tmp.replace(delete_index,delete_len,replacement.m_s);
    }
    this->m_s=tmp;
}

UTF8string& UTF8string::operator+=(const UTF8string &addElement){
    this->m_s+=addElement.m_s;
    return *this;
}

UTF8string UTF8string::operator!()const {
    auto *p =(unsigned char *) this->m_s.c_str();
    unsigned char array[this->m_s.size()+1]="\0";
    unsigned char *a_p=array;
    recu(p,a_p);
    UTF8string result((char *)a_p);
    return result;
}
//function
UTF8string operator+(const UTF8string &LEFT,const UTF8string &RIGHT){
    UTF8string result(LEFT.m_s+RIGHT.m_s);
    return result;
}

std::ostream& operator<<(std::ostream& os,const UTF8string &str){
    return os<<str.m_s;
}

UTF8string operator*(const UTF8string &str,int times){
    UTF8string result("");
    for (int i = 0; i < times; ++i)
        result+=str;
    return result;
}
UTF8string operator*(int times,const UTF8string &str){
    return str*times;
}
