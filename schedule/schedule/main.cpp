#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

int department_id = 0;
int schedule_id = 0;
int lecturer_id = 0;
int class_room_id = 0;

using namespace std;

Department* begin_department;
Department* end_department;

Group* begin_group;
Group* end_group;

Schedule* begin_schedule;
Schedule* end_schedule;

Lecturer* begin_lecturer;
Lecturer* end_lecturer;

void print_menu()
{
	cout << "Выберите действие:" << endl;
	cout << "1 - Вывод информации о кафедрах." << endl;
	cout << "2 - Вывод информации о группах." << endl;
	cout << "3 - Вывод информации о преподавателях." << endl;
	cout << "4 - Вывод информации о расписании." << endl;
	cout << "5 - Вывод расписания по номеру аудитории." << endl;
	cout << "6 - Вывод расписания по id преподавателя." << endl;
	cout << "7 - Вывод расписания по номеру группы." << endl;
	cout << "8 - Вывод расписания по предмету." << endl;
}

typedef int (*get_int)(Schedule* schedule);
get_int int_functions[3] = { get_schedule_group_id, get_schedule_lecturer_id, get_schedule_class_room_id };

typedef string (*get_string)(Schedule* schedule);
get_string string_functions[1] = { get_schedule_subject_name};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int error_code = 0;
	int error_code1 = 0;
	int error_code2 = 0;
	int error_code3 = 0;

	check_file("Departments.txt", error_code);
	check_file("Groups.txt", error_code1);
	check_file("Lecturers.txt", error_code2);
	check_file("Schedules.txt", error_code3);

	if (error_code != 0 || error_code1 != 0 || error_code2 != 0 || error_code3 != 0)
		return 0;
	else
		cout << "Файлы прошли проверку." << endl;

	error_code = 0;
	error_code1 = 0;
	error_code2 = 0;
	error_code3 = 0;

	read_departments("Departments.txt", error_code);
	read_groups("Groups.txt", error_code1);
	read_lecturers("Lecturers.txt", error_code2);
	read_schedules("Schedules.txt", error_code3);
	if (error_code != 0 || error_code1 != 0 || error_code2 != 0 || error_code3 != 0)
		return 0;
	else
		cout << "Все данные успешно считаны." << endl << endl;

	print_menu();
	int command;

	while (!(cin >> command))
	{
		cout << "Ошибка. Вводимое значение должно быть числом." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	while (command != 0)
	{
		switch (command)
		{
		case 1:
			print_departments();
			break;
		case 2:
			print_groups();
			break;
		case 3:
			print_lecturers();
			break;
		case 4:
			print_schedules(begin_schedule);
			break;
		case 5:
			int class_room_id;
			cout << "Введите номер аудитории." << endl;
			while (!(cin >> class_room_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			print_schedules(find_schedule_parameters_id(class_room_id, int_functions[2]));
			break;
		case 6:
			int lecturer_id;
			cout << "Введите id преподавателя." << endl;
			while (!(cin >> lecturer_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			print_schedules(find_schedule_parameters_id(lecturer_id, int_functions[1]));
			break;
		case 7:
			int group_id;
			cout << "Введите номер группы." << endl;
			while (!(cin >> group_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			print_schedules(find_schedule_parameters_id(group_id, int_functions[0]));
			break;
		case 8:
			int group_id;
			cout << "Введите номер группы." << endl;
			while (!(cin >> group_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			print_schedules(find_schedule_parameters_id(group_id, string_functions[0]));
			break;
		default:
			break;
		}

		cout << endl;
		print_menu();
		while (!(cin >> command))
		{
			cout << "Ошибка. Вводимое значение должно быть числом." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}
