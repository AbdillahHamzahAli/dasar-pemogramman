#include <stdio.h>
#include <string.h>

int getPrecedence(char key) {
    switch (key) {
        case 'q': return 1;
        case 'w': return 2;
        case 'e': return 3;
        case 'r': return 4;
        case 't': return 5;
        case 'y': return 6;
        case 'u': return 7;
        case 'i': return 8;
        case 'o': return 9;
        case 'p': return 10;
        case 'a': return 11;
        case 's': return 12;
        case 'd': return 13;
        case 'f': return 14;
        case 'g': return 15;
        case 'h': return 16;
        case 'j': return 17;
        case 'k': return 18;
        case 'l': return 19;
        case 'z': return 20;
        case 'x': return 21;
        case 'c': return 22;
        case 'v': return 23;
        case 'b': return 24;
        case 'n': return 25;
        case 'm': return 26;
    }
}

void nextPermutation(char* str) {
    int n = strlen(str);
    char* i = &str[n - 2];
    while (i >= str && getPrecedence(*i) >= getPrecedence(*(i + 1))) {
        i--;
    }
    if (i >= str) {
        char* j = &str[n - 1];
        while (j >= str && getPrecedence(*j) <= getPrecedence(*i)) {
            j--;
        }
        char temp = *i;
        *i = *j;
        *j = temp;
    }
    
    char* left = i + 1, *right = &str[n - 1];
    // printf("left: %s\n", left);
    // printf("right: %s\n", right);
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
        printf("%s\n", str);
    }
}

int main()
{
    char str[1000000];
    scanf("%s", str);
    nextPermutation(str);
    printf("%s\n", str);
    return 0;
}


