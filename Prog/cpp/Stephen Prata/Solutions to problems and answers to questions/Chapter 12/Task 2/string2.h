// string1.h -- fixed and augmented string class definition

#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
#include <cctype>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;             
    int len;                
    static int num_strings; 
    static const int CINLIM = 80;
public:
    String();               
    String(const char* s); 
    String(const String &); 
    ~String();             

    int length () const { return len; }
    String& StringLow();
    String& StringUp();
    int Has(char symb);
    String& operator=(const String& other);
    String& operator=(const char* other);

    friend String operator+(const char* otherStr, const String& other);
    friend String operator+(const String& otherOne, const String& otherTwo);

    char & operator[](int i);
    const char & operator[](int i) const;
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);

    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);

    static int HowMany();
};
#endif
