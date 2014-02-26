What is the problem about
=====================


Problem statement says, "Find the count of non-ASCII character in give string which is less than 200chars in size. String will UTF-8 encoded. No garbage. in C without any 3rd party libraries"

----------


Challenge
---------

Well, at a first glance it looks simple like just iterate through the character and count which character is not in ordinal range of 0 to 127 (ASCII).
But UTF-8 comprised sequencial bytes, which makes simple character count little tricky. So the logic is increament only when 1st byte of bytes sequence encountered.

----------

Solution
---------

UTF-8 is made of several sequencial bytes and it also has backward compatibility of representing the ASCII character. It reprensents the ASCII in range of 0x00 to 0x7F as a single byte.
All non-ASCII character has a sequence of bytes to reprensent the single character. It's first byte always in range of 0xC0 to 0xFD. So here is the solution if calculate the bitwise AND of 0xC0 and Character, it'll give whether it's UTF char's first byte or not.


Execution instruction
---------

Please provide lines only ends with either \n. Line containing only \r will generate false result.
To execute under linux environment

	gcc utf-counter.c -Wall
	./a.out < test_cases.txt


#### Refs:
http://www.changhai.org/articles/technology/misc/utf-8.php  

https://en.wikipedia.org/wiki/UTF-8#Description  
