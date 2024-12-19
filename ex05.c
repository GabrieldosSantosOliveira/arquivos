#include <stdio.h>
#define ERROR_OPEN_FILE 30
#define N 100
int main()
{
  FILE *file = fopen("dados", "wb");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int i;
  for (i = 1; i <= N; i++)
  {
    fwrite(&i, sizeof(int), 1, file);
  }

  fclose(file);
  return 0;
}