Small test case only includes numbers up to 300 to ensure that 
testing the '1-table' deviation works as advertised. 1-table 
cuckoo hashing has no use at all in practice but it does make
it clear what kinds of problem cuckoo hashing faces (repeatedly
rehashing to the same spot, impact of table sizes, etc.).

Larger test cases more meaningful to 2-table, 3-table, 4-table,
and 5-table systems.

6000_2.txt says that up to 6000 elements may be in the hash at one time
and the 2 says 2 tables are being used.

The 6000_2 test case is used to determine if the special 50/50
mode is better than our naive 50/50 mode. Surprisingly,
our method outperforms the special 50/50 method.

The 6000 test cases were used to determine the effectiveness of
changing the max loop size. 
