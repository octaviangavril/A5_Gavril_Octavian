#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <functional>
#include <stdarg.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "MyException.h"
#include "OpenFileException.h"
#include "ReadFileException.h"
#include "WriterFileException.h"
#include <new>

using namespace std;

class CommandManager {
private:
	map<string, function<void(vector<string>)>> commands;

public:
	void add(string name, function<void(vector<string>)> fn);

	// run shall read a line from stdin in a loop, split it by whitespaces.
	// the first word will be the command name. if no word has been found, it will do nothing
	// then it will search the map for the name, and it will invoke the callback if it founds it
	// or it will show a message if it can't find it
	// the args for the callback will not contain the command name
	// if the `stop` command is found, the function will return
	// try doing this yourself; if you spent too much time on this, look at https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
	void run()
	{
		string s;
		vector<string> v;
		while (true)
		{
			getline(cin, s);
			if (s == "stop")
				return;

			v.clear();
			auto p = strtok(&s[0], " ");
			while (p)
			{
				v.push_back(p);
				p = strtok(NULL, " ");
			}
			if (v.empty())
			{
				continue;
			}
			auto it = commands.find(v[0]);
			if (it == commands.end())
			{
				printf("Comanda noua!");
				continue;
			}
			v.erase(v.begin());

			try {
				it->second(v);
			}
			catch(std::exception ex)
			{
				std::cerr << ex.what()<<'\n';
			}
		}
	};
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
	commands[name] = fn;
}

int main() {
	CommandManager manager;
	// number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
	// this is only relevant for the append and copy commands


	// prints pong!
	auto ping = [](vector<string> args) { printf("pong!\n"); };
	manager.add("ping", ping);

	// prints the number of arguments it received
	// `count a b c` -> will print `counted 3 args`
	auto count = [](vector<string> args) { printf("%d",args.size()); };;
	manager.add("count", count);

	// the first argument will be treated as a file name
	// the rest of the arguments will be appended to that file with a space as delimiter
	// remember to count the errors, if any

	auto append = [](vector<string> args)
	{
		FILE* f = fopen(args[0].c_str(), "a");

		if (args.size() < 2)
			throw args.size();	

		for (int i = 2; i < args.size(); i++)
			fwrite(&args, sizeof(args[i]), sizeof(args), f);
		fclose(f);
	};
	manager.add("append", append);



	// will print the number of times the command was called
	// do not capture any reference for this lambda
	auto times = [count = 0](vector<string> args) mutable{ count++; printf("%d", count); };
	manager.add("times", times);

	// copy a file; args[0] will provide the source, and args[1] the destination
	// make sure it works with binary files (test it with an image)
	// remember to count the errors, if any
	auto copy = [](vector<string> args)
	{		
		FILE* f1 = fopen(args[0].c_str(), "r");

		if (f1 == nullptr)
			throw ReadFileException(args[0]);
		
		FILE* f2 = fopen(args[1].c_str(), "w");
		auto ch = fgetc(f1);
		while (ch != EOF)
		{
			fputc(ch, f2);
			ch = fgetc(f1);
		}
		fclose(f1);
		fclose(f2);
	};
	manager.add("copy", copy);

	// will sort the arguments by size
	// `sort_size abc a 1234` -> will print `a abc 1234`
	// use std::sort with a lambda comparator to sort
	// and std::for_each with a lambda to print afterwards
	auto sort_size = [](vector<string> args)
	{
		auto print = [](vector<string> v) {
			for (auto& i : v)
				printf("%s ",i.c_str());
		};
		std::sort(args.begin(), args.end(), [](std::string& a, std::string& b) { return a.size()<b.size(); });
		print(args);
	};
	manager.add("sort_size", sort_size);
	
	// change the name of a file 
	// first argument is the current file name
	// the second argument is the new name of the file
	auto change_name = [](vector<string>args)
	{
		FILE* f1 = fopen(args[0].c_str(), "r");

		if (f1 == nullptr)
			throw ReadFileException(args[0]);
		
		FILE* f2 = fopen(args[1].c_str(), "w");
			
		if (f2 != nullptr)
			throw WriterFileException(args[1]);
		
		auto ch = fgetc(f1);
		while (ch != EOF)
		{
			fputc(ch, f2);
			ch = fgetc(f1);
		}
		remove(args[0].c_str());
		fclose(f2);
	};
	manager.add("change_name", change_name);

	auto huge_alloc = [](vector<string> args)
	{
		const char* s = args[0].c_str();
			int nr = 0, p = 1;
			int k = (int)strlen(s) - 1;
			for (int i = k; i >= 0; i--)
			{
				int cifra = s[i] - '0';
				nr = nr + p * cifra;
				p = p * 10;
			}		
		try
		{
			int* myarray = new int[nr];
		}
		catch (std::bad_alloc& ex)
		{
			std::cerr <<"bad alloc caught:"<< ex.what() << endl;
		}
	};
	manager.add("huge_alloc", huge_alloc);

	manager.run();

}