//#ifndef DSSTRING
#define DSSTRING

#include <iostream>
#include <cstring>

class DSString{
private:
    char* data;

public:
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    DSString& operator+= (const DSString&);
    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator< (const char*);
    bool operator< (const DSString&);
    char& operator[] (const int);

    int size();

    //substring:parameter a represents the starting position
    //parameter b represents the num of char to copy into substring
    //that is returned. If b is +, count forward from pos a. If -,
    //count backward from position a.

    DSString substring(int a, int b);

    //c_str returns c-str repr of DSString obj
    char* c_str();

    friend std::ostream&operator<<(
            std::ostream&, const String&);


};


