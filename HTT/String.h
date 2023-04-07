#ifndef STRING_H
#define STRING_H

#include "Vector.h"
#include "Serializable.h"

namespace utils
{

	class String : private Vector<char>, Serializable
	{
	public:
		String(const char* cs = "");
		String(char c);
		String(String const& s);
		String& operator=(String const& s);

		const char* c_str() const;

		void write(std::ostream& os) const override;
		void read(std::istream& is) override;

		using Vector::operator[];

		String operator+(String const& s) const;
		String operator+(char c) const;

		String& operator+=(String const& s);
		String& operator+=(char c);

		bool operator==(String const& s);
		bool operator<(String const& s);
		bool operator>(String const& s);
	};

	String operator+(char c, String const& s);

	std::ostream& operator<<(std::ostream& os, String const& s);
	std::istream& operator>>(std::istream& is, String& s);

}

#endif // !STRING_H
