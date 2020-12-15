#include "grade.h"



//Ponderacion
double grade(double midterm, double final, double homework){
    return 0.2*midterm + final*0.4 + homework*0.4;
}

double grade(double midterm, double final, const std::vector<double> &hw){
    if(hw.size() == 0)
        throw std::domain_error("No homework\n");
    return grade(midterm,final,median_func(hw));
}
double grade(const struct Alumno &s){
    return  grade(s.midterm,s.final,s.homework);
}
bool fgrade(const struct Alumno &s){
    return grade(s) >= 5.0;
}
bool pgrade(const struct Alumno &s){
    return !fgrade(s);
}

