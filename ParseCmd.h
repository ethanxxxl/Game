#ifndef PARSECMD_H
#define PARSECMD_H

#include <string>
#include <map>
#include <vector>
#include <ncurses.h>

class ParseCmd
{
private:
	typedef void (*callback_func)(WINDOW *);
	typedef std::map<std::string, callback_func> callback_list_type;

	typedef  std::vector<std::tuple<std::string, int>> token_data;

public:
	//comandline functions
	int getCmd(WINDOW *cmd_line, std::string input, callback_list_type);

	//tokenizer functions
	
	//TODO: make the tokenizer simpler, but also have options you can set to make
	// it behave a certain way.
	std::vector<std::string> tokenizeString(std::string input_str, char delimeter = ' ');
	token_data summarizeString(std::string input_str);
	void crushString(std::string input_str);

};

#endif
