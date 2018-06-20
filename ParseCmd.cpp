#include "ParseCmd.h"

// callback_list_type is a map of strings and function pointers
int ParseCmd::get_cmd(WINDOW *cmd_line, std::string input, callback_list_type callback_list)
{
	// this is the container for what the user just typed
	// callback list is a map that contains a string key and a function pointer value.
	//  this grabs an iterator to the the match it found.
	//  if there is not a match, find returns the iterator, which will point to the
	//  the last element + 1, which is how the if statement determines whether it found a
	//  match.
	

	std::vector<std::string> formated_input = ParseCmd::tokenize_string(input);

	auto the_function = callback_list.find(formated_input[0]);
	if (the_function != callback_list.end())
	{
		(*the_function->second)(cmd_line);
		return 0;
	}
	else
	{
		return 1;
	}
}


std::vector<std::string> ParseCmd::tokenize_string(std::string input_str, char delimeter)
{
	// TODO: add options so that the user can decide where the words are broken up at.

	// data for the tokenizer
	std::vector<std::string> list;
	std::string word = "";

	// tokenizes the input string
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

ParseCmd::token_data ParseCmd::summarize_string(std::string input_str)
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
