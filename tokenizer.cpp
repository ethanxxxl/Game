#include <string>
#include <vector>
#include <tuple>
#include "tokenizer.h"

std::vector<std::string> tokenize_string(std::string input_str, char delimeter = ' ')
{
	// TODO: add options so that the user can decide where the words are broken up at.

	// data for the tokenizer
	std::vector<std::string> list;
	std::string word = "";

	// tokenizer
	for (int i = 0; i < input_str.length(); i++ )
	{
		if ( input_str[i] == delimeter || i == input_str.length() - 1)
		{
			// gets the last letter of the last word
			if (i == input_str.length() - 1 )
			{
				word += input_str[i];
			}

			// puts the new word into the list
			list.push_back(word);
			
			word.clear();
		}
		else
		{
			word += input_str[i];
		}
	}

	return list;
}

token_data Tokenizer::summarize_string(std::string input_str)
{
	// data for the tokenizer
	token_data list;
	std::string word = "";

	// tokenizer
	for (int i = 0; i < input_str.length(); i++ )
	{
		if ( input_str[i] == ' ' || i == input_str.length() - 1)
		{
			// gets the last letter of the last word
			if (i == input_str.length() - 1 )
			{
				word += input_str[i];
			}

			// puts the new word into the list
			list.push_back(std::make_tuple(word, 1));
			
			// checks the list for an existing entry for said word and deletes the newest entry if one is found.
			for ( int x = 0; x < list.size()-1; x++ )
			{
				// checks to see if the data of the current element of the list matches the current word.
				if ( word.compare(std::get<0>(list[x])) != 0 || x == list.size() - 1 )
				{
					continue;
				}
				else
				{
					// removes the last element on the list that is a duplicate of the one just found.
					std::get<1>(list[x]) += 1;
					list.pop_back();
					break;
				}
			}
			word.clear();
		}
		else
		{
			word += input_str[i];
		}
	}

	return list;
}
