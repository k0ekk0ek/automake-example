#include <stdio.h>
#include "config.h"

#if HAVE_WESTMERE
#include "westmere/parser.h"
#endif

#if HAVE_HASWELL
#include "haswell/parser.h"
#endif

int main(int argc, char** argv) {
  printf("hello world!\n");
#if HAVE_WESTMERE
  print_hello_westmere();
#endif
#if HAVE_HASWELL
  print_hello_haswell();
#endif
  return 0;
}
