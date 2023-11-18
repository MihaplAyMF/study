#pragma once

#include <iostream>

class Base
{
private:
    char* label;
public:
    Base(const char* l = "null");
    Base(const Base& other);
    virtual ~Base();
    Base& operator=(const Base& other);
    virtual void View();
};

class BaseDMA : public Base
{
private:
    int rating;

public:
    BaseDMA(const char* l = "null", int r = 0);
    BaseDMA(const BaseDMA& other);
    ~BaseDMA() {};
    BaseDMA& operator=(const BaseDMA& other);
    void View();
};

class LacksDMA : public Base
{
private:
    char* color;
public:
    LacksDMA(const char* c = "blank", const char* l = "null");
    LacksDMA(const char* c, const Base& other);
    ~LacksDMA();
    void View();
};

class HasDMA : public Base
{
private:
    char* style;
public:
    HasDMA(const char* s = "none", const char* l = "null");
    HasDMA(const char* s, const Base& other);
    HasDMA(const HasDMA& hs);
    ~HasDMA();
    HasDMA& operator=(const HasDMA& other);
    void View();
};

