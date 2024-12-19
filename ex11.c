#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FILE_NAME "m"
#define N 3
#define ERROR_OPEN_FILE 30
typedef enum
{
  true = 1,
  false = 0
} bool;
typedef struct
{
  double i;
  double real;
} Complex;
void print_complex(Complex *x)
{
  printf("%.2lf%+.2lfi\n", x->real, x->i);
}
int main()
{
  double buffer[2];
  FILE *file = fopen(FILE_NAME, "rb+");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int i;
  while (fread(&buffer, sizeof(double), 2, file) != 0)
  {
    Complex c = {.i = buffer[0], .real = buffer[1]};
    print_complex(&c);
  }
  fclose(file);
  return 0;
}