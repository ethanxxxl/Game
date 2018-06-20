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
	ParseCmd();
	~ParseCmd();

	//comandline functions
	int get_cmd(WINDOW *cmd_line, std::string input, callback_list_type);

	//tokenizer functions
	
	//TODO: make the tokenizer simpler, but also have options you can set to make
	// it behave a certain way.
	std::vector<std::string> tokenize_string(std::string input_str, char delimeter = ' ');
	token_data summarize_string(std::string input_str);
	void crush_string(std::string input_str);

};

#endif
