#include <stdio.h>

// To execute C, please define "int main()"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int min(int a, int b){
  return (((a<b) )? (a) : (b));
}

int max(int a, int b){
  return  (((a>b) )? (a) : (b));
}


int main() {

int x = 3, y = 5;
printf("Macro-func just copy a code,so value will increment twice\n");
printf("First, will return value and after that will be post-increment\n");
printf("MAX(%d, %d) = %d;\n", x, y, MAX(x++, y));
x = 3, y = 5;
printf("First will be pre-increment value and after that will return value\n");
printf("MIN(%d, %d) = %d;\n", x, y,MIN(++x,y));
printf("\n\n");
x = 3, y = 5;
printf("Regular functions will increment value once\n");
printf("max(%d, %d) = %d;\n", x, y, max(++x, y));
x = 3, y = 5;
printf("min(%d, %d) = %d;\n", x, y, min(x++, y));

  return 0;
}
