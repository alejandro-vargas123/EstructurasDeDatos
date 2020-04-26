#include <string.h>
#include <stdio.h>

int main()
{
   char string[10];
   char *str1 = "abcdefghi";

   stpcpy(string, str1);
   printf("%s\n", string);
   return 0;
}
