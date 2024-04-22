/*
* Name: Iain Rogers
* Class: CS 10B
* Instructor: Dave Harden
* Date: 4/22/2024
* Filename: mystring.h
* Description: A class for the storage, boolean comparison, and outputting of strings.
* 
* Member functions:
* 
* MyString();
* pre: none.
* post: creates a MyString object that stores the empty string "".
* 
* 
* MyString(const char* inString);
* pre: none.
* post: creates a MyString object that stores the string in inString.
* 
* 
* MyString(const MyString& inString);
* pre: none.
* post: creates a deep copy of inString.
* 
* 
* int length() const;
* pre: none.
* post: returns the number of characters in the calling object. For example, the length of 
*           "hello" is 5.
* 
* 
* void read(std::istream& in, const char delimiter);
* pre: in is an istream whose contents will be read into the calling MyString. delimiter
*          is a character that will stop the reading process when it is encountered.
* post: the contents of in's buffer are read into the calling MyString, stopping either when it
*           encounters the delimiting character or when it has read MAX_INPUT_SIZE characters. If a
*           delimiting character is encountered, it is not read into the calling MyString, but it
*           is consumed from in's buffer.
* 
* 
* friend std::ostream& operator<<(std::ostream& out, const MyString& str);
* pre: out is an ostream whose buffer the contents of str will be added to.
* post: all characters in str are added to out's buffer in order from first to last. returns out.
* 
* 
* friend std::istream& operator>>(std::istream& in, MyString str);
* pre: in is an istream whose contents will be read into str.
* post: the contents of in's buffer, up to a limit of MAX_INPUT_SIZE characters, are read into str.
*           leading whitespace is skipped.
* 
* 
* MyString operator=(const MyString& right);
* pre: right is a string whose contents you'd like to copy to the calling object.
* post: a deep copy of right is made to the calling object. returns the updated calling object.
* 
* 
* MyString operator+=(const MyString& right);
* pre: right is a string whose contents you'd like to add to those of the calling object.
* post: the contents of right are appended to the contents of the calling object. returns the
*           updated calling object.
* 
* 
* friend MyString operator+(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to combine.
* post: returns a MyString which contains the contents of right appended to the contents of left.
* 
* 
* friend bool operator==(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to compare.
* post: returns true if left and right are identical; false otherwise. case and whitespace 
*           sensitive.
* 
* 
* friend bool operator!=(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to compare.
* post: returns true if left and right are not identical; true otherwise. case and whitespace 
*           sensitive.
* 
* 
* friend bool operator<(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to compare.
* post: returns true if left comes before right ASCII-alphabetically; false otherwise.
* 
* 
* friend bool operator>(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to compare.
* post: returns true if left comes after right ASCII-alphabetically; false otherwise.
* 
* 
* friend bool operator<=(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to compare.
* post: returns true if left doesn't come after right ASCII-alphabetically; false otherwise.
* 
* 
* friend bool operator>=(const MyString& left, const MyString& right);
* pre: left and right are two strings whose contents you'd like to compare.
* post: returns true if left doesn't come before right ASCII-alphabetically; false otherwise.
* 
* 
* char operator[](int index)const;
* pre: index is a positive integer that is less than this->length().
* post: returns a char literal representing the "index-th" character in the string. 
*           For example, assuming MyString str = "Hello", str[1] returns "e".
* 
* 
* char& operator[](int index);
* pre: index is a positive integer that is less than this->length().
* post: returns a pointer to the "index-th" character in the string. 
*           For example, assuming MyString str = "Hello", str[1] returns a pointer to the e in
*           hello.
*/

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

namespace cs_mystring {

	class MyString {
	public:
		MyString();
		MyString(const char* inString);
		MyString(const MyString& inString);

		~MyString();

		int length() const;

		void read(std::istream& in, const char delimiter);

		friend std::ostream& operator<<(std::ostream& out, const MyString& str);
		friend std::istream& operator>>(std::istream& in, MyString str);

		MyString operator=(const MyString& right);
		MyString operator+=(const MyString& right);
		friend MyString operator+(const MyString& left, const MyString& right);

		friend bool operator==(const MyString& left, const MyString& right);
		friend bool operator!=(const MyString& left, const MyString& right);
		friend bool operator<(const MyString& left, const MyString& right);
		friend bool operator>(const MyString& left, const MyString& right);
		friend bool operator<=(const MyString& left, const MyString& right);
		friend bool operator>=(const MyString& left, const MyString& right);

		char operator[](int index) const;
		char& operator[](int index);

		static const int MAX_INPUT_SIZE = 127;

	private:
		char* rawstr;
	};
}
#endif
