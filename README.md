# CuckooHashingProject

Cuckoo Hashing Project
--------
Anthony Tavernia, Jackson Hoffman, Connor Stutsrim

Running 'make' will create the executable 'hash' which can be used as follows:

./hash <input-file> <output-file> <D|M> <T|F>

In general, the input file describes the size of the tables at start, 
the number of tables (fixed) and the sequence of input, search, delete, and print
instructions. The output format is made clear by the python script file
we've used to create tests which is present in the testing directory. Additionally,
there are sample test files we've used for testing as well.

However, if the final command line argument is set to T then the program 
expects a 50/50 table and will use a special algorithm design for the first and second
table.

The D or M argument indicates what method hashing should be used. D indicates
using the division method while M indicates to use the multiplication method.

The output-file text was originally planned but has been scrapped. With more time
it'd no longer be included.

The format of prints makes it easier to comprehend output of larger examples
by redirecting standard output to a file. As well, digit sizes for insert look 
good up to 4 digit lengths because of the formatted output style.

There testing directory contains a README itself detailing used test cases. 
The code has some sparse documentation as well.
