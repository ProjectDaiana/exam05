#pragma	once
#include <iostream>

class vect2 {
	public:
		int x;
		int y;

		//canonical
		vect2() : x(0), y(0) {}
		vect2(int xParam, int yParam) : x(xParam), y(yParam) {}
		vect2(const vect2 &other) : x(other.x), y(other.y) {}
		vect2& operator=(const vect2& other) {
			if(*this != other) {
				x = other.x;
				y = other.y;
			}
			return *this;
		}
		~vect2() {}

		// operations, parameter scalar
		vect2 operator+(const int scalar){
			return vect2(x + scalar, y + scalar);
		}

		vect2 operator*(const int scalar){
			return vect2(x * scalar, y * scalar);
		}

		vect2 operator-(const int scalar){
			return vect2(x - scalar, y - scalar);
		}


		// operations, param vector
		vect2& operator+(const vect2& other) {
			this->x = x + other.x;
			this->y = y + other.y;
			return *this;
		}

		vect2& operator-(const vect2& other) {
			x = this->x - other.x;
			y = this->y - other.y;
			return *this;
		}

		vect2& operator*(const vect2& other) {
			x = this->x * other.x;
			y = this->y * other.y;
			return *this;
		}


		//increment operators ++v, v--, ++v, --v

		vect& operator++() {
			x += x;
			y +=y;
			return *this;
		} 
		
		vect& operator++(int) {
			vect2 tmp(*this);
			x++;
			y++;
			return tmp;
		}


		// operator []
		int operator[](int it) {
			return (it == 0 ? x : y);
		};

		// operator <<
		std::ostream& operator<<(std::ostream& os, const vect2& vect) {
			os << "{" << vect.x << ", " << vect.y << "}" << std::endl;
			return os;
		}

};
