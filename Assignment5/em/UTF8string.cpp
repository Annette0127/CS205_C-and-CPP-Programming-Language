//
// Created by lenovo on 2017/12/2.
//

#include "UTF8string.hpp"
#include "utf8.h"
#include <cstring>

    //
    // The four following functions need to be coded
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


