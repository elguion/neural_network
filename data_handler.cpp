#include "data_handler.hpp"


 data_handler::data_handler()
 {
    data_array = new std::vector<dataset*>;
    training_set = new std::vector<dataset*>;
    test_set = new std::vector<dataset*>;
    validation_set = new std::vector<dataset *>;

 }
 data_handler::~data_handler()
 {
   // Destructor
 }

  void  data_handler::split_data ( double test_ratio  = 0.2 ,  double validation_ratio = 0.2)
  {
      std::unordered_set<int> used_indexes ;

      int training_ratio = 1 - test_ratio ;

      int training_size = data_array->size()*training_ratio ;
      int test_size = data_array->size() *test_ratio ;
      int validation_size = data_array->size()*validation_ratio ;


      int count = 0 ;

      while (count < training_size)
      {
         int rand_index = rand() % data_array->size() ;
         
         if (used_indexes.find(rand_index) == used_indexes.end())
         {
            training_set->push_back(data_array->at(rand_index));
            used_indexes.insert(rand_index);

         

         }


         count++;
      }

      count = 0 ;

      while ( count < test_size)
      {
        int rand_index = rand()% data_array->size();

        if(used_indexes.find(rand_index)== used_indexes.end())
        {
            test_set->push_back(data_array->at(rand_index));
            used_indexes.insert(rand_index);
        }
          count++;
      }


      count = 0 ;

      while(count < validation_size)
      {
          int rand_index = rand()% data_array->size();

          if(used_indexes.find(rand_index) == used_indexes.end())
          {
            validation_set->push_back(data_array->at(rand_index));
            used_indexes.insert(rand_index);


          }

       count++;

      }
  }
  void data_handler::read_feature( std::string path)
  {
     uint8_t header [4];
     unsigned char bytes [4];

     FILE *file = fopen(path.c_str() , "r");

     if (!file)
     {
       std::cerr << "Error : File not found" << '\n';
       exit(1);

     }

     else
     {
        for (int i = 0; i<4 ; i++)
        {
          if(fread(bytes , sizeof(bytes) , 1 , file))
          {
            header[i] = convert_little_endian(bytes);

          }



        }
        int image_size = header[2]*header[3];

        for ( int i = 0; i < header[1]; i++)
        {
           dataset *data = new dataset();
           uint8_t element[i];

           for (int j = 0; j < image_size; j++)
           {
             if (fread(element , sizeof(element) , 1 ,file))
             {
                data->append_feature(element[0]);
             }
             else
             {
               std::cerr <<"Error encountered while reading file" <<'\n';
               exit(1);

             }
             data_array->push_back(data);
           }
            
        }


           std::cout << " Features read successfuly "  << data_array->size() << '\n';
     }
  }
  void data_handler::read_feature_label( std::string path)
  { 
    uint8_t header [2]; //MAGIC | IMAGE_SIZE
     unsigned char bytes [4];

     FILE *file = fopen(path.c_str() , "r");

     if (!file)
     {
       std::cerr << "Error : File not found" << '\n';
       exit(1);

     }

     else
     {
        for (int i = 0; i<2 ; i++)
        {
          if(fread(bytes , sizeof(bytes) , 1 , file))
          {
            header[i] = convert_little_endian(bytes);

          }



        }
    

        for ( int i = 0; i < header[1]; i++)
        {
           dataset *data = new dataset();
           uint8_t element[i];
            
           
             if (fread(element , sizeof(element) , 1 ,file))
             {
                data_array->at(i)->set_label(element[0]);
             }
             else
             {
               std::cerr <<"Error encountered while reading file label" <<'\n';
               exit(1);

             }
             
           
            
        }


           std::cout << " Labels read successfuly "  << data_array->size() << '\n';
     }

  }
  int count_classes ()
  {

  }
  uint32_t convert_little_endian( const char* bytes)
  {
    return uint32_t (bytes[0]<< 24) | (bytes[1]<< 16) | (bytes[2]<< 8) | (bytes[3]);
  }
  std::vector <dataset*> * data_handler::get_training_data()
  {
    return training_set;
  }
  std::vector<dataset*> * data_handler::get_test_data()
  {
     return test_set ;
  }
  std::vector<dataset*> *data_handler::get_validation_data ()
  {
     return validation_set ;
  }


int main()


{


  data_handler data =  data_handler();
  std::clog << "The implementation phase" << '\n';









}