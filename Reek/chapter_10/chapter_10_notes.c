#include <stdio.h>

int main(void) {
  
  typedef struct
  {
    int a;
    char b;
    float c;

  } Simple;

  Simple x;

  Simple y[20], *z;

  struct SIMPLE
  {

	int a;
	char b;
	float c;

  };

  struct COMPLEX
  {

	float f;

	int a[20];

	long *lp;
	
	struct SIMPLE s;

	struct SIMPLE sa[10];

	struct SIMPLE *sp;



  };

  struct SELF_REF1
  {
	  int a;
	  struct SELF_REF1 *b;
	  int c;

  };

  struct SELF_REF2
  {
	
	  int a;
	  struct SELF_REF2 *b;
	  int c;

  };

  struct B;

  struct A
  {
	struct B *partner;
	/* other declarations */

  };

  struct B
  {
	
  struct B *partner;
	/* other declarations */

  };

  return 0;

  typedef struct
  {
	
	  int a;

	  short b[2];

  } Ex2;

}

