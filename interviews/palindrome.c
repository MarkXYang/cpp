#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* astr)
{
    char* pforward = astr;
    char* pback = astr + strlen(astr) - 1;
    while(pforward < pback) {
        while(*pforward == ' ') {
            ++pforward;
        }
        while(*pback == ' ') {
            --pback;
        }
        if(*pforward != *pback && *pforward - *pback != 'a' - 'A' && *pback - *pforward != 'a' - 'A')
            return false;
        
        pforward++;
        pback--;
    }
    return true;
}

int main()
{
    //char* s1 = "oppo";
    //printf("%s is palindrome: %d\n", s1, isPalindrome(s1));
    char* s2 = "He    ll Eh";
    printf("%s is palindrome: %d\n", s2, isPalindrome(s2));
    return 0;
}