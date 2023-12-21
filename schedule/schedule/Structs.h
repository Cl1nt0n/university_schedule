#include "CircularDoublyLinkedList.h"
#include "iostream"
#include "fstream"
using namespace std;

extern int department_id;
extern int group_id;
extern int lecturer_id;
extern int schedule_id;

//Структура кафедра
struct Department
{
	int id;			// Номер кафедры
	string name;    // название кафедры
	Department* next;
	Department* previous;

	Department(string name)
	{
		this->name = name;
		id = department_id;
		department_id++;
	}
};

//расширение видимости переменных
extern Department* begin_department;
extern Department* end_department;

struct Group
{
	int id;
	int department_id;
	Group* next;
	Group* previous;

	Group(int department_id, int id)
	{
		id = group_id;
		this->department_id = department_id;
		group_id++;
	}
};

//расширение видимости переменных
extern Group* begin_group;
extern Group* end_group;

struct Schedule
{
	int id;
	int department_id;
	int group_id;
	int lecturer_id;
	int class_room_id;
	string subject_name;
	Date date_of_lesson;
	Schedule* next;
	Schedule* previous;

	Schedule(string subject_name, int department_id, int group_id, int lecturer_id, int class_room_id)
	{
		this->subject_name = subject_name;
		this->department_id = department_id;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
		schedule_id++;
	}
};

//расширение видимости переменных
extern Schedule* begin_schedule;
extern Schedule* end_schedule;

struct Lecturer
{
	int id;
	int department_id;
	string name;
	Lecturer* next;
	Lecturer* previous;

	Lecturer(string name, int department_id)
	{
		this->name = name;
		this->department_id = department_id;
		id = lecturer_id;
		lecturer_id++;
	}
};

//расширение видимости переменных
extern Lecturer* begin_lecturer;
extern Lecturer* end_lecturer;

struct Date
{
	int day;
	int month;
	int year;
};

struct ClassRoom
{
	int id;
};
