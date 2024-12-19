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

int main()
{
  Complex buffer;
  FILE *file = fopen(FILE_NAME, "wb+");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int i;
  Complex complex[3];
  for (i = 0; i < N; i++)
  {
    scanf("%lf%lf", &complex[i].real, &complex[i].i);
  }
  for (i = 0; i < N; i++)
  {
    fwrite(&complex[i], sizeof(Complex), 1, file);
  }

  fclose(file);
  return 0;
}