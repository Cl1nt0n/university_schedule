#include "CircularDoublyLinkedList.h"
#include "fstream"
#include "iostream"
#include "string"
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
		department_id++;
		id = department_id;
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
		this->id = id;
		this->department_id = department_id;
	}
};

//расширение видимости переменных
extern Group* begin_group;
extern Group* end_group;

struct Date
{
	string hour;
	string minute;
	string day;
	string month;
	string year;
};

struct Schedule
{
	int id;
	int group_id;
	int lecturer_id;
	int class_room_id;
	string subject_name;
	Date date_of_lesson;
	Schedule* next;
	Schedule* previous;

	Schedule(string subject_name, int group_id, int lecturer_id, int class_room_id, Date date)
	{
		date_of_lesson = date;
		this->subject_name = subject_name;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
		schedule_id++;
		id = schedule_id;
	}

	Schedule(string subject_name, int id, int group_id, int lecturer_id, int class_room_id, Date date)
	{
		date_of_lesson = date;
		this->subject_name = subject_name;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
		this->id = id;
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
		lecturer_id++;
		id = lecturer_id;
	}
};

//расширение видимости переменных
extern Lecturer* begin_lecturer;
extern Lecturer* end_lecturer;

