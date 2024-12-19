#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MISSING_PARAM_ERROR 10
int main(int argc, char **argv)
{
  int a, b;
  if (argc < 5)
  {
    printf("Informe os valores de A e B e as flags -start e -stop\n");
    return MISSING_PARAM_ERROR;
  }
  if (strcmp(argv[1], "-start") == 0)
  {
    a = atoi(argv[2]);
    b = atoi(argv[4]);
  }
  else
  {
    b = atoi(argv[2]);
    a = atoi(argv[4]);
  }
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