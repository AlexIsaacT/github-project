 #include<stdio.h>
 #define MAX 1000
 int block_comment(char buffer[]);
 int single_comment(char buffer[]);
 int quotes(char buffer[]);
 int i;
 int main()
 {
 int c;
 char buffer[MAX];
 for (i = 0; i <= MAX; i++)
 {
 buffer[i] = 0;
 }
 for (i = 0; (c = getchar()) != EOF; i++)
 buffer[i] = c;
  i = 0;
  while (buffer[i] != '\0')
   {
    if (buffer[i] == '/' && buffer[i+1] == '*')
    {
    i = block_comment(buffer);
    i++;
   }
    else if (buffer[i] == '/' && buffer[i+1] == '/')
     {
       i = single_comment(buffer);
     }
    else if(buffer[i] == '"' || buffer[i] == '\'')
    {
      i = quotes(buffer);
    }
    else
    {
    printf ("%c", buffer[i]);
    i++;
   }
  }
  printf ("\n");
 }
  int block_comment(char buffer[])
  {
   int j, k;
   char store[MAX];
   for (k = 0; k <= MAX; k++)
   store[k] = 0;
   for (j = i, k = 0; (!(buffer[j] == '*' && buffer[j+1] == '/')); j++,k++)
     {
      store[k] = buffer[j];
       if (buffer[j+1] == '\0')
       {
        printf ("%s", store);
        break;
      }
      }
      i = j + 1;
      return i;
  }
  int single_comment(char buffer[])
  {
    int k;
    for (k = i; buffer[k] != '\n'; k++)
    ;
    i = k + 1;
    return i;
  }
  int quotes(char buffer[])
  {
    int l;
    putchar(buffer[i]);
    for (l = i+1; buffer[l] != '"' && buffer[l] != '\''; l++)
    {
     printf ("%c", buffer[l]);
   }
    putchar(buffer[l]);
     i = l + 1;
     return i;
  }
