#include<stdio.h>
#include <stdlib.h>
#include<iostream>


struct a1_course
{
	const char* courseName;
	double avarage;
	unsigned int numberOfStudents;
};

	struct a1_student
{
	const char* p_name;
	int studentID;
	a1_course* p_course;
};
	

struct a1_studentIn
{
	const char* name;
	unsigned int id;
	const char* courseName;
};



struct a1_course* findCourse(struct a1_course* courses, int numCourses, const char* courseName) {
	for (int i = 0; i < numCourses; i++) {
		if (strcmp(courses[i].courseName, courseName )==0) {
			return &courses[i];
		}
	}
	return NULL; // Course not found
}
//part 2

struct registar {
	a1_course* courses;
	unsigned int numCourses;
	a1_student* students;
	unsigned int numStudents;
};

unsigned int numResgisteredStudents(a1_student* students, unsigned int numStudents, a1_course* course) {
	unsigned int courseCount =0;
	for (int i = 0; i < numStudents; i++) {
		if (students[i].p_course == course) {
			courseCount++;
		}
		
	}

	return courseCount;
} 

void printRegistrar(registar reg) {
	printf("\nbelow these are the students\n");
	for (int i = 0; i < reg.numStudents; i++) {
		printf("%s %i taking ", reg.students[i].p_name,
			reg.students[i].studentID);
		a1_course& course = *reg.students[i].p_course;
		printf("Course name %s number of students: %i,  course average: %f   \n",
			course.courseName, course.numberOfStudents, course.avarage);
	}
	printf("\nbelow these are the courses\n");
	for (int i = 0; i < reg.numCourses; i++) {
		a1_course& course = reg.courses[i];
		printf("Course name %s number of students: %i,  course average: %f   \n",
			course.courseName, course.numberOfStudents, course.avarage);
	}
	
}

int main() {
	int numStudents = 3;
	struct a1_student* studentsArray = (struct a1_student*)malloc(numStudents * sizeof(struct a1_student));

	a1_studentIn Students[3] =
	{{"kofo Oladipupo", 12345, "BIT2400"},
	{"Joe Smith", 54321, "BIT2400"},
	{"Brian Brown", 11111, "BIT1400"} };
	
	a1_course courses[4] = { {"BIT2400", 71.0, 90},
	{"BIT1400", 52.7, 140},
	{"ITEC2100", 85.3, 15},
	{"BIT2000", 85.3, 15} };

	/*a1_student students[3] =
	{ {"kofo oladipupo", 101226, &courses[1]},
	{"kelly rose", 101227, &courses[2]},
	{"Billy brown", 101228, &courses[3] } };
	*/

	for (int i = 0; i < numStudents; i++) {
		studentsArray[i].p_name = Students[i].name;
		studentsArray[i].studentID = Students[i].id;
		studentsArray[i].p_course = findCourse(courses, 4, Students[i].courseName);
	}

	if (studentsArray == NULL) {
		printf("Memory allocation failed.\n");
		return 1; 
	}

	a1_course &course = *findCourse(courses, 4, "ITEC2100");
	printf("%s was found\n", course.courseName);

	//part 2
	registar reg;
	reg.courses = courses;
	reg.students = studentsArray;
	reg.numCourses = 4;
	reg.numStudents = numStudents;
	printRegistrar(reg);
	courses[1].numberOfStudents = 80;
	printRegistrar(reg);
	free(studentsArray);

	return 0;

}