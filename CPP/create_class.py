import os
import sys

special_char_1 = "{"
special_char_2 = "}"

def return_class_h_string(class_name):
	stri = f"""
#ifndef {class_name.upper()}_H
# define {class_name.upper()}_H

# include "string"
# include "iostream"

class {class_name} {special_char_1}
	public:
		{class_name}( void );
		~{class_name}( void );
	
	private:

{special_char_2};

#endif // {class_name.upper()}_H
	"""
	return stri

pwd = os.getcwd()
n = len(sys.argv)

if n != 2:
	print("Please enter the name of the class")
	exit(0)


with open(sys.argv[1] + ".hpp", "w") as f:
	f.write(return_class_h_string(sys.argv[1]))