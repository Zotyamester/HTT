#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

class Serializable
{
public:
	virtual ~Serializable() {}
	virtual void write(std::ostream& os) = 0;
	virtual void read(std::istream& is) = 0;
};

#endif // !SERIALIZABLE_H
