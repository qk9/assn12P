// rawstr is the c-string in which the characters of a MyString are stored internally.
// the size of rawstr's array will always be exactly large enough to store the string,
//     plus the ending null character.

#pragma warning(disable:4996)
#include "mystring.h"
#include <iostream>
#include <cassert>
#include <cstring>

namespace cs_mystring {

	MyString::MyString() {
		rawstr = new char[1];
		strcpy(rawstr, "");
	}






	MyString::MyString(const char* inString) {
		rawstr = new char[strlen(inString) + 1];
		strcpy(rawstr, inString);
	}






	MyString::MyString(const MyString& inString) {
		rawstr = new char[inString.length() + 1];
		strcpy(rawstr, inString.rawstr);
	}






	MyString::~MyString() {
		delete[] rawstr;
	}






	int MyString::length() const {
		return strlen(rawstr);
	}






	void MyString::read(std::istream& in, const char delimiter) {
		//TODO: implement read
	}






	std::istream& operator>>(std::istream& in, MyString str) {
		//TODO: implement >>
		return in;
	}






	std::ostream& operator<<(std::ostream& out, const MyString& str) {
		for (int i = 0; i < str.length(); i++) {
			out << str[i];
		}
		return out;
	}






	MyString MyString::operator=(const MyString& right) {
		if (this != &right) {
			delete[] rawstr;
			rawstr = new char[strlen(right.rawstr) + 1];
			strcpy(rawstr, right.rawstr);
		}

		return *this;
	}






	MyString MyString::operator+=(const MyString& right) {
		*this = *this + right;
		return *this;
	}






	MyString operator+(const MyString& left, const MyString& right) {
		char* newstr = new char[left.length() + right.length() + 1];
		strcpy(newstr, left.rawstr);
		strcat(newstr, right.rawstr);
		MyString returnstr(newstr);
		delete[] newstr;
		return returnstr;
	}






	bool operator==(const MyString& left, const MyString& right) {
		return (strcmp(left.rawstr, right.rawstr) == 0);
	}






	bool operator!=(const MyString& left, const MyString& right) {
		return !(left == right);
	}






	bool operator<(const MyString& left, const MyString& right) {
		return strcmp(left.rawstr, right.rawstr) < 0;
	}






	bool operator>(const MyString& left, const MyString& right) {
		return strcmp(left.rawstr, right.rawstr) > 0;
	}






	bool operator<=(const MyString& left, const MyString& right) {
		return !(left > right);
	}






	bool operator>=(const MyString& left, const MyString& right) {
		return !(left < right);
	}




	char MyString::operator[](int index) const {
		assert(index >= 0 && index < this->length());
		return rawstr[index];
	}






	char& MyString::operator[](int index) {
		assert(index >= 0 && index < this->length());
		return rawstr[index];
	}
}