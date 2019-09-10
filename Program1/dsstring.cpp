#ifndef DSSTRING
#define DSSTRING

#include <iostream>
#include <cstring>
#include <dsstring.h>

using namespace std;

    DSString::DSString(){
      data=nullptr;
      ssize=0;
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

    // DSString& operator= (const char*);
    DSString& DSString::operator=(const char *r){
        *data = *r;
        return *this;
    }

    // DSString& operator= (const DSString&);
    DSString& DSString::operator= (const DSString &q){
        if(this!=&q){
            if(data){
                delete[] data;
            }
            data = new char[strlen(q.data)+1];
            strcpy(data,q.data);
        }
        return *this;
    }

    //DSString operator+ (const DSString&);
    DSString DSString::operator+(const DSString &q)
    {
     DSString s;
     s.data = new char[strlen(data)+strlen(q.data)+1];
     strcpy(s.data,data);
     strcat(s.data,q.data);
     return s;
    }

    //DSString& operator+= (const DSString&)
    DSString& DSString::operator+= (const DSString& p){
        char* temp = this -> data;
        this->data = new char[strlen(temp) + strlen(p.data) + 1];
        strcpy(this->data, temp);
        strcat(this->data, p.data);
        delete[] temp;
        return *this;
    }

    bool DSString::operator== (const char* s){
        if(strcmp(this->data, s) == 0){
            return true;
        }
    }

    bool DSString::operator== (const DSString &object){
        if(strcmp(this->data, object.data) == 0){
            return true;
        }
        else{
            return false;
        }
    }

    //bool operator< (const char*);
    bool DSString::operator< (const char *p){
        if(data < p){
            return true;
        }
    }
    //bool operator< (const DSString&);
    bool DSString::operator< (const DSString& r){
        if(data < r.data){
            return true;
        }
    }

    //char& operator[] (const int);
    char& DSString::operator[] (const int j){
        return *(data+j);
//        if(j >= strlen(data)){
//            throw 1;
//            return data[j];
//        }
    }

    //int size();
    int DSString::size(){
        return ssize;
    }


/* DSString substring(int a, int b)
 * parameter a: starting position
 * parameter b: num of char to copy into substring that is returned
 * b+ : count forward from a, b- : count backaward
 */
    DSString substring(int a, int b){
        for(int i = 0; i < a; i++){
            if (b < 0){
                DSString sub =
            }
            else{

            }
        }

    }


    char* c_str(){

    }

    std:: ostream& operator<< (std::ostream& OS, const String& s){
        OS << s.data;
        return OS;
    }

#endif
