#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n");
    printf("\nInteger Formats\n");
    printf("%u\n",integer_value);
    printf("0x%x\n",integer_value);
    printf("0%o\n",integer_value);
    printf("|%5d|\n",integer_value);
    printf("|%-5d|\n",integer_value);
    printf("\nFloat Formats\n");
    printf("%f\n",float_value);    
    printf("%.2f\n",double_value); //both double and float seem to work.
    printf("%e\n",float_value);    
    printf("%.5g\n",float_value);    
    printf("\nCharacter and String Formats\n");
    printf("%c\n",char_value);
    printf("%s\n",string_value);
    printf("|%20s|\n",string_value);
}