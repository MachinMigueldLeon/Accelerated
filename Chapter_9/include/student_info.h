#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "grade.h"


class Alumno
{
    public:
    //read
    Alumno();
    Alumno(std::istream &in) { read_alumno(in); } //Echa le un ojo a esta superrecursividad
    std::istream & read_alumno(std::istream &in);
    std::string name() const { return n;}
    bool made_all_hw();
    double grade() const;


    private:
    std::string n;
    double midterm,final;
    std::vector<double> homework;
    
};

std::istream & read_hw(std::istream &in,std::vector<double> &hw);

bool compare(const Alumno &x,const Alumno &y);


//std::vector<Alumno> extract_fails(std::vector<Alumno> &s);


#endif
