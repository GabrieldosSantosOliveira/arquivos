#include <stdlib.h>
#include <stdio.h>
#define MISSING_PARAM_ERROR 10
int main(int argc, char **argv)
{
  if (argc < 3)
  {
    printf("Informe os valores de A e B\n");
    return MISSING_PARAM_ERROR;
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  printf("%d\n", a);
  while (a != b)
  {
    if (a > b)
      a--;
    else
      a++;
    printf("%d\n", a);
  }
  return 0;
}