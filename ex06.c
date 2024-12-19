#include <stdio.h>
#define FILE_NAME "abc"
#define N 3
#define ERROR_OPEN_FILE 30
const int nums[N] = {1629495328, 1629495329, 1629495330};
int main()
{
  FILE *file = fopen(FILE_NAME, "wb");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int i;
  for (i = 0; i < N; i++)
  {
    fwrite(&nums[i], sizeof(int), 1, file);
  }
  fclose(file);
  return 0;
}