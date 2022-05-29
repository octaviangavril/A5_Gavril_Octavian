#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <iostream>
#include <map>
int main()
{
	std::string s = "I bought an apple. Then I eat an apple. Apple is my favorite.";
	std::map<std::string, int> m;
	FILE* f = fopen("text.txt", "r");
	if (f)
	{

		auto ch = fgetc(f);
		while (ch != EOF)
		{
			s += ch;
			ch = fgetc(f);
		}
		std::cout << s<<std::endl;
		fclose(f);
	}
	else std::cout << "can t opel file!";

	std::string p;
	std::string::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		*it = tolower(*it);
		if (*it == ' ' || *it == '.' || *it == ',' || *it == '!' || *it == '?')
		{
			it++;
			while (*it == ' ' || *it == '.' || *it == ',' || *it == '!' || *it == '?') it++;
			it--;
			std::cout << p << std::endl;
			m[p]++;
			p.erase();
		}
		else p += *it;
	}
	std::map<std::string, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++)
	{
		std::cout << i->first << ": " << i->second << std::endl;
	}
	return 0;

}