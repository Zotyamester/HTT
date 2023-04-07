#ifndef VECTOR_H
#define VECTOR_H

namespace utils
{

	template <typename T>
	class Vector
	{
	private:
		static const size_t DEFAULT_EXTRA = 5;

		size_t capacity, size;
		T* data;
	public:
		Vector(size_t size = 0);
		Vector(Vector const& rhs);
		Vector& operator=(Vector const& rhs);
		~Vector();

		void push(T item);
		void pop();

		T& operator[](size_t idx);
		T const& operator[](size_t idx) const;
	};

}

#endif // !VECTOR_H
