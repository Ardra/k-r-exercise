#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100
#define MAXLINES 1000
#define NKEYS (sizeof noise / sizeof(char*))

struct tnode {      
  char *word;
  int count;
  int linenum[MAXLINES];
  struct tnode *left;
  struct tnode *right;
};

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
int isnoiseword(char *word);
int binsearch(char*, char*[], int);

char buf[BUFSIZE];      
int bufp = 0;          

char *noise[] = {"a", "and", "are", "as", "at", "i", "if", 
		 "in", "is", "it", "of", "on", "or", "the", "to", "with", "you"};

int main(int argc, char *argv[])
{
  struct tnode *root;
  char word[MAXWORD];
  char c;
  int nlines = 1;

  root = NULL;
  while ((c=getword(word, MAXWORD)) != EOF) {
       
    int i;
    for(i = 0; word[i] != '\0'; i++)
      word[i] = tolower(word[i]);

    if (c == '\n')
      nlines++;
    else if (!noiseword(word))
      root = addtree(root,word,nlines);
  }
  treeprint(root);
  return 0;
}

int noiseword(char *word)
{
  return binsearch(word, noise, NKEYS) < 0 ? 0 : 1;
}

int binsearch(char* word, char *list[], int len)
{
  int cond;
  int low, high, mid;

  low = 0;
  high = len - 1;
  while(low <= high) {
    mid = (low+high) / 2;
    if ((cond = strcmp(word, list[mid])) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
    }
 return -1;
}


struct tnode *addtree(struct tnode *p, char *w, int lnum)
{
    int cond;

    if (p == NULL){
      p = talloc();   
      p->word = strdup(w);
      p->linenum[0] = lnum;
      p->count = 1;
      p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) == 0)
      p->linenum[p->count++] = lnum;
    else if (cond < 0)  
        p->left = addtree(p->left, w, lnum);
    else                
        p->right = addtree(p->right, w, lnum);
    return p;
}

void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);

    printf("Word: %-15sTotal: %i\n", p->word, p->count);
    printf("  Appears on: ");
    int i;
    for (i = 0; i < p->count; ++i)
      printf("%i ", p->linenum[i]);
    printf("\n");
        
    treeprint(p->right);
  }
}

int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch())) {
    if (c == '\n')
      return c;
  }
    
  if (c == EOF)
    return c;

  *w++ = c;
  while (--lim > 0) {
    c = getch();
    if (c != ' ' && c != EOF && c != '\n')
      *w++ = c;
    else {
      ungetch(c);
      break;
    }
  }
    
  *w = '\0';
  return word[0];
}

int getch(void)    
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

