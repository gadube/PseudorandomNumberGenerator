#include <args.h>
#include <io.h>
#include <prng.h>
#include <randlc.h>

int main(int argc, char** argv) {
  uint64_t N;
  char binary;
  char fname[1024];
  handle_args(argc, argv, &N, &binary, fname);

#ifdef DEBUG
  fprintf(stderr, "filename = %s\n N = %lu\n bin? %s\n\n", fname, N,
          (binary) ? "yes" : "no");
#endif

  double* data = (double*)malloc(sizeof(double) * N);
  prng(data, N);
  write_to_file(fname, data, N, binary);

  free(data);
  return 0;
}

void prng(double* data, uint64_t size) {
  double seed = 314159265;

  for (uint64_t i = 0; i < size; i++) {
    data[i] = randlc(&seed);
  }
}
