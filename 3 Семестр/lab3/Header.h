#pragma once

#include <vector>

using namespace std;
class String 
{
private:
	vector<char> base;
	int length;
public:

	void PrintString() 
	{
		for (int i = 0; i < this->length; i++) cout << this->base[i];
		cout << '\n';
	}
	char& GetString() 
	{
		char* str = new char[this->length];
		for (int i = 0; i < this->length; i++) 
		{
			str[i] = this->base[i];
		}
		return *str;
	}
	int Len() 
	{
		return this->length;
	}
	String() 
	{
		this->base = {};
		this->length = 0;
	}
	String(vector<char> a) 
	{
		this->base = a;
		this->length = a.size();
	}
	String(char str[])
	{
		this->length = strlen(str);
		this->base = {};
		for (int i = 0; i < strlen(str); i++) 
		{
			this->base.push_back(str[i]);
			
		}
	}
	String(char* str, size_t bufsize)
	{
		this->length = strlen(str);
		this->base = {};
		for (int i = 0; i < bufsize; i++)
		{
			this->base.push_back(str[i]);

		}
	}


	void Clean() 
	{
		this->base = {};
		this->length = 0;
	}

	String& operator= (const String& copycat) 
	{
		this->base = copycat.base;
		this->length = copycat.length;

		return *this;
	}

	String operator+ (String str2) 
	{
		String newstr = String(str2.base);
		newstr.length += str2.length;
		for (int i = 0; i < str2.length; i++) 
		{
			newstr.base.push_back(str2.base[i]);
		}
		return newstr;
	}


	void operator+= (String str2)
	{
		this->length += str2.length;
		for (int i = 0; i < str2.length; i++)
		{
			this->base.push_back(str2.base[i]);
		}
	}

	bool operator==(String str2) {
		if (this->length == str2.length) 
		{
			for (int i = 0; i < this->length; i++) 
			{
				if (this->base[i] != str2.base[i]) return false;
			}
			return true;
		}
		else return false;
	}

	bool operator!=(String str2) {
		if (this->length == str2.length)
		{
			for (int i = 0; i < this->length; i++)
			{
				if (this->base[i] == str2.base[i]) return true;
			}
			return false;
		}
		else return true;
	}


	int HowManySymbols(char character) 
	{
		int count = 0;
		for (int i = 0; i < this->length; i++) 
		{
			if (this->base[i] == character)count++;
		}
		return count;
	}


	void Insert(int pos, String str2) 
	{
		this->length += str2.length;
		vector<char>::iterator position = this->base.begin();
		this->base.insert(this->base.begin()+pos, str2.base.begin(), str2.base.end());
	}

	bool IsIn(String area) 
	{
		if (this->length > area.length) return false;
		bool flag;
		for (int i = 0; i < area.length; i++) 
		{
			if (this->base[0] == area.base[i]) 
			{
				flag = true;
				for (int j = 0; j < this->length; j++) 
				{
					if (i + j >= area.length) {
						flag = false; break;
					}
					if (this->base[j] != area.base[i + j]) { 
						flag = false; break;
					}
				}
				if (flag == true) { break; }
			}
		}
		return flag;
	}
};
