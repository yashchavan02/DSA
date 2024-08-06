#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsPangram(char* s) {
    int* arr = (int*)malloc(26 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }

    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            arr[s[i] - 'a']++;
        } else if ('A' <= s[i] && s[i] <= 'Z') {
            arr[s[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) {
            free(arr);
            return false;
        }
    }

    free(arr);
    return true;
}

int main() {
    char s[50];
    printf("Enter the sentence : ");
    fgets(s, sizeof(s), stdin); 
    s[strcspn(s, "\n")] = 0;

    if (IsPangram(s)) {
        printf("Given sentence is a pangram.\n");
    } else {
        printf("Given sentence is not a pangram.\n");
    }

    return 0;
}
