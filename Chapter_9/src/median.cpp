#include "median.h"

//Finding medians
double median_func(std::vector<double> vec){
    typedef std::vector<double>::size_type vector_size;  //Creo el tipo de dato  vector_size que guarda el tamano del vector double
    vector_size size = vec.size();

    if(size == 0){
        throw std::domain_error ("median empty vector");
    } 

    std::sort(vec.begin(),vec.end());
    vector_size vector_mid = size/2;
    double median;

    return median = size % 2 == 0 ? (vec[vector_mid - 1] + vec[vector_mid]) / 2
                           :  vec[vector_mid];
}