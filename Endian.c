//
//  main.c
//  Coding_Challenge3
//
//  Created by Nidhi Galgali on 3/30/23.
//

#include <stdio.h>
#include <limits.h>
#include <assert.h>

unsigned short my_ntohs(unsigned short in) {
    //    Checking for max value of unsigned short
    if (in > USHRT_MAX) {
        
        return 1;
    }
//    Shift value to right by 8 bits to so MSB->LSB
//    Shift value to left by 8 bits to so LSB->MSB
//    Combine both results using a bitwise OR to produce a swapped value.
    return (in >> 8) | (in << 8);
}

unsigned int my_ntohl(unsigned int in) {
//    Checking for max value of unsigned int
    if (in > UINT_MAX) {
       
        return 1;
    }
//    Shift value right by 24 bits to get 1st MSB and use the 0xff mask to get 1st LSB
//    Shift value right by 8 bits to get 2nd MSB and use the 0xff00 mask to get 2nd LSB
//    Shift value left by 8 bits to get 2nd LSB and use the 0xff0000 mask to get 2nd MSB
//    Shift value left by 24 bits to get 1st LSB and use the 0xff000000 mask to get 1st MSB
//    Combine all the four using Bitwise OR to get the swapped value
    return ((in >> 24) & 0xff) | ((in >> 8) & 0xff00) | ((in << 8) & 0xff0000) | ((in << 24) & 0xff000000);
}

int main () {
//    TEST CASE 1:
    unsigned short inp1 = 0x1234;
    unsigned short output1 = 0x3412;
    printf("\n0x%04x",my_ntohs(inp1));
    assert(my_ntohs(inp1) == output1 && "\nTest Case 1 Failed");
    printf("\nTest Case 1 Passed\n");
//    TEST CASE 2:
    unsigned short inp2 = 0x5678;
    unsigned short output2 = 0x7856;
    printf("\n0x%04x",my_ntohs(inp2));
    assert(my_ntohs(inp2) == output2 && "\nTest Case 2 Failed");
    printf("\nTest Case 2 Passed\n");
//    TEST CASE 3:
    unsigned int inp3 = 0xAABBCCDD;
    unsigned int output3 = 0xDDCCBBAA;
    printf("\n0x%08x",my_ntohl(inp3));
    assert(my_ntohl(inp3) == output3 && "\nTest Case 3 Failed");
    printf("\nTest Case 3 Passed\n");
//    TEST CASE 4:
   
    unsigned int inp4 = 0x01ff01ff;
    unsigned int output4 = 0xff01ff01;
    printf("\n0x%08x",my_ntohl(inp4));
    assert(my_ntohl(inp4) == output4 && "\nTest Case 4 Failed");
    printf("\nTest Case 4 Passed\n");
//    TEST CASE 5:
    unsigned int inp5 = 0x99887766;
    unsigned int output5 = 0x66778899;
    printf("\n0x%08x",my_ntohl(inp5));
    assert(my_ntohl(inp5) == output5 && "\nTest Case 5 Failed");
    printf("\nTest Case 5 Passed\n");


    return 0;
}
/**
 * The htons() and htonl() functions are reversible and can be implemented without writing additional
Logic. I tried testing that with the ntohs() and ntohl() and it worked.
 *  Also, it is essential to use unsigned  because network bytes are supposed to be unsigned.Using a signed integer might might cause errors in bitwise operations.
 */
