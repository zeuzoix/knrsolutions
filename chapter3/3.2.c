/* Exercise 3-2. Write a function escape (s, t) that converts characters like
newline and tab into visible escape sequences like \n and \ t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.*/
#include <stdio.h>
#define MAXSTRLEN 1000

escape(char s[], char t[])
{
	int i = 0;
	int j = 0;
	while(s[i])
	{
		switch(s[i]) {
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = s[i];
				break;
		}
		i++;
	}
	t[j++] = '\0';
}

escape_reverse(char s[], char t[])
{
	int i = 0;
	int j = 0;
	while(s[i])
	{
		switch(s[i]) {
			case '\\':
				i++;
				switch(s[i]) {
					case 'n':
						t[j++] = '\n';
						break;
					case 't':
						t[j++] = '\t';
						break;
					default:
						t[j++] = '\\';
						t[j++] = s[i];
						if (s[i] == 0)
							i--;
				}
				break;
			default:
				t[j++] = s[i];
				break;
		}
		i++;
	}
	t[j++] = '\0';
}

main()
{
	char source[MAXSTRLEN];
	char translated[MAXSTRLEN];
	int c;
	int i = 0;

	while (EOF != (c = getchar())) {
		source[i++] = c;
		if ('\n' == c) {
			source[i++] = '\0';
			i = 0;
			printf("source: %s", source);
			//escape(source, translated);
			escape_reverse(source, translated);
			printf("translated: %s\n", translated);
		}
	}

}
