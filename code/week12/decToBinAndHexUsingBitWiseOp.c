#include <stdio.h>
#include <string.h>

// Helper function to reverse a string in place
void reverseString(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Convert a decimal number to binary and store the result in the provided buffer
void decimalToBinary(int num, char *binary)
{
    int index = 0;

    // Handle 0 case
    if (num == 0)
    {
        binary[index++] = '0';
    }

    // Get each bit starting from the least significant
    while (num > 0)
    {
        binary[index++] = (num & 1) ? '1' : '0';
        num >>= 1; // Shift right by 1 bit
    }

    binary[index] = '\0';  // Null-terminate the string
    reverseString(binary); // Reverse to get the correct binary order
}

// Convert a decimal number to hexadecimal and store the result in the provided buffer
void decimalToHexadecimal(int num, char *hex)
{
    int index = 0;

    // Handle 0 case
    if (num == 0)
    {
        hex[index++] = '0';
    }

    // Get each 4-bit chunk (hex digit) starting from the least significant
    while (num > 0)
    {
        int digit = num & 0xF; // Mask last 4 bits
        if (digit < 10)
        {
            hex[index++] = '0' + digit; // 0-9
        }
        else
        {
            hex[index++] = 'A' + (digit - 10); // A-F
        }
        num >>= 4; // Shift right by 4 bits
    }

    hex[index] = '\0';  // Null-terminate the string
    reverseString(hex); // Reverse to get the correct hexadecimal order
}

int main()
{
    char binary[33]; // Buffer to store binary string (32 bits + null terminator)
    char hex[9];     // Buffer to store hexadecimal string (8 hex digits + null terminator)

    for (int i = 1; i <= 1000; i++)
    {
        decimalToBinary(i, binary);
        decimalToHexadecimal(i, hex);
        printf("DEC %d:\tBIN %s\tHEX %s\n", i, binary, hex);
    }

    return 0;
}
