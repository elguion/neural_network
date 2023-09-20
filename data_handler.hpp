#ifndef _DATA_HANDLER_H_
#define DATA_HANDLER_H_


#include<fstream>
#include<map>
#include <vector>
#include<unordered_set>
#include<string>
#include "data.hpp"
#include "stdio.h"
#include "stdint.h"
#include<iostream>




class data_handler 

{
  std::vector<dataset*> *training_set  ;
  std::vector<dataset*> *test_set ;
  std::vector<dataset*> *validation_set ;
  std::vector<dataset*> *data_array;

  int num_classes ;
  int feature_size;
  std::map<uint8_t , int> class_map ;





  public :
   data_handler();
  ~data_handler();

  void split_data (double , double);
  void read_feature( std::string path);
  void read_feature_label( std::string path);
  int count_classes ();
  uint32_t convert_little_endian( unsigned char * bytes);
  std::vector <dataset*> *get_training_data();
  std::vector<dataset*> *get_test_data();
  std::vector<dataset*> *get_validation_data ();






};

#endif