#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char *s, int start, int end) {
    if (start >= end) {
        return true;
    } 
    if (s[start] != s[end]) {
        return false;
    }

    return is_palindrome(s, start+1, end-1);
}

int main(void) {
    char palabra1[] = "reconocer";
    char palabra2[] = "algoritmo";

    int len1 = strlen(palabra1);
    int len2 = strlen(palabra2);

    // end es el último índice válido: largo - 1
    printf("%s: %s\n", palabra1, is_palindrome(palabra1, 0, len1 - 1) ? "Es palindromo" : "No es palindromo");
    printf("%s: %s\n", palabra2, is_palindrome(palabra2, 0, len2 - 1) ? "Es palindromo" : "No es palindromo");

    return 0;
}