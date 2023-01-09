#include <args.h>

void usage() {
  fprintf(stderr,
          "Usage: ./prng [-hb] [-n NUM_VALS] [-o OUTFILE]\n"
          "       -h          show this help menu\n"
          "       -b          generate binary file\n"
          "       -n <NUM>    the number of values to create (default = 2^25)\n"
          "       -o <FILE>   give name to output file (default = "
          "pseudorandomnumbers.txt\n\n");
  exit(-1);
}

void handle_args(int argc, char** argv, uint64_t* N, char* binary,
                 char* filename) {
  *N = 33554432;
  *binary = 0;
  strcpy(filename, "pseudorandomnumbers.txt");

  int opt;
  while ((opt = getopt(argc, argv, "hbn:o:")) != -1) {
    switch (opt) {
      case 'h':
        usage();
        break;
      case 'b':
        *binary = 1;
        break;
      case 'o':
        strcpy(filename, optarg);
        break;
      case 'n':
        *N = atoll(optarg);
        break;
      case '?': {
        usage();
        break;
      }
      default:
        exit(-1);
    }
  }

  int idx = optind;
  if (idx != argc) {
    fprintf(stderr, "Unknown arguments:\n");
    for (; idx < argc; idx++) {
      fprintf(stderr, "\t%s\n", argv[idx]);
    }
      fprintf(stderr, "\n");

    usage();
  }
}
