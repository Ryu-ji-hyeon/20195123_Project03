#include <iostream>
#include<cstring>

using namespace std;

class String
{
private:
	char* _chars;
public:
	String() {};
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	//1. ==
	bool operator==(const String& str)const
	{
		return strcmp(_chars, str._chars ) == 0;
	}
	//2. !=
    bool operator!=(const String& str)const
	{
		return strcmp(_chars, str._chars) != 0;
	}
	//3. >
	bool operator>(const String& str)const
	{
		return strcmp(_chars, str._chars) > 0;
	}
	//4. <
	bool operator<(const String& str)const
	{
		return strcmp(_chars, str._chars) < 0;
	}
	//5. >=
	bool operator>=(const String& str)const
	{
		// >=의 반대 ?-> <
		return !(*this < str);
	}
	//6. <=
	bool operator<=(const String& str)const
	{
		// <=의 반대 ?-> >
		return !(*this > str);
	}
};
int main() {

	String str0{ "abc" };
	String str1{ "ac" };

	if (str0 == str1)
		cout << "equal" << endl;

	if (str0 != str1)
		cout << "not equal" << endl;

	if (str0 > str1)
		cout << "str0 > str1" << endl;

	if (str0 < str1)
		cout << "str0 < str1" << endl;

	if (str0 <= str1)
		cout << "str0 <= str1" << endl;

	if (str0 >= str1)
		cout << "str0 >= str1" << endl;
}