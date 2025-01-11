#include<stdio.h>
#include<stdlib.h>

#define STR_SIZE 100 
char str[STR_SIZE], pat[50], rep[50], ans[100];
int i, j, c, m, k, flag=0;

int main()
{
    printf("Enter the main string: ");
    fgets(str, STR_SIZE, stdin);
    

    return 0;
}
    
    void string_match(){
    int s, p, r, a;
    for(int i=0; str[i]!='\0'; i++){
        if(str[s]==pat[p]){
            s++;
            p++;
            if(pat[p]=='\0'){
                flag=1;
                for(r=0; rep[r]!='\0'; r++){
                    ans[a]=rep
                }
            }
        }
    }
}
void stringmatch()
{
    i = m = c = j = 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i]) // ...... matching
        {
            i++;
            m++;

            if (pat[i] == '\0')

            {

                //.....found occurrences.

                flag = 1;
                //.... copy replace string in ans string.
                for (k = 0; rep[k] != '\0'; k++, j++)
                    ans[j] = rep[k];
                i = 0;
                c = m;
            }
        } // if ends.
        else 
        {
            //... mismatch
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        } // else ends

    } // end of while ans[j] = '\0';
} // end stringmatch()