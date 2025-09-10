#pragma once
#include <iostream>
#include <deque>
#include <cstdlib>

class bigint {
	//store in array of unsigned integers
	//increment
	//addition
	//comparisons
	//bitshits
	public:
	std::deque<int> digits;

	//cannonical
	bigint() : digits(1) {}; // default constructor
	bigint(size_t n) { //fill up the deque
		while(n) {
			digits.push_front(static_cast<int>(n % 10));
			n /= 10;
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
	friend std::ostream& operator<<(std::ostream& os, const bigint& bi) {
		for (size_t i = 0; i < bi.digits.size(); i++)
			os << bi.digits[i];
		return os;
	}
	// -
	bigint operator-(const bigint &second) const{
		(void)second;
		return bigint(0);
	} 

	//sum
	bigint operator+(const bigint& other) const{
		int a = static_cast<int>(this->digits.size());
		int o = static_cast<int>(other.digits.size());

		const bigint& smaller((a < o) ? *this : other);
		bigint bigger = (a < o) ? other : *this; //copy

		int diff = std::abs(a - o); 
	
		int carry = 0;
		for (int i = bigger.digits.size() - 1; i >= 0 ; i--)
		{
			int j = i - diff;
			int sd = (j >= 0) ? smaller.digits[j] : 0;
			int sum = (bigger.digits[i] + sd + carry);
			
			bigger.digits[i] = (sum % 10);
		   	carry = sum / 10;
		}
		if (carry > 0)
			bigger.digits.push_front(carry);
		return bigger;
	};

	// =+ 
	bigint& operator+=(const bigint& other) {
		*this = addition(other);
		return *this;
	}

	//increment pre y post
	bigint& operator++() {
		*this = addition(1);
		return (*this);
	}
	
	bigint operator++(int) {
		bigint tmp(*this);
		*this = addition(1); 
		return tmp;
	}

	//shifting
	bigint operator<<(int lsh) const{
		bigint cpy(*this);
		if (cpy.digits.size() == 1 && cpy.digits[0] == 0)
			return cpy;
		for (int i =0 ; i < lsh; i++)		
			cpy.digits.push_back(0);
		return cpy;
	}

	bigint operator<<(const bigint& lsh) const {
		bigint cpy(*this);
		if (cpy.digits.size() == 1 && cpy.digits[0] == 0)
			return cpy;			
		for (bigint i = 0; i < lsh; i++) {
			cpy.digits.push_back(0);
		}
		return cpy;
	}

	bigint operator>>(int rsh) const {
		bigint cpy(*this);
		if(cpy.digits.empty()) {
			cpy.digits.push_front(0);
			return cpy;
		}
		for (int i = 0; i < rsh; i++)
			cpy.digits.pop_back();
		return cpy;
	}

	bigint operator>>(const bigint& rsh) const {
		bigint cpy(*this);
		if (cpy.digits.empty()) {
			cpy.digits.push_front(0);
			return cpy;
		}
		for (bigint i; i < rsh; i++)
			cpy.digits.pop_back();
		return cpy;	
	}

	bigint operator<<=(const bigint& other) {
		return (*this << other);
	}

	bigint operator>>=(const bigint& other) {
		return (*this >> other);		
	}

	// bools
	// mayor y menor
	bool operator<(const bigint& other) const {
		if(digits.size() < other.digits.size())
			return true;
		else if (digits.size() > other.digits.size())
			return false;
		for (size_t i= 0; i < digits.size(); i++)
			if (digits[i] < other.digits[i])
				return true;
			else if (digits[i] > other.digits[i])
				return false;
		return false;
	}
	bool operator>(const bigint& other) const {
		return !(*this < other);
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

	bool operator!=(const bigint& other) const { 
		return ((*this < other) || (*this > other)); 
	}


	private:
		bigint addition(const bigint &other){
		int a = static_cast<int>(this->digits.size());
		int o = static_cast<int>(other.digits.size());

		const bigint& smaller((a < o) ? *this : other);
		bigint bigger = (a < o) ? other : *this; //copy

		int diff = std::abs(a - o); 
	
		int carry = 0;
		for (int i = bigger.digits.size() - 1; i >= 0 ; i--)
		{
			int j = i - diff;
			int sd = (j >= 0) ? smaller.digits[j] : 0;
			int sum = (bigger.digits[i] + sd + carry);
			
			bigger.digits[i] = (sum % 10);
		   	carry = sum / 10;
		}
		if (carry > 0)
			bigger.digits.push_front(carry);
		return bigger;

		}
};
