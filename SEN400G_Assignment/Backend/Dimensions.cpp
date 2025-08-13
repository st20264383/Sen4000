#include "Dimensions.h"

// Default constructor
Dimensions::Dimensions() : width(0), height(0) {}

// Overloaded constructor
Dimensions::Dimensions(unsigned short w, unsigned short h) : width(w), height(h) 
{

}

// Copy constructor
Dimensions::Dimensions(const Dimensions &other) : width(other.width), height(other.height) 
{

}

// Equals operator
Dimensions& Dimensions::operator=(const Dimensions &other)
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
    }
    return *this;
}

// Getter for width
unsigned short Dimensions::getWidth() const 
{
    return width;
}

// Setter for width
void Dimensions::setWidth(unsigned short w) 
{
    width = w;
}

// Getter for height
unsigned short Dimensions::getHeight() const 
{
    return height;
}

// Setter for height
void Dimensions::setHeight(unsigned short h) 
{
    height = h;
}