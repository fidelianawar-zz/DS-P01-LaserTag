#ifndef DSSTRING
#define DSSTRING

#include <iostream>
#include <cstring>
#include <dsstring.h>

    DSString::DSString(){
      data=nullptr;
    }

    DSString::DSString(const char* x){
      data = new char[strlen(x)+1];
      strcpy(data, x);
    }

    DSString::DSString(const DSString& r){
        if(this==&r)
            return;
        data = new char[strlen(r.data)+1];
        strcpy(data, r.data);
    }
    DSString::~DSString(){
        if(data)
            delete[] data;
    }
    DSString& operator= (const DSString* s){

    }
    DSString& DSString::operator+= (const DSString& p){
        char* temp = this -> data;
        this->data = new char[strlen(temp) + strlen(p.data) + 1];
        strcpy(this->data, temp);
        strcat(this->data, p.data);
        delete[] temp;
        return *this;
    }

    DSString DSString::operator =(const DSString &q){
        if(this!=&q){
            if(data){
                delete[] data;
            }
            data = new char[strlen(q.data)+1];
            strcpy(data,q.data);
        }
        return *this;
    }

//    DSString& operator= (const char*);
//    DSString& operator= (const DSString&);
//    DSString operator+ (const DSString&);
//    DSString& operator+= (const DSString&);
//    bool operator== (const char*);
//    bool operator== (const DSString&);
//    bool operator< (const char*);
//    bool operator< (const DSString&);
//    char& operator[] (const int);

//    int size();

//    DSString substring(int a, int b);

//    char* c_str();

//    friend std:: ostream& operator<< (
//            std::ostream&, const String&);

//};

#endif
