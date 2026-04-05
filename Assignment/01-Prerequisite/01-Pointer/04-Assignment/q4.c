#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char *name;
    int size, vowels = 0, consonants = 0;

    printf("Enter size of string: ");
    scanf("%d", &size);

    name = (char*)malloc(size*sizeof(char));

    if(name == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter a string: ");
    scanf("%s", name);

    
    int consonant= 0, vowel= 0;
    
    
    for (int i = 0; name[i] != '\0'; i++) {
        char str = tolower(name[i]);
        if (str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u') 
        {
           vowel++;
        }else {
            consonant++;
        }
    }
 
    int count=vowel+consonant;
    printf("count of vowel is: %d\ncount of consonant is: %d\ntotal count is: %d\n",vowel,consonant,count);

    free(name);

    return 0;
}