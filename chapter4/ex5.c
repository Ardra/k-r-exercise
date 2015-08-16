#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXOP 100
#define NUMBER '0'
#define MATH_FUN 'F'

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathfun(char []);

main()
{
  int type;
  double op2,op1;
  char s[MAXOP];

  while((type=getop(s))!=EOF){
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop()+pop());
      break;
    case '*':
      push(pop()*pop());
      break;
    case '-':
      op2=pop();
      push(pop()-op2);
      break;
    case '/':
      op2=pop();
      if(op2!=0.0)
	push(pop()/op2);
      else
	printf("error: zero divisor\n");
      break;
    case '%':
      op2=pop();
      if(op2!=0.0)
	push(fmod(pop(),op2));
      else
	printf("error:zero divisor\n");
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    case '?'://to print topmost eleement of stack
      op2=pop();
      printf("topmost element of stack %.8g\n",op2);
      push(op2);
      break;
    case 'd'://duplicate topmost element
      op2=pop();
      push(op2);
      push(op2);
      break;
    case 's'://swap topmost elements
      op2=pop();
      op1=pop();
      push(op2);
      push(op1);
    case 'c'://clear stack
      clear();
      break;
    case 'F':
      mathfun(s);
      break;

    default:
      printf("error:unknown command %s\n",s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp=0;
double val[MAXVAL];

void push(double f)
{
  if(sp<MAXVAL)
    val[sp++]=f;
  else
    printf("error:stack full ,can't push %g\n",f);
}
double pop(void)
{
  if(sp>0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include<ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i,c;
  while((s[0]=c=getch())== ' '|| c== '\t')
    ;
  s[1]='\0';
  if(islower(c)){
    while(islower(s[++i]=c=getch()));
    s[i]='\0';
    if(c!=EOF){
      ungetch(c);
    }
    if(strlen(s)>1)
      {
	return MATH_FUN;
      }
    else{
      return c;
    }
  }

  if(!isdigit(c)&&c!='.'&&c!='-')
    return c;
  i=0;
  if(c=='-'){
    if(isdigit(c=getch())||c=='.'){
      s[++i]=c;
    }
    else{
      if(c!=EOF)
	ungetch(c);
      return '-';
    }
  }
  if(isdigit(c))
    while(isdigit(s[++i]=c=getch()))
      ;
  if(c=='.')
    while(isdigit(s[++i]=c=getch()))
      ;
  s[i]='\0';
  if(c!=EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100
int bufp=0;
char buf[BUFSIZE];

int getch(void)
{
  return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
  if(bufp>=BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    {
      buf[bufp++]=c;
    }
  return;
}
void clear()
{
  sp=0;
  return;
}
void mathfun(char s[])
{
  double op1,op2;
  if(strcmp(s,"sin")==0){
    push(sin(pop()));
  }
  else if(strcmp(s,"cos")==0){
    push(cos(pop()));
  }
  else if(strcmp(s,"pow")==0){
    op2=pop();
    op1=pop();
    push(pow(op1,op2));
  }
  return;
}