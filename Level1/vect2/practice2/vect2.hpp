#pragma once
#include <iostream>

class vect2 {
	public:
		int a;
		int b;

		//cannonical
		vect2() : a(0), b(0) {};
		vect2(int pa, int pb) : a(pa), b(pb) {};
		vect2(const vect2& other) {
			this->a = other.a;
			this->b = other.b;
		}
		vect2& operator=(const vect2& other) {
			if (this != &other){
				this->a = other.a;
				this->b = other.b;
			}
			return *this;
		}
		~vect2() {};

		// operator ostream <<
		friend std::ostream& operator<<(std::ostream& os, const vect2 v) {
			os << "{" << v.a << ", " << v.b << "}";
			return os;
		}

		// operator []
		int& operator[](int i) {
			return(i == a ? a : b);
		}
		int operator[](int i) const{
			return(i == a ? a : b);
		}

		// increase/decrease pre and post
		vect2 operator++(int) {
			vect2 tmp(*this);
			a++;
			b++;
			return tmp;
		}
		vect2& operator++() {
			a = a + 1;
			b = b + 1;
			return *this;
		}
		vect2 operator--(int) {
			vect2 tmp(*this);
			a = a - 1;
			b = b - 1;
			return tmp;
		}
		vect2& operator--() {
			a = a - 1;
			b = b - 1;
			return *this;
		}

		// assignment + - *
		vect2& operator+=(const vect2& oth) {
			a = a + oth.a;
			b = b + oth.b; 
			return *this;
		}

		vect2& operator-=(const vect2& oth) {
			a = a - oth.a;
			b = b - oth.b; 
			return *this;
		}

		vect2& operator*=(const int s) {
			a = a * s;
			b = b * s; 
			return *this;
		}
		
		// operators  + - * vect
		vect2 operator+(const vect2& other) const{
			return vect2(a + other.a, b + other.b);
		}

		vect2 operator-(const vect2& other) {
			return vect2(a - other.a, b - other.b);
		}

		vect2 operator*(const vect2& other) {
			return vect2(a * other.a, b * other.b);
		}

		vect2 operator+(int s) const{
			return vect2(a + s, b + s);
		}

		vect2 operator-(int s) const{
			return vect2(a - s, b - s);
		}

		vect2 operator*(int s) const{
			return vect2(a * s, b * s);
		}

		// reverse *
		friend vect2 operator*(int s, vect2& v) {
			return vect2(s * v.a, s * v.b);
		}

		// negation
		vect2 operator-() const {
			return vect2(-a,-b);
		}

		//booleans
		bool operator==(const vect2& other) {
			return(a == other.a && b == other.b);
		}

		bool operator!=(const vect2& other) {
			return(a != other.a && b != other.b);
		}
};
