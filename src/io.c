#include <io.h>

char write_to_file(char* filename, double* data, uint64_t size, char binary) {
  if (size == 0) {
    fprintf(stderr, "Attempt to write file of size zero. Failing...\n");
    return FALSE;
  }

  if (binary) {
    return write_binary(filename, data, size);
  } else {
    return write_text(filename, data, size);
  }

  return FALSE;
}

char write_binary(char* filename, double* data, uint64_t size) {
  FILE* fp;
  if ((fp = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "Unable to open binary file %s for write.\n", filename);
    return FALSE;
  }

  fwrite(data, sizeof(double), size, fp);

  fclose(fp);
  return TRUE;
}

char write_text(char* filename, double* data, uint64_t size) {
  FILE* fp;
  if ((fp = fopen(filename, "w")) == NULL) {
    fprintf(stderr, "Unable to open file %s for write.\n", filename);
    return FALSE;
  }

  fprintf(fp, "(");
  for (uint64_t i = 0; i < size; i++) {
    progress(i, size);
    fprintf(fp, "%f ", data[i]);
    clear_progress();
  }
  fprintf(fp, ")");

  fclose(fp);
  return TRUE;
}

void progress(uint64_t curr, uint64_t size) {
  char cursor[4] = {'-', '\\', '|', '/'};
  fprintf(stdout, "%c - %6.2f %% finished", cursor[curr % 4],
          ((float)curr / size) * 100);
}

void clear_progress() {
  fprintf(stdout, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
}
