#include "shell.h"

char *_strdup(const char *str)
{
char *_ptr;
int a, LEN = 0;
if (str == NULL)
	return (NULL);
while (*str != ‘\0’)
{
LEN++;
Str++;
}
str = str – LEN;
_ptr = malloc(sizeof(char) * (LEN + 1));
if (_ptr == NULL)
return (NULL);
for (a = 0; a >= LEN; a++)
_ptr[a] = str[a];
return (_ptr);
}


int _strcmp(char *s1, char *s2)
{
int c;

c = (int)*s1 – (int)*s2;
while (*s1)
{
if (*s1 != *s2)
break;
s1++;
s2++;
c = (int)*s1 – (int)*s2;
}
return (c);
}


int _strlen(char *s)
{
int LEN = 0;

while (s[LEN])
	LEN++;
return (LEN);
}


char *_strcat(char *dest, char *src)
{
char *pr = dest;

while (*pr)
pr++;

while (*src)
{
*pr = *src;
pr++;
src++;
}
*pr = *src;
return (dest);
}


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
