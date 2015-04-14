#include "genomeid.h"
static const double genomeid_version = 1.0;

int generate_id(struct genomeid_args* args ){
  //check required arguments
  if( !args->ref_version || strlen(args->file) <= 1 || strlen(args->file_type) <= 1 ){
    //missing args
  }
  
  //determine file type
  if( strcmp(args->file_type, "vcf") == 0 ){
    if( (int) strlen(args->sampleName) <= 1 ){
	   args->read_col = 10;
	 }
	 else{
      // determine which col has samplename

	 }
	 vcf_parse( args );
  }

  return 1;
}