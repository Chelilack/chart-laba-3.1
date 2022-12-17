#pragma once
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
/// <summary>
/// first > second -> 1
/// first == second -> 2 
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpComplexNumberRE(ComplexNumber first, ComplexNumber second)
{
	if (first.GetRe() == second.GetRe()) { return 2; }
	return first.GetRe() > second.GetRe();
}
/// <summary>
/// first > second = 1 
/// first == second -> 2 
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpComplexNumberIM(ComplexNumber first, ComplexNumber second)
{
	if (first.GetIm() == second.GetIm()) { return 2; }
	return first.GetIm() > second.GetIm();
}
int (*cmpComplexNumber[])(ComplexNumber, ComplexNumber) = { cmpComplexNumberRE,cmpComplexNumberIM };

/// <summary>
/// first > second -> 1 
/// first == second -> 2
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpStudentFirstName(Student first, Student second) 
{
	if (first.GetFirstName() == second.GetFirstName()) { return 2; }
	return first.GetFirstName() > second.GetFirstName();
}
/// <summary>
/// first > second -> 1 
/// first == second -> 2
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpStudentLastName(Student first, Student second) 
{
	if (first.GetLastName() == second.GetLastName()) { return 2; }
	return first.GetLastName() > second.GetLastName();
}
/// <summary>
/// first > second -> 1 
/// first == second -> 2
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpStudentId(Student first, Student second) 
{
	if (first.GetId() == second.GetId()) { return 2; }
	return first.GetId() > second.GetId();
}
int (*cmpStudent[])(Student, Student) = { cmpStudentFirstName,cmpStudentLastName,cmpStudentId };

/// <summary>
/// first > second -> 1 
/// first == second -> 2
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpTeacherFirstName(Teacher first, Teacher second)
{
	if (first.GetFirstName() == second.GetFirstName()) { return 2; }
	return first.GetFirstName() > second.GetFirstName();
}
/// <summary>
/// first > second -> 1
/// first == second -> 2 
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpTeacherLastName(Teacher first, Teacher second)
{
	if (first.GetLastName() == second.GetLastName()) { return 2; }
	return first.GetLastName() > second.GetLastName();
}
/// <summary>
/// first > second -> 1
/// first == second -> 2 
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpTeacherId(Teacher first, Teacher second)
{
	if (first.GetId() == second.GetId()) { return 2; }
	return first.GetId() > second.GetId();
}
/// <summary>
/// first > second -> 1 
/// first == second -> 2
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
/// <returns></returns>
int cmpTeacherSubject(Teacher first, Teacher second) 
{
	if (first.GetSubject() == second.GetSubject()) { return 2; }
	return first.GetSubject() > second.GetSubject();
}
int (*cmpTeacher[])(Teacher, Teacher) = { cmpTeacherFirstName,cmpTeacherLastName,cmpTeacherId,cmpTeacherSubject };