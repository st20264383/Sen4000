#ifndef DIMENSIONS_H
#define DIMENSIONS_H

/* You don't need this - just left it in here to test the projects are linked correctly!*/

class Dimensions
{
private:
	unsigned short width;
	unsigned short height;

public:
	// Default constructor
	Dimensions();

	// Overloaded constructor
	Dimensions(unsigned short w, unsigned short h);

	// Copy constructor
	Dimensions(const Dimensions &other);

	// Equals operator
	Dimensions& operator=(const Dimensions &other);

	// Getter for width
	unsigned short getWidth() const;

	// Setter for width
	void setWidth(unsigned short w);

	// Getter for height
	unsigned short getHeight() const;

	// Setter for height
	void setHeight(unsigned short h);
};

#endif // DIMENSIONS_H