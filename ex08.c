#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FILE_NAME "m"
#define N 10
#define ERROR_OPEN_FILE 30
typedef enum
{
  true = 1,
  false = 0
} bool;

int main()
{
  float buffer;
  FILE *file = fopen(FILE_NAME, "wb+");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  srand(time(NULL));
  int i;
  for (i = 1; i <= N; i++)
  {
    float aleatorio = (rand() % (10 + 1));
    fwrite(&aleatorio, sizeof(float), 1, file);
  }
  fseek(file, 0, SEEK_SET);
  while (fread(&buffer, sizeof(float), 1, file) != 0)
  {
    printf("%.2f\n", buffer);
  }
  fclose(file);
  return 0;
}