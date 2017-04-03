#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid number of arguments. \n");
        return 1;
    }


    int k = atoi(argv[1]) % 26;

    printf("plaintext: ");
    string p = get_string();
    int length = strlen(p);
    int to_encrypt[length];
    int LOWER_Z = 122;
    int UPPER_Z = 90;

    for(int i = 0; i < strlen(p); i++) {
        to_encrypt[i] = p[i];
    }


    for(int j = 0; j < length; j++) {

        if(isupper(p[j]) && to_encrypt[j] + k > UPPER_Z && isalpha(p[j])) {
            to_encrypt[j] -= (26 - k);
        } else if(!isupper(p[j]) && to_encrypt[j] + k > LOWER_Z && isalpha(p[j])) {
            to_encrypt[j] -= (26 - k);
        } else if(isalpha(p[j])){
            to_encrypt[j] += k;
        } else {
            to_encrypt[j] = p[j];
        }
    }

    for(int x = 0; x < length; x++) {
        char c = to_encrypt[x];
        p[x] = c;

    }

    printf("ciphertext: ");
    printf("%s", p);
    printf("\n");
    return 0;

}
