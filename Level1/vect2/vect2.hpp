#pragma	once

class vect2 {
	public:
		int x;
		int y;

		//canonical
		vect2() : x(0), y(0) {}
		vect2(int xParam, int yParam) : x(xParam), y(yParam) {}
		vect2(const vect2 &other) : x(other.x), y(other.y) {}
		vect2& operator=(const vect2 &other){
			if(*this != &other){
				this->x = other.x;
				this->y = other.y;
			}
			return *this;
		}
		~vect2() {}

		vect2 operator+(const int scalar){
			return vect2(x + scalar, y + scalar);
		}

		vect2 operator*(const int scalar){
			return vect2(x * scalar, y * scalar);
		}

		vect2 operator-(const int scalar){
			return vect2(x - scalar, y - scalar);
		}

		vect2& operator+(const vect2&) {
			return
		}

		//operator
		vect2 operator[]{};
		vect2 operator<<{};

		std::vector

}