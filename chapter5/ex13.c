#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define TAIL 10
#define MAXLEN 1000


#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}


int getline_ptr(char *s, int lim) {
	char c = '\0';
	char *p = s;
	
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - p;
}

void line_shift(char *lineptr[], int shift_size, int nlines) {
	int i;

	strcpy(allocbuf, allocbuf + shift_size);

	for (i = 1; i < nlines - 1; i++)
		lineptr[i] = lineptr[i+1];
}

int readlines_tail(char *lineptr[], int ntail) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline_ptr(line, MAXLEN)) > 0) {
		if (nlines >= ntail) {
			line_shift(lineptr, strlen(lineptr[0])+1, nlines);

			if ((p = alloc(len)) == NULL)
				return -1;
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines - 1] = p;
		}
		else if ((p = alloc(len)) == NULL) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return 0;
}

void writelines(char *lineptr[], int nlines) {
	int i;
	printf("\nlines\n");
	for (i = 0; i < nlines; i++)
		printf("[%d]\t%s\n", i, lineptr[i]);

	printf("\n");
}

int main (int argc, char *argv[]) {
	int res;
	int tmp;
	int ntail = TAIL;
	char *lineptr[ntail];

	if (argc > 2) {
		printf("\nUsage:\n\t%s -n\n\tn -\tnumber of tailed lines\n", argv[0]);
		return 1;
	}
	if (argc == 2 && argv[1][0] == '-') {
		tmp = atoi(argv[1]+1);
		if (tmp > 0 && tmp < INT_MAX)
			ntail = tmp;
	}

	printf("ntail = %d\n", ntail);

	
	res = readlines_tail(lineptr, ntail);
	if (res) {
		printf("error: input too big\n");
		return -1;
	}
	writelines(lineptr, ntail);

	return 0;
}
