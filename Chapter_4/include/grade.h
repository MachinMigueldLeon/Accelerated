#ifndef GUARD_GRADE_H
#define GUARD_GRADE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "median.h"
#include "student_info.h"

/**
 * @brief 
 * 
 * @param midterm 
 * @param homework 
 * @return double 
 */
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double> &hw);
double grade(const struct Alumno &s);
bool fgrade(const struct Alumno &s);
bool pgrade(const struct Alumno &s);


#endif
