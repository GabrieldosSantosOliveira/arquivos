#include <stdio.h>
#define FILE_NAME "dados"
#define N 10
#define ERROR_OPEN_FILE 30
typedef enum
{
  true = 1,
  false = 0
} bool;

int main()
{
  int buffer;
  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  while (true)
  {
    int chunck_read = fread(&buffer, sizeof(int), 1, file);
    if (chunck_read == 0)
    {
      break;
    }
    printf("%d\n", buffer );
  }

  fclose(file);
  return 0;
}