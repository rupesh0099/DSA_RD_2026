#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int size;

    printf("Enter size of string: ");
    scanf("%d", &size);

    str = (char *)malloc(size * sizeof(char));

    if(str == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter a string: ");
    scanf("%s", str); 

    while(*str != '\0') {
        printf("%c", *str);
        str++;
    }

    free(str);

    return 0;
}