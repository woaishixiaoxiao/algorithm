#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int match(const char *str, const char *pattern)
{
    int i;
    int str_len, pattern_len;
    if(str == '\0') {
    	str_len = 0;
	}else {
		str_len = strlen(str);
	}
	if(pattern == '\0') {
		pattern_len = 0;
	}else{
		pattern_len = strlen(pattern);
	}
    if (!str_len && !pattern_len)
        return 0;
    if (!pattern_len || !str_len)
        return -1;
    if (pattern[0] == '*') {
    	while()
        for (i = 0; str[i]; i++)
            if (0 == match(str + i, pattern + 1))
                return 0;
        return -1;
    } else if (pattern[0] == '?') {
        return match(str + 1, pattern + 1);
    } else {
        return pattern[0] == str[0] ? match(str + 1, pattern + 1) : -1;
    }
}
int main() {
	char *str1, *str2;
	str1 = (char*)malloc(1000 * sizeof(char));
	str2 = (char*)malloc(1000 * sizeof(char));
	scanf("%s", str1);
	scanf("%s", str2);
    if(match(str1, str2) == 0) {
        printf("%s", "match");
    }else {
    	printf("%s", "unmatch");
    }
}
