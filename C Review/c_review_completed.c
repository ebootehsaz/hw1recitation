#include <stdio.h>    // Includes the Standard Input Output header file.
                     // This header file is necessary for performing input and output operations
                     // such as reading from the keyboard and writing to the screen.
                     // It provides functionalities through functions like printf, scanf, etc.

#include <string.h>  // Includes the String header file.
                     // This header file contains functions for handling strings (arrays of characters).
                     // It provides functionalities for manipulating strings such as strcmp (string compare),
                     // strlen (string length), strcpy (string copy), etc.

#include <stdlib.h>  // Includes the Standard Library header file.
                     // This header file contains functions for performing general utility operations
                     // such as memory allocation, process control, conversions, and others.
                     // It provides functionalities like malloc (memory allocation), free (memory deallocation),
                     // atoi (convert string to integer), exit (terminate the program), etc.


/*
By default, gcc and clang are pretty quiet about compilation warnings and errors, which can be very useful information. 
Explicitly using stricter compiler flags is recommended. Here are some recommended defaults:
-Wall -Wextra -Werror -O2 -std=c99 -pedantic

*/

int main() {

/*
Definition and Declaration: 
A pointer in C is a variable that stores the memory address of another variable. 
To declare a pointer, you specify the data type of the variable it points to and use the * operator. 
*/
int *inp; // Pointer to an integer
char *chp; // Pointer to a character

// ints are usually 4 bytes (use the `sizeof` operator to check)
int x_int = 0;

// Shorthands for multiple declarations:
int i1 = 1, i2 = 2;

int b, c;
b = c = 0;

int *px, pxx; // px is a pointer to an int
pxx = 5;
px = &pxx;


// sizeof(T) gives you the size of a variable with type T in bytes
// sizeof(obj) yields the size of the expression (variable, literal, etc.).
printf("Size of int ptr %zu\n", sizeof(int*)); // => 8 (Depends on machine)
printf("Size of int %zu\n", sizeof(int)); // => 4 (on most machines with 4-byte words)
printf("Size of char %zu\n", sizeof(char)); // => 1 (on most machines with 4-byte words)

// chars are defined as the smallest addressable unit for a processor.
// This is usually 1 byte, but for some systems it can be more (ex. for TMS320 from TI it's 2 bytes).
char x_char = 0;
char y_char = 'y'; // Char literals are quoted with ''

/*
Initialization and Dereferencing:
You can initialize a pointer to hold the address of a variable using the & operator. 
Dereferencing a pointer is done using the * operator to access the value at the pointer's address:
*/
int var = 10;
int *ptr = &var; // Pointer p holds the address of var
printf("%d\n", *ptr); // Dereferencing p gives 10

/*
Pointer Arithmetic:
Pointers support arithmetic operations like addition and subtraction. 
For example, p + 1 will give the address of the next memory location after p, depending on the type of pointer.

Pointers and Arrays: 
An array name in C acts like a pointer to its first element. 
Therefore, you can use pointers to iterate through an array:
*/

// Arrays must be initialized with a concrete size.
char my_char_array[20]; // This array occupies 1 * 20 = 20 bytes
int my_int_array[20]; // This array occupies 4 * 20 = 80 bytes
// (assuming 4-byte words)

/*
Explicit Initialization:
You can explicitly initialize an array.
In this example, all elements of arr are initialized to zero. 
Even partial initialization like 
would initialize the first two elements to 1 and 2, respectively, and the rest to zero.
*/
int x[] = {1,2,3}; // x has type int[3] and holds 1,2,3
int y[5] = {1,2,3}; // y has type int[5] and holds 1,2,3,0,0
int z[4] = {1}; // z has type int[4] and holds 1,0,0,0
int w[3] = {0}; // w has type int[3] and holds all zeroes

// Integer Arrays: 
// An integer array in C is a collection of elements of type int, stored in contiguous memory locations. For example:
int arr[5];// = {1, 2, 3, 4, 5};
int *ptr2 = arr; // Equivalent to int *p = &arr[0];
for(int i = 0; i < 5; i++) {
    printf("%d ", *(ptr2 + i)); // Prints each element in the array
}
printf("\n");
/*
Character Arrays: 
Character arrays are used to store sequences of characters and are typically used to represent strings. 
A character array must be null-terminated (ending with \0) to be a valid string. For example:

This is necessary to accommodate the 5 characters of "Hello" plus the null terminator \0 
which is automatically added at the end of string literals in C. 
*/
char name[6] = "Hello"; // 5 characters + 1 null terminator
// It's good practice to use `const char *' when referring to a string literal,
// since string literals shall not be modified (i.e. "foo"[0] = 'a' is ILLEGAL.)
const char *my_str = "This is my very own string literal";

/*
Here, you're not explicitly specifying the size of the array. 
Instead, you're allowing the compiler to automatically determine the size based on the initialization. 
The compiler will size the array to fit the string literal "Hello" and its null terminator. 
In this case, the compiler will also create an array of size 6.
*/
char* name2 = "Hello";



unsigned int u_val = 253;
char c2 = (char) u_val;

printf("Unsigned value: %u\n", u_val);
printf("Signed value: %d\n", (signed int) u_val);
printf("Char value: %d\n", c2);

unsigned char uc = (unsigned char) c2;  
unsigned int result = (unsigned int) uc;
printf("Unsigned Char value: %u\n", uc);
printf("Unsigned int value: %u\n", result);

// The value 253 in a 32-bit binary representation is 00000000 00000000 00000000 11111101.
// The cast to char converts 253 into a 1-byte value.
// In most systems, char is signed by default, meaning it can represent values from -128 to 127.


// branching with multiple choices: switch()
int a = 1;
switch (a) {
  case 0: // labels need to be integral *constant* expressions (such as enums)
    printf("Hey, 'a' equals 0!\n");
    break; // if you don't break, control flow falls over labels
  case 1:
    printf("Huh, 'a' equals 1!\n");
    break;
    // Be careful - without a "break", execution continues until the
    // next "break" is reached.
  case 3:
  case 4:
    printf("Look at that.. 'a' is either 3, or 4\n");
    break;
  default:
    // if `some_integral_expression` didn't match any of the labels
    // The default case in a switch statement is optional. 
    // It serves as a catch-all for any values not explicitly handled by case statements.
    fputs("Error!\n", stderr);
    exit(-1);
    break;
}


// Example of buffer overflow effect

char password[4] = {'S', 'e', 'e', '\0'};
char input[4]; 

printf("Enter password: ");
gets(input);

// printf("You entered: %s\n\n", input);

int areEqualStr = strcmp(input, password) == 0; // strcmp returns 0 if strings are eq
if (areEqualStr) {
    printf("You are ADMIN\n");
    system("/bin/sh");
} else {
    printf("You are user\n");
}

// printf("Your pass: %s\n", password);

// null terminator on Mac is Shift+control+2
// Minimum answer is len 5, technically len 4 because gets will add a null terminator
// Answer 1: Pas0Pas0
// Optimal Answer: 00000


return 0;

}