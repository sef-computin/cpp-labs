#pragma once
#include <vector>
#include <string>

typedef std::vector<int> lnum;

const int base = 1000 * 1000 * 1000;

class BigNumber 
{
public:
	lnum number;
	lnum fraction;
	
	void read(std::string c, std::string d) 
	{
		for (int i = (int)c.length(); i > 0; i -= 9)
			if (i < 9)
				number.push_back(atoi(c.substr(0, i).c_str()));
			else
				number.push_back(atoi(c.substr(i - 9, 9).c_str()));
		while (number.size() > 1 && number.back() == 0)
			number.pop_back();


		for (int i = (int)d.length(); i > 0; i -= 9)
			if (i < 9)
				fraction.push_back(atoi(d.substr(0, i).c_str()));
			else
				fraction.push_back(atoi(d.substr(i - 9, 9).c_str()));
	}
	void showcase() 
	{
		printf("%d", number.empty() ? 0 : number.back());
		for (int i = (int)number.size() - 2; i >= 0; --i)
			printf("%09d", number[i]);
		
		printf(".");
		printf("%d", fraction.empty() ? 0 : fraction.back());
		for (int i = (int)fraction.size() - 2; i >= 0; --i)
			printf("%09d", fraction[i]);

	}
	std::string ToString()
	{
		std::string s;
		s.push_back(number.empty() ? 0 : number.back());
		for (int i = (int)number.size() - 2; i >= 0; --i)
			s.push_back(number[i]);

		s.push_back('.');
		s.push_back(fraction.empty() ? 0 : fraction.back());
		for (int i = (int)fraction.size() - 2; i >= 0; --i)
			s.push_back(fraction[i]);
		return s;
	}
};


BigNumber BigMultiply(BigNumber a, BigNumber b) 
{
	BigNumber res;

	//целая часть
	lnum c (a.number.size() + b.number.size());
	for (size_t i = 0; i < a.number.size(); ++i)
		for (int j = 0, carry = 0; j < (int)b.number.size() || carry; ++j) {
			long long cur = c[i + j] + a.number[i] * 1ll * (j < (int)b.number.size() ? b.number[j] : 0) + carry;
			c[i + j] = int(cur % base);
			carry = int(cur / base);
		}
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();

	//дробная часть
	lnum f(a.fraction.size() + b.fraction.size());
	for (size_t i = 0; i < a.fraction.size(); ++i)
		for (int j = 0, carry = 0; j < (int)b.fraction.size() || carry; ++j) {
			long long cur = f[i + j] + a.fraction[i] * 1ll * (j < (int)b.fraction.size() ? b.fraction[j] : 0) + carry;
			f[i + j] = int(cur % base);
			carry = int(cur / base);
		}


	res.number = c;
	res.fraction = f;
	return res;
}
BigNumber BigDegree(BigNumber a, int b) 
{
	BigNumber res = a;
	
	for (int i = 0; i < b; i++) 
	{
		res = BigMultiply(res, a);
	}
	return res;
}
