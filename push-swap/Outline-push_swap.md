# Components needed
- Input and error handling:
	- open file descriptor, read only
	- read a string containing numerical characters, negative and/or positive integers without repetitions
		1. no parameters ("" or argc == 1)
			=> back to command prompt
		2. replace whitespaces with a simple space ' ' (`ft_whitespaces_to_spaces`)
		3. check if certain characters are not numbers: `if (!((char >= '0' && char <= '9') || char != ' ' || char != '-'))`
		4. split characters into arrays of characters, and for each string:
		5. check if '-' is found elsewhere than str[0]
		6. check if `ft_strlen(str)` (or `ft_strlen(str+1)` if str[0] == '-') > 10 (int overflow)

		7. convert the string to an integer (`ft_atoi`)
		8. check overflow: if str[0] == '-' and number > 0 (and vice-versa) return error
		9. malloc an int array of size split_size for the integers (`ft_count_2d_array`)
		10. add elements to the array: for each new element (element i), check if equal to any previous element.
			=> if a repetition is found, write "Error\n" to **stderr**
		11. malloc another array of same size
	- problem: handling 0s (e.g. b_stack is initalized with no elements, thus filled with 0)