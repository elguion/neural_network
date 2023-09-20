#include "data.hpp"


dataset::dataset()
{
    feature = new  std::vector<uint8_t> ;
    
}
void dataset::set_feature_vector (std::vector <uint8_t> *vect)
{
   feature = vect ;
}
void dataset::append_feature (uint8_t val)
{
    feature->push_back(val);
}
void dataset::set_label(uint8_t  value)
{
    label = value ;
}
void dataset::set_enum_label (uint8_t value)
{
   enum_label = value ;

}

int  dataset::get_feature_size()
{
  return  feature->size() ;
}
  uint8_t dataset::get_label()
  {

     return label ;
  }
  uint8_t dataset::get_enum_label()
  {
 return enum_label ;

  }
  std::vector <uint8_t> *dataset ::get_feature  () 
  {
     return feature ;
  }