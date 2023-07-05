#include "float_vector.h"
#include <stdio.h>

int main() {
  FloatVector *vec = create(10);
  FloatVector_print(vec);

  FloatVector_append(vec,0.0);
  FloatVector_append(vec,0.2);
  FloatVector_append(vec,0.3);
  FloatVector_append(vec,0.4);
  FloatVector_append(vec,0.5);
  FloatVector_append(vec,0.6);
  FloatVector_append(vec,0.7);
  FloatVector_append(vec,0.8);
  FloatVector_append(vec,0.9);

  FloatVector_print(vec);

  FloatVector_destroy(&vec);

  return 0;
}