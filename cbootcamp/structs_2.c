#include <stdio.h>

struct inner_s {
  int i;
  char c;
};

struct outer_s {
  char ar[10];
  struct inner_s in;
};

void func() {
  struct outer_s out_instr;
  out_instr.ar[0] = 'a';
  out_instr.in.i = 42;
  struct outer_s* out_ptr = &out_instr;
  out_ptr-> in.c = 'b';
  return;
}

int main () {
    func();
}