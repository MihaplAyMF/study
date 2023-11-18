#include <cstring>
#include "dma.h"

// Base methods

Base::Base(const char* l)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
}

Base::Base(const Base& other)
{
    label = new char[std::strlen(other.label) + 1];
    std::strcpy(label, other.label);
}

Base::~Base()
{
    delete[] label;
}

Base& Base::operator=(const Base& other)
{
    if(this == &other)
        return *this;
    delete[] label;
    label = new char[std::strlen(other.label) + 1];
    std::strcpy(label, other.label);
    return *this;
}

void Base::View()
{
    std::cout << "Label: " << label << std::endl;
}

// BaseDMA methods

BaseDMA::BaseDMA(const char* l, int r)
    : rating(r)
{ }

BaseDMA::BaseDMA(const BaseDMA& other)
{
    rating = other.rating;
}

BaseDMA& BaseDMA::operator=(const BaseDMA& other)
{
    rating = other.rating;
    return *this;
}

void BaseDMA::View()
{
    Base::View();
    std::cout << "Rating: " << rating << std::endl;
}

// lacksDMA methods

LacksDMA::LacksDMA(const char* c, const char* l)
    : Base(l)
{
    color = new char[std::strlen(c) + 1];
    std::strcpy(color, c);
}

LacksDMA::LacksDMA(const char* c, const Base& rs)
    : Base(rs)
{
    std::strcpy(color, c);
}

LacksDMA::~LacksDMA()
{
    delete[] color;
}

void LacksDMA::View()
{
    Base::View();
    std::cout << "Color: " << color << std::endl;
}

// hasDMA methods

HasDMA::HasDMA(const char* s, const char* l)
    : Base(l)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

HasDMA::HasDMA(const char* s, const Base& rs)
    : Base(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

HasDMA::HasDMA(const HasDMA& hs)
    : Base(hs)  
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

HasDMA::~HasDMA()
{
    delete[] style;
}

HasDMA& HasDMA::operator=(const HasDMA& hs)
{
    if(this == &hs)
        return *this;
    Base::operator=(hs); 
    delete[] style;         
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

void HasDMA::View()
{
    Base::View();
    std::cout << "Style: " << style << std::endl;
}
