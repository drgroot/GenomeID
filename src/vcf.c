#include "vcf.h"

void vcf_parse( struct genomeid_args* args ){
  FILE *vcf = fopen( args->file, "r" );
  
  char raw[1024];
  regex_t pound;
  regcomp( &pound, "^#", 0);
  char *token;

  int chr=-1;
  int loc=-1;
  int zyg;

  while(fgets(raw, 1024, vcf) ){
    if(! regexec( &pound, raw, 0, NULL, 0) ){
       continue;
 	 }
    
	 char* line = strdup( raw );
	 int col = 0;
	 while((token = strsep( &line, "\t" ) ) != NULL ){
      if(col++ >= args->read_col){
		  break;
		}
		if( col == 1 )
	     sscanf( token, ".*%d", &chr );
		else if( col == 2 )
		  sscanf( token, ".*%d", &loc );
	 }

    free(line);
	 free(token);
	 break;
  }
  free(vcf);
}
