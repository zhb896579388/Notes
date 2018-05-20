#ifndef GUARD_grade_h
#define GUARD_grade_h

// 'grade.h'
#include <vector>
#include <string>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
const std::string &letter_grade(double, double, const std::vector<double>&);	// added; ����ɼ��ȼ���ĸ

#endif

