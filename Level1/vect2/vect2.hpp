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
			if(this != &other) {
				x = other.x;
				y = other.y;
			}
			return *this;
		}
		~vect2() {}

		// operations, parameter scalar
		vect2 operator+(const int scalar) const{
			return vect2(x + scalar, y + scalar);
		}

		vect2 operator*(const int scalar) const{
			return vect2(x * scalar, y * scalar);
		}

		vect2 operator-(const int scalar) const{
			return vect2(x - scalar, y - scalar);
		}


		// operations, param vector
		vect2 operator+(const vect2& other) const{
			return vect2(x + other.x, y + other.y );
		}

		vect2 operator-(const vect2& other) const {
			return vect2(x - other.x, y - other.y );
		}

		vect2 operator*(const vect2& other) const {	
			return vect2(x * other.x, y * other.y );
		}


		//increment operators ++v, v--, ++v, --v

		vect2& operator++() {
			x ++;
			y ++;
			return *this;
		} 
		
		vect2 operator++(int) {
			vect2 tmp(*this);
			x++;
			y++;
			return tmp;
		}
		
		vect2& operator--(){
			x --;
			y --;
			return *this;
		}

		vect2 operator--(int) {
			vect2 tmp(*this);
			x--;
			y--;
			return tmp;
		}

		// operator []
		int& operator[](int it) {
			return (it == 0 ? x : y);
		};

		int operator[](int it) const {
			return (it == 0 ? x : y);
		}

		// operator <<
		friend std::ostream& operator<<(std::ostream& os, const vect2& vect) {
			os << "{" << vect.x << ", " << vect.y << "}";
			return os;
		}

		//add/subst/mult assignment		

		vect2& operator+=(const vect2& other){
			x += other.x;
			y += other.y;
			return *this;
		}
	
		vect2& operator-=(const vect2& other){
			x -= other.x;
			y -= other.y;
			return *this;
		}
		
		vect2& operator*=(const vect2& other){
			x *= other.x;
			y *= other.y;
			return *this;
		}
		
		vect2& operator*=(const int s){
			x *= s;
			y *= s;
			return *this;
		}


		// scalar reverse
		friend vect2 operator *(int s, vect2& v) {
			return vect2(s * v.x, s * v.y);
		} 

		// negation
		vect2 operator-()const{
			return vect2 (-x, -y);
		}
	
		//booleans
		bool operator==(const vect2& oth){
			return( x == oth.x && y == oth.y);
		}

		bool operator!=(const vect2& oth){
			return( x != oth.x && y != oth.y);
		}

};
