Small test case only includes numbers up to 300 to ensure that 
testing the '1-table' deviation works as advertised. 1-table 
cuckoo hashing has no use at all in practice but it does make
it clear what kinds of problem cuckoo hashing faces (repeatedly
rehashing to the same spot, impact of table sizes, etc.).

Larger test cases more meaningful to 2-table, 3-table, 4-table,
and 5-table systems.
