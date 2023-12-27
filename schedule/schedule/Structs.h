/*************************************************************************
*                                                                        *
*           КУРСОВАЯ РАБОТА по дисциплине ПРОГРАММИРОВАНИЕ               *
*                                                                        *
**************************************************************************
*Project type : Visual Studio Solution                                   *
*Project name : Курсач                                                   *
*File name    : main.cpp                                                 *
*Language     : CPP, MSVS 2022                                           *
*Programmer   : Чиняков Игорь Павлович, М3О-210Б-22                      *
*Modified by  :                                                          *
*Created      : 20.12.2023                                               *
*Last revision: 26.12.2023                                               *
*Comment      : Списочные базы данных    					             *
*************************************************************************/
#include "fstream"
#include "iostream"
#include "string"
using namespace std;

extern int department_id;
extern int group_id;
extern int lecturer_id;
extern int schedule_id;

//************************************************************************
//*                           СТРУКТУРЫ                                  *
//************************************************************************
//Структура кафедра
struct Department
{
	int id;			// Номер кафедры
	string name;    // название кафедры
	Department* next;//указатель на следующую кафедру
	Department* previous;//указатель на предыдущую кафедру

	//конструтктор
	Department(string name)
	{
		this->name = name;
		department_id++;
		id = department_id;
	}
};

//Структура группа
struct Group
{
	int id;//номер группы
	int department_id;//id кафедры
	Group* next;//указатель на слудующую группу
	Group* previous;//указатель на предыдущую группу

	//конструктор
	Group(int department_id, int id)
	{
		this->id = id;
		this->department_id = department_id;
	}
};

//струтктура дата
struct Date
{
	string hour;//час
	string minute;//минута
	string day;//день
	string month;//месяц
	string year;//год
};

//структура расписание
struct Schedule
{
	int id;//id расписания
	int group_id;//номер группы
	int lecturer_id;//id преподавателя
	int class_room_id;//номер аудитории
	string subject_name;//название предмета
	Date date_of_lesson;//дата проведения
	Schedule* next;//указатель на следующее расписание
	Schedule* previous;//указатель на предыдущее расписание

	//конструктор
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

	//конструктор
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

//структура преподавателя
struct Lecturer
{
	int id;//id лектора
	int department_id;//id кафедры
	string name;//имя преподавателя
	Lecturer* next;
	Lecturer* previous;

	//конструктор
	Lecturer(string name, int department_id)
	{
		this->name = name;
		this->department_id = department_id;
		lecturer_id++;
		id = lecturer_id;
	}

	//конструктор
	Lecturer(string name, int department_id, int id)
	{
		this->name = name;
		this->department_id = department_id;
		this->id = id;
	}
};

//struct Subject
//{
//	int id;
//	string name;
//	Subject* next;
//	Subject* previous;
//
//	Subject(string name)
//	{
//		this->name = name;
//		subject_id++;
//		id = subject_id;
//	}
//};

