#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_possible_digits(int number, int base){
    int count = 0;
    while(number != 0){
        number = number/base;
        count = count + 1;
    }

    return count;
}

char convert_hex_digit(char c){
    int rem = c - '0';
    if(rem == 0){
        return 'A';
    }
    if(rem == 1){
        return 'B';
    }
    if(rem == 2){
        return 'C';
    }
    if(rem == 3){
        return 'D';
    }
    if(rem == 4){
        return 'E';
    }
    if(rem == 5){
        return 'F';
    }
}

char * convert(char * number, char * base){
    int b, n, rem;
    b = atoi(base);
    n = atoi(number);
    int size = count_possible_digits(n, b);

    char * digits_n_system;
    digits_n_system = calloc(size, sizeof(char));
    while(n != 0){
        rem = n % b;
        if(b == 16 && rem >= 10){
            rem = rem - 10;
            char c = rem + '0';
            digits_n_system[size - 1] = convert_hex_digit(c);
        }else{
            digits_n_system[size - 1] = rem + '0';
        }
        size = size - 1;
        n = n/b;
    }

    return digits_n_system;
}

int main(){
    char * number, *octal,*binary, *hexa;
    number = calloc(10, sizeof(char));

    printf("Enter a number: ");
    scanf("%s", number);

    octal = convert(number, "8");
    binary = convert(number, "2");
    hexa = convert(number, "16");
    printf("decimal number: %s\noctal number: %s\nbinary number: %s\nhexadecimal number: %s", number, octal, binary, hexa);

    return 0;
}
