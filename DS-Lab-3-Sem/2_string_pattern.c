#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 100

char str[STR_SIZE], pat[STR_SIZE / 2], rep[STR_SIZE / 2], res[STR_SIZE];
int flag = 0;

void stringMatch();

int main()
{
    printf("Enter the main string: ");
    fgets(str, STR_SIZE, stdin);
    printf("Enter the pattern string: ");
    fgets(pat, STR_SIZE / 2, stdin);
    printf("Enter the replace string: ");
    fgets(rep, STR_SIZE / 2, stdin);

    stringMatch();

    if (flag == 1)
    {
        printf("the resulting string is :%s\n", res);
    }
    else
    {
        printf("pattern string not found!\n");
    }
    return 0;
}

// void stringMatch()

// {
//     int strIndex = 0;
//     int patIndex = 0;
//     int resIndex = 0;

//     while (str[strIndex] != '\0')
//     {
//         if (str[strIndex + patIndex] == pat[patIndex])
//         {
//             patIndex++;
//             if (pat[patIndex] == '\0')
//             {
//                 flag = 1;
//                 for (int i = 0; rep[i] != '\0'; i++)
//                 {
//                     res[resIndex++] = rep[i];
//                 }
//                 resIndex += patIndex;
//                 patIndex = 0;
//                 continue;
//             }
//         }
//         else
//         {
//             res[resIndex++]=str[strIndex++];
//             patIndex=0;
//         }
//     }
//     res[resIndex]='\0';
// }
void stringMatch() {
    int strIndex = 0;    // Index for main string
    int patIndex = 0;    // Index for pattern string
    int resIndex = 0;    // Index for result string
    
    // Traverse through the main string
    while (str[strIndex] != '\0') {
        // If characters match, continue matching pattern
        if (str[strIndex + patIndex] == pat[patIndex]) {
            patIndex++;
            
            // If we found complete pattern
            if (pat[patIndex] == '\0') {
                flag=1;
                // Copy replacement string to result
                for (int i = 0; rep[i] != '\0'; i++) {
                    res[resIndex++] = rep[i];
                }
                
                // Move main string index past the matched pattern
                strIndex += patIndex;
                patIndex = 0;
                continue;
            }
        } 
        // If mismatch occurs
        else {
            // Copy current character to result
            res[resIndex++] = str[strIndex++];
            patIndex = 0;
        }
    }
    
    // Add null terminator to result string
    res[resIndex] = '\0';
}
