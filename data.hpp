#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include "stdint.h"
#include "stdio.h"


class dataset

{
  std::vector<uint8_t> *feature ;
  uint8_t label ;
  uint8_t enum_label ;
  
  
  public :
  dataset();
  ~dataset();
  void set_feature_vector (std::vector <uint8_t> *);
  void append_feature (uint8_t);
  void set_label(uint8_t );
  void set_enum_label (uint8_t);

  int  get_feature_size();
  uint8_t get_label(); 
  uint8_t get_enum_label();
  std::vector <uint8_t> *get_feature  () ; 

};

#endif