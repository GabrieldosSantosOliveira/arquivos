#include <stdio.h>
#define NOME_ARQUIVO "dados"
#define ERROR_OPEN_FILE 30
#define N 100

int main()
{
  FILE *file = fopen(NOME_ARQUIVO, "w");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int i;
  for (i = 1; i <= N; i++)
  {
    fprintf(file, "%d\n", i);
  }
  fclose(file);
  return 0;
}