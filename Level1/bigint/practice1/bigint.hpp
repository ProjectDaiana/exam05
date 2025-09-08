#pragma once
#include <iostream>
#include <deque>

class bigint {
	//store in array of unsigned integers
	//increment
	//addition
	//comparisons
	//bitshits
	public:
	std::deque<int> digits;

	//cannonical
	bigint() : digits(0) {}; // default constructor
	bigint(size_t n) { //fill up the deque
		while(n) {
			digits.push_front(static_cast<int>(n % 10));
			n =/ 10;
		}
		if (digits.empty())
			digits.push_front(0);
	}	
	bigint(const bigint& other) : digits(other.digits) {}; // copy constructor
	~bigint(){}; 
	bigint operator=(const bigint& other){
		digits = other.digits;
		return *this;
	};	

	//ostream overload
	friend std::ostream <<(std::ostream& os, bigint bi) {
		os << bi.digits;
		retunr os;
	}

	//increment pre y post
	bigint& operator++() {
		// iterate the digits and add 1 to each?
	}
	
	bigint operator++(int) {
		bigint tmp(&this);
		// increase all digits?
		return tmp;
	}

	//sum
	bigint operator+(const bigint& other){
		add_or_subst();
	}
	// -
	bigint operator-(const bigint first&, const bigint &second) {
		return bigint(0);
	} 


	//sum scalar
	friend bigint operator+(int s) {};

	// =+ 
	bigint& operator=+() {
		
	}

	//shifting
	bigint operator<<() {}
	bigint operator>>() {}
	bigint operator<<=() {}
	bigint operator>>=() {}

	// bools
	// mayor y menor
	bool operator<(const bigint& other) const {
		if(digits.size() < other.digits.size())
			return true;
		else if (digits.size() > other.size(i))
			return false;
		for (size_t i= 0; i < digits.size(); i++)
			if (digits[i] < other.digits[i])
				return true;
			else if (digits[i] > other.digits[i])
				return false;
		return false;
	}
	bool operator>(const bigint& other) const {
		return *this < other;
	}
	
	bool operator<=(const bigint& other) const {
		if (*this > other)
			return false;
		else
			return true;
	}

	bool operator>=(const bigint& other) const {
		if (*this < other)
			return false;
		else
			return true;
	}

	bool operator==(const bigint& other) const { 
		return (!(*this < other) && !(*this > other)); 
	}
};
