#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <tuple>
#include <string>

typedef  std::vector<std::tuple<std::string, int>> token_data;

class Tokenizer
{
private:

public:
	//TODO: make the tokenizer simpler, but also have options you can set to make
	// it behave a certain way.
	std::vector<std::string> tokenize_string(std::string input_str);
	token_data summarize_string(std::string input_str);
	void crush_string(std::string input_str);
};

#endif
