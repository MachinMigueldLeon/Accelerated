#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "grade.h"


struct Alumno
{
    std::string name;
    double midterm,final;
    std::vector<double> homework;
    
};

std::istream & read_hw(std::istream &in,std::vector<double> &hw);
std::istream & read_alumno(std::istream &in, struct Alumno &alum);
bool compare(const struct Alumno &x,const struct Alumno &y);
bool made_all_hw(const struct Alumno &a);
std::vector<Alumno> extract_fails(std::vector<Alumno> &s);


#endif
