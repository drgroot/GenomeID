#include <stdio.h>
#include "genomeid.h"

int main(){
  struct genomeid_args arguments;
  arguments.ref_version = 19;
  arguments.file = "../samples/sample1.vcf";
  arguments.file_type = "vcf";

  generate_id( &arguments );
}
