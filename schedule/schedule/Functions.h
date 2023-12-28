#include "Structs.h"
#include "iomanip"
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

//Элементы для построения таблицы
const char VerticalLine = (char)186;//"║" - ВЕРТИКАЛЬНАЯ ЛИНИЯ
const char HorizontalLine = (char)205;//"═" - ГОРИЗОНТАЛЬНАЯ ЛИНИЯ
const char TopLeftCorner = (char)201;//"╔" - ЛЕВЫЙ ВЕРХНИЙ УГОЛ
const char TopRightCorner = (char)187;//"╗" - ПРАВЫЙ ВЕРХНИЙ УГОЛ
const char BottomLeftCorner = (char)200;//"╚" - ЛЕВЫЙ НИЖНИЙ УГОЛ
const char BottomRightCorner = (char)188;//"╝" - ПРАВЫЙ НИЖНИЙ УГОЛ
const char LeftJunction = (char)185;//"╣" - ПОВОРОТ ВЛЕВО
const char RightJunction = (char)204;//"╠" - ПОВОРОТ ВПРАВО
const char BottomJunction = (char)203;//"╦" - ПОВОРОТ ВНИЗ
const char TopJunction = (char)202;//"╩" - ПОВОРОТ ВВЕРХ
const char CrossJunction = (char)206;//"╬" - ПЕРЕКРЕСТОК
const char Space = (char)32;//Пробел

//************************************************************************
//*                     ПРОТОТИПЫ ФУНКЦИЙ                                *
//************************************************************************

//Функция считывания кафедр из файла
void read_departments(string file_name, //имя файла
	int& error_code, //код ошибки
	Department*& begin_department, 
	Department*& end_department);

//Функция считывания групп из файла
void read_groups(string file_name, //имя файла
	int& error_code, //код ошибки
	Group*& begin_group,
	Group*& end_group,
	Department*& begin_department);

//Функция считывания преподавателей из файла
void read_lecturers(string file_name, //имя файла
	int& error_code,
	Lecturer*& begin_lecturer,
	Lecturer*& end_lecturer,
	Department*& begin_department);//код ошибки

//Функция считывания расписаний из файла
void read_schedules(string file_name, //имя файла
	int& error_code,
	Schedule*& begin_schedule,
	Schedule*& end_schedule,
	Group*& begin_group,
	Lecturer*& begin_lecturer,
	Subject* begin_subject,
	ClassRoom*& begin_class_room);//код ошибки

void read_subjects(string file_name, int& error_code, Subject*& begin_subject, Subject*& end_subject);

void read_class_rooms(string file_name, int& error_code, ClassRoom*& begin_class_room, ClassRoom*& end_class_room);

//Функция проверки полей даты
void check_date_fields(int year_int, //год 
	int& error_code, //код ошибки
	int minute_int, //минута
	int hour_int, //час
	int month_int, //месяц
	int day_int);//день

//Функция проверки файла 
void check_file(string file_name, //название файла
	int& error_code); //код ошибки

//Функция вставки кафедры
void insert_department(string name, //название
	int& error_code, 
	Department*& begin_department, 
	Department*& end_department); //код ошибки

//Функция вставки преподавателя
void insert_lecturer(string name, //имя
	int department_id, //id кафедры
	int& error_code, //код ошибки
	Lecturer*& begin_lecturer, 
	Lecturer*& end_lecturer,
	Department*& begin_department); 

//Функция вставки группы
void insert_group(int department_id, //id кафедры
	int id, //номер группы
	int& error_code, 
	Group*& begin_group, 
	Group*& end_group, 
	Department*& begin_department); //код ошибки

//Функция вставки расписания
void insert_schedule(Subject* subject, //название предмета
	int group_id, //id группы
	int lecturer_id, //id преподавателя
	int class_room_id, //id класса
	int& error_code, //код ошибки
	Date date, 
	Schedule*& begin_schedule,
	Schedule*& end_schedule,
	Group*& begin_group, 
	Lecturer*& begin_lecturer, 
	Subject*& begin_subject,
	ClassRoom*& begin_class_room); //дата

void insert_subject(string name, int& error_code, Subject*& begin_subject, Subject*& end_subject);

void insert_class_room(int id, int& error_code, ClassRoom*& begin_class_room, ClassRoom*& end_class_room);

//Функция поиска кафедры по id
Department* find_department_by_id(int id, Department*& begin_department); //id

//Функция поиска кафедры по имени
Department* find_department_by_name(string name, Department*& begin_department); //название кафедры

Subject* find_subject_by_name(string name, Subject*& begin_subject);

Subject* find_subject_by_id(int subject_id, Subject*& begin_subject);

ClassRoom* find_class_room_by_id(int class_room_id, ClassRoom*& begin_class_room);

//Функция поиска группы по id
Group* find_group_by_id(int id, Group*& begin_group); //id

//Функция поиска групп по id кафедры
Group* find_groups_by_department_id(int department_id, Group*& begin_group); //id кафедры

//Функция поиска преподавателя по id
Lecturer* find_lecturer_by_id(int id, Lecturer*& begin_lecturer); //id

//Функция поиска преподавателей по имени
Lecturer* find_lecturers_by_name(string name, Lecturer*& begin_lecturer); //имя

//Функция поиска преподавателей по id кафедры
Lecturer* find_lecturers_by_department_id(int department_id, Lecturer*& begin_lecturer); //id кафедры

//Функция поиска расписания по id
Schedule* find_schedule_by_id(int id, Schedule*& begin_schedule); //id

//Функция поиска расписания по дате
Schedule* find_schedule_by_date(string hour, //час
	string minute, //минута
	string day, //день
	string month, //месяц
	string year, 
	Schedule*& begin_schedule); //год

//Функция проверки символа на цифру
bool is_digit(char symbol); //символ

//Функция печати кафедр
void print_departments(Department* department); //кафедра

//Функция печати групп
void print_groups(Group* group); //группа

//Функция печати преподавателей
void print_lecturers(Lecturer* lecturer); //преподаватель

//Функция печати расписаний
void print_schedules(Schedule* schedule, Lecturer*& begin_lecturer, Subject* begin_subject); //расписание

void print_subjects(Subject* subject);

void print_class_rooms(ClassRoom* class_room);

//Функция получения id группы рапсиания
int get_schedule_group_id(Schedule* schedule);//расписание

//Функция получения id преподавателя расписания
int get_schedule_lecturer_id(Schedule* schedule);//расписание

//Функция получения id класса расписания
int get_schedule_class_room_id(Schedule* schedule);//расписание

//Функция получения названия предмета расписания
int get_schedule_subject_id(Schedule* schedule);//расписание

//Функция проверки даты
void check_date(string str_date, //параметры даты
	int& error_code, 
	int& hour_int, 
	int& minute_int, 
	int& day_int, 
	int& month_int, 
	int& year_int,
	string& year, 
	string& minute, 
	string& hour, 
	string& month, 
	string& day);

//Функция перезаписи файла с кафедрами
void write_departments(string file_name, Department*& begin_department);//имя файла

//Функция перезаписи файла с группами
void write_groups(string file_name, Group*& begin_group);//имя файла

//Функция перезаписи файла с преподавателями
void write_lecturers(string file_name, Lecturer*& begin_lecturer);//имя файла

//Функция перезаписи файла с рапсианиями
void write_schedules(string file_name, Schedule*& begin_schedule);//имя файла

void write_subjects(string file_name, Subject* begin_subject);

void write_class_rooms(string file_name, ClassRoom* begin_class_room);

//Функция удаления всех расписаний по заданным параметрам
void remove_all_schedules_by_parameter(int parameter, //параметр
	int(*function)(Schedule*), //функция получения параметра расписания
	Schedule*& begin_schedule, 
	Schedule*& end_schedule);

//Функция удаления всех расписаний по id кафедры
void remove_all_lecturers_by_department_id(int department_id, 
	Lecturer*& begin_lecturer, 
	Lecturer*& end_lecturer, 
	Schedule*& begin_schedule, 
	Schedule*& end_schedule);//id кафедры

//Функция удаления всех групп по id кафедры
void remove_all_groups_by_department_id(int department_id, 
	Group*& begin_group, 
	Group*& end_group, 
	Schedule*& begin_schedule, 
	Schedule*& end_schedule);//id кафедры

//Функция очистки списка задданного типа
template<typename T>
void clear_list(T*& start, //начальный элемент
	T*& end)//конечный элемент
{
	//проверка на пустоту списка
	if (start == nullptr)
	{
		cout << "Список пуст." << endl;
		return;
	}
	T* current = start;
	T* previous = end;

	//проверка, имеется ли в списке только один элемент
	if (current == previous)
	{
		delete start;
		start = nullptr;
		end = nullptr;
		return;
	}

	//цикл, пока начальный элемент не удален
	do
	{
		current = start;
		start->previous->next = start->next;
		start->next->previous = start->previous;
		start = start->next;
		if (current == start)
			start = nullptr;
		delete current;
	} while (start != nullptr);
}

//Функция удаления элемента из списка
template<typename T>
void remove_element_from_list(T*& start, //начальный элемент
	T*& end, //конечный элемент
	int id)//id элемента
{
	//проверка на пустоту списка
	if (start == nullptr)
	{
		cout << "Список пуст." << endl;
		return;
	}

	T* current = start;
	T* previous = end;

	//проверка, имеется ли в списке только один элемент
	if (current == previous)
	{
		//проверка, является ли этот элемент искомым
		if (current->id == id)
		{
			delete start;
			start = nullptr;
			end = nullptr;
			cout << "Элемент удален из списка." << endl;
			return;
		}
	}


	//цикл, пока не перебраны все элементы списка 
	do
	{
		//проверка, является ли элемент искомым
		if (current->id == id)
		{
			//проверка, является ли этот элемент начальным
			if (current == start)
			{
				start = current->next;
				end->next = current->next;
				delete current;
				cout << "Элемент удален из списка." << endl;
				current = nullptr;
				return;
			}
			if (current == end)
			{
				end = current->previous;
				end->next = current->next;
				delete current;
				cout << "Элемент удален из списка." << endl;
				current = nullptr;
				return;
			}

			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
			cout << "Элемент удален из списка." << endl;
			return;
		}

		current = current->next;
	} while (current != start || current != nullptr);

	cout << "Элемент не найден." << endl;
}

//Функция нахождения расписания по заданным параметрам
template<typename T>
Schedule* find_schedule_by_parameters(T parameter, //параметр
	T(*function)(Schedule*), Schedule*& begin_schedule, Schedule*& end_schedule)//функция получения поля структуры
{
	//Объявление переменных
	Schedule* schedule = begin_schedule;

	if (schedule == nullptr)
		return nullptr;

	Schedule* temp = new Schedule(schedule->subject_id,
		schedule->id,
		schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
	temp->next = nullptr;
	temp->previous = nullptr;
	Schedule* begin_temp = temp;

	//Цикл, пока не перебраны все элементы списка
	do
	{
		//проверка, является ли элемент искомым
		if (function(schedule) == parameter)
		{
			temp->next = new Schedule(schedule->subject_id,
				schedule->id,
				schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		schedule = schedule->next;
	} while (schedule != begin_schedule);

	//Проверка, если не найден ни один элемент
	if (temp->next == nullptr)
	{
		//Удаление первого элемента нового списка
		delete temp;
		return nullptr;
	}
	//Удаление первого элемента нового списка
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}