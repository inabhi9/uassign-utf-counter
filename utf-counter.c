/**
* This code demonstrates the non-Ascii UTF-8 encoded characters count appeared in a string.
* It takes stdin file as an input and prints output as in stdout, counts for per line.
* 
* Date: 26 Feb 2014
* Author: Abhinav <in.abhi9@gmail.com>
**/

#include <stdio.h>


int main(void){
    int noOfUtfChars = 0;
    char ch;

    while( (ch = fgetc(stdin) ) != EOF){
        if (ch == '\n' || ch == '\r' || ch == EOF){
            // new line encountered so print number of UTF characters
            // found in the line, trailing with new line
            printf("%d%c", noOfUtfChars, '\n');

            // reset for next line
            noOfUtfChars = 0;
        }

        // performs bitwise AND operation to extract top 2-bits and checks
        // whether it represents UTF character's starting sequence byte?
        // if so, increase the count and ignore the rest bytes in the sequence
        if( (ch & 0xC0) == 0xC0) noOfUtfChars++;
    }

    return 0;
}
