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

		vect2 operator+(const int scalar) {
			this->x = this->x + scalar;
			this->y = this->y + scalar;
		}

		vect2& operator-(const int scalar) {
			this->x = this->x - scalar;
			this->y = this->y - scalar;
		}

		vect2& operator*(const int scalar) {
			this->x = this->x * scalar;
			this->y-= this->y * scalar;
		}


		vect2& operator+(const other& vect) {
			return vect2((this->x + other.x), (this->y + other.y));
		}

		vect2& operator-(const other& vect) {
			return vect2((this->x - other.x), (this->y - other.y));
		}

		vect2& operator*(const other& vect) {
			return vect2((this->x * other.x), (this->y * other.y));
		}


		vect2& operator+(const other& vect) {
			this->x = this->x + other.x;
			this->y = this->y + other.y;
		}

		vect2& operator-(const other& vect) {
			this->x = this->x - other.x;
			this->y = this->y - other.y;
		}

		vect2& operator*(const other& vect) {
			this->x = this->x * other.x;
			this->y-= this->y * other.y;
		}

		//operator
		std::ostream& operator<<(std::ostream& os, const vect2& vect){
			os << vect.x << ", " << vect.y << std::endl:
			return os;
		}
	
		vect2 operator[]{};

		std::vector

};