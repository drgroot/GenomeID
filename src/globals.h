#include <stdio.h>
#include <regex.h>
#include <string.h>
#include "../uthash/src/uthash.h"
#ifndef GLOBALS_H
#define GLOBALS_H

regex_t is_homo1;
regex_t is_homo0;
regex_t is_misR;

void init(int version);

//hashes for bit marker storages
struct my_hash *bit_loc;
struct my_hash *pengelly;
struct my_hash *autosomes;
struct my_hash *allosomes;
struct my_hash *ref_alle;

struct my_hash {
  int id;
  char name[10];
  UT_hash_handle hh;
};

struct genomeid_args{
  //minimum args required to generate id
  int ref_version;
  char *file;
  char *file_type;
  
  //optional arguments to generate id
  int guess_hg;
  int ucn;
  int include_sex_markers;

  //bam specific variables
  int baq;
  int maq;
  double noise;
  int minRead_depth;
  
  //tabix and vcf specific variables
  char *sampleName;
  int read_col;
};

#endif
