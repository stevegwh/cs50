#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int y;
    int i;
    int m;
    int j;
    int key_j;
    int x;

    if (argc != 2)
    {
        printf("Invalid argument. \n");
        return 1;
    }

    string k = argv[1];

    for(y = 0; y < strlen(k); y++)
    {
        if(!isalpha(k[y]))
        {
            printf("Invalid argument. \n");
            return 1;
        }
    }

    printf("plaintext: ");
    string p = get_string();

    int length = strlen(p);
    int to_encrypt[length];
    int key_values[length];
    int LOWER_Z = 122;
    int UPPER_Z = 90;
    string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
    string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //creates an array of ascii codes
    for(i = 0; i < strlen(p); i++)
    {
        to_encrypt[i] = p[i];
    }

    // create an array of keycodes
    for(m = 0; m < strlen(k); m++)
    {
        for(int o  = 0; o < 27; o++)
        {
            if(k[m] == alpha_lower[o])
            {
                key_values[m] = o;
            }
            else if(k[m] == alpha_upper[o])
            {
                key_values[m] = o;
            }
        }
    }


    // iterate through the ascii codes and add the keycode to them from the key_values array
    for(j = 0, key_j = 0; j < length; j++, key_j++)
    {
        if(key_j == strlen(k))
        {
            key_j = 0;
        }

        if(isupper(p[j]) && to_encrypt[j] + key_values[key_j] > UPPER_Z && isalpha(p[j]))
        {
            to_encrypt[j] -= (26 - key_values[key_j]);
        }
        else if(!isupper(p[j]) && to_encrypt[j] + key_values[key_j] > LOWER_Z && isalpha(p[j]))
        {
            to_encrypt[j] -= (26 - key_values[key_j]);
        }
        else if(isalpha(p[j]))
        {
            to_encrypt[j] += key_values[key_j];
        }
        else
        {
            key_j--;
            to_encrypt[j] = p[j];
        }
    }

    // convert them back to ascii chars
    for(x = 0; x < length; x++)
    {
        char c = to_encrypt[x];
        p[x] = c;

    }

    printf("ciphertext: ");
    printf("%s", p);
    printf("\n");

    return 0;

}
