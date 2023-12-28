﻿/*************************************************************************
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

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Functions.h"

using namespace std;

//начальные и конечный элменты списков
Department* b_department = nullptr;
Department* e_department = nullptr;

Group* b_group = nullptr;
Group* e_group = nullptr;

Schedule* b_schedule = nullptr;
Schedule* e_schedule = nullptr;

Lecturer* b_lecturer = nullptr;
Lecturer* e_lecturer = nullptr;

Subject* b_subject = nullptr;
Subject* e_subject = nullptr;

ClassRoom* b_class_room = nullptr;
ClassRoom* e_class_room = nullptr;

//файлы с данными
const string departments_file = "Departments.txt";
const string groups_file = "Groups.txt";
const string lecturers_file = "Lecturers.txt";
const string schedules_file = "Schedules.txt";
const string subjects_file = "Subjects.txt";
const string class_rooms_file = "ClassRooms.txt";

//печать меню
void print_menu()
{
	cout << "Выберите действие:" << endl;
	cout << "1  - Вывод информации о кафедрах." << endl;
	cout << "2  - Вывод информации о группах." << endl;
	cout << "3  - Вывод информации о преподавателях." << endl;
	cout << "4  - Вывод информации о расписании." << endl;
	cout << "5  - Вывод информации о предметах." << endl;
	cout << "6  - Вывод информации о предметах." << endl;
	cout << "7  - Поиск расписания по номеру аудитории." << endl;
	cout << "8  - Поиск расписания по id преподавателя." << endl;
	cout << "9  - Поиск расписания по номеру группы." << endl;
	cout << "10  - Поиск расписания по предмету." << endl;
	cout << "11 - Поиск расписания по дате." << endl;
	cout << "12 - Вставка новой кафедры." << endl;
	cout << "13 - Вставка новой группы." << endl;
	cout << "14 - Вставка нового расписания." << endl;
	cout << "15 - Вставка нового преподавателя." << endl;
	cout << "16 - Вставка нового предмета." << endl;
	cout << "17 - Вставка новой аудитории." << endl;
	cout << "18 - Удаление кафедры." << endl;
	cout << "19 - Удаление группы." << endl;
	cout << "20 - Удаление преподавателя." << endl;
	cout << "21 - Удаление расписания." << endl;
	cout << "22 - Удаление предмета." << endl;
	cout << "23 - Удаление аудитории." << endl;
	cout << "24 - Поиск преподавателей по имени." << endl;
	cout << "25 - Поиск преподавателей по id кафедры." << endl;
	cout << "26 - Поиск групп по id кафедры." << endl;
	cout << "0  - Выход из программы. Сохранение изменений." << endl;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	int error_code = 0;
	int error_code1 = 0;
	int error_code2 = 0;
	int error_code3 = 0;
	int error_code4 = 0;
	int error_code5 = 0;
	int class_room_id;
	int group_id;
	int department_id;
	int lecturer_id;
	int schedule_id;
	int subject_id;
	int year_int = -1, minute_int = -1, hour_int = -1, month_int = -1, day_int = -1;
	string subject_name;
	string str_date;
	string department_name;
	string lecturer_name;
	string year = "", minute = "", hour = "", month = "", day = "";
	Date date;
	Schedule* schedule = nullptr;
	Lecturer* lecturer = nullptr;
	Group* group = nullptr;
	Department* department = nullptr;
	Subject* subject = nullptr;

	check_file(departments_file, error_code);
	check_file(groups_file, error_code1);
	check_file(lecturers_file, error_code2);
	check_file(subjects_file, error_code4);
	check_file(class_rooms_file, error_code5);
	check_file(schedules_file, error_code3);

	if (error_code != 0 || error_code1 != 0 || error_code2 != 0 || error_code3 != 0 || error_code4 != 0 || error_code5 != 0)
		return 0;
	else
		cout << "Файлы прошли проверку." << endl;

	read_departments(departments_file, error_code, b_department, e_department);
	read_groups(groups_file, error_code1, b_group, e_group, b_department);
	read_lecturers(lecturers_file, error_code2, b_lecturer, e_lecturer, b_department);
	read_subjects(subjects_file, error_code4, b_subject, e_subject);
	read_class_rooms(class_rooms_file, error_code5, b_class_room, e_class_room);
	read_schedules(schedules_file, error_code3, b_schedule, e_schedule, b_group, b_lecturer, b_subject, b_class_room);

	if (error_code != 0 || error_code1 != 0 || error_code2 != 0 || error_code3 != 0 || error_code4 != 0 || error_code5 != 0)
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
			print_departments(b_department);
			break;
		case 2:
			print_groups(b_group);
			break;
		case 3:
			print_lecturers(b_lecturer);
			break;
		case 4:
			print_schedules(b_schedule, b_lecturer, b_subject);
			break;
		case 5:
			print_subjects(b_subject);
			break;
		case 6:
			print_class_rooms(b_class_room);
			break;
		case 7:
			cout << "Введите номер аудитории:" << endl;
			while (!(cin >> class_room_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			schedule = find_schedule_by_parameters(class_room_id, get_schedule_class_room_id, b_schedule, e_schedule);
			print_schedules(schedule, b_lecturer, b_subject);
			clear_list(schedule, schedule->previous);
			print_schedules(schedule, b_lecturer, b_subject);
			break;
		case 8:
			cout << "Введите id преподавателя:" << endl;
			while (!(cin >> lecturer_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			schedule = find_schedule_by_parameters(lecturer_id, get_schedule_lecturer_id, b_schedule, e_schedule);
			print_schedules(schedule, b_lecturer, b_subject);
			clear_list(schedule, schedule->previous);
			print_schedules(schedule, b_lecturer, b_subject);
			break;
		case 9:
			cout << "Введите номер группы:" << endl;
			while (!(cin >> group_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			schedule = find_schedule_by_parameters(group_id, get_schedule_group_id, b_schedule, e_schedule);
			print_schedules(schedule, b_lecturer, b_subject);
			clear_list(schedule, schedule->previous);
			print_schedules(schedule, b_lecturer, b_subject);
			break;
		case 10:
			cout << "Введите название предмета:" << endl;
			getchar();
			getline(cin, subject_name);
			subject = find_subject_by_name(subject_name, b_subject);
			if (subject == nullptr)
			{
				cout << "Предмет не найден." << endl;
				break;
			}
			schedule = find_schedule_by_parameters(subject->id, get_schedule_subject_id, b_schedule, e_schedule);
			print_schedules(schedule, b_lecturer, b_subject);
			clear_list(schedule, schedule->previous);
			print_schedules(schedule, b_lecturer, b_subject);
			break;
		case 11:
			error_code = 0;
			cout << "Введите дату в формате hh:mm dd:mm:yyyy:" << endl;
			getchar();
			getline(cin, str_date);
			check_date(str_date, error_code, hour_int, minute_int, day_int, month_int, year_int, year, minute, hour, month, day);
			if (error_code != 0)
			{
				cout << "Ошибка при считывании даты." << endl;
				break;
			}
			check_date_fields(year_int, error_code, minute_int, hour_int, month_int, day_int);
			if (error_code != 0)
			{
				cout << "Ошибка в формате даты." << endl;
				break;
			}
			schedule = find_schedule_by_date(hour, minute, day, month, year, b_schedule);
			print_schedules(schedule, b_lecturer, b_subject);
			clear_list(schedule, schedule->previous);
			print_schedules(schedule, b_lecturer, b_subject);
			break;
		case 12:
			error_code = 0;
			cout << "Введите название кафедры." << endl;
			getchar();
			getline(cin, department_name);

			insert_department(department_name, error_code, b_department, e_department);
			if (error_code != 0)
				cout << "Ошибка при добавлении кафедры." << endl;
			else
				cout << "Добавление произведено успешно." << endl;
			break;
		case 13:
			error_code = 0;
			cout << "Введите номер группы:" << endl;
			while (!(cin >> group_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Введите номер кафедры:" << endl;
			while (!(cin >> department_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			insert_group(department_id, group_id, error_code, b_group, e_group, b_department);
			if (error_code != 0)
				cout << "Ошибка при добавлении группы." << endl;
			else
				cout << "Добавление призведено успешно." << endl;
			break;
		case 14:
			error_code = 0;
			cout << "Введите название предмета:" << endl;
			getchar();
			getline(cin, subject_name);
			cout << "Введите номер группы:" << endl;
			while (!(cin >> group_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Введите id преподавателя:" << endl;
			while (!(cin >> lecturer_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Введите номер аудитории:" << endl;
			while (!(cin >> class_room_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cout << "Введите дату в формате hh:mm dd:mm:yyyy:" << endl;
			getchar();
			getline(cin, str_date);
			check_date(str_date, error_code, hour_int, minute_int, day_int, month_int, year_int, year, minute, hour, month, day);
			if (error_code != 0)
			{
				cout << "Ошибка при считывании даты." << endl;
				break;
			}
			check_date_fields(year_int, error_code, minute_int, hour_int, month_int, day_int);
			if (error_code != 0)
			{
				cout << "Ошибка в формате даты." << endl;
				break;
			}

			date.hour = hour;
			date.minute = minute;
			date.day = day;
			date.month = month;
			date.year = year;

			insert_schedule(find_subject_by_name(subject_name, b_subject), group_id, lecturer_id, class_room_id, error_code, date, b_schedule, e_schedule, b_group, b_lecturer, b_subject, b_class_room);
			if (error_code != 0)
				cout << "Ошибка при добавлении расписания." << endl;
			else
				cout << "Добавление произведено успешно." << endl;
			break;
		case 15:
			error_code = 0;
			cout << "Введите имя преподавателя:" << endl;
			getchar();
			getline(cin, lecturer_name);
			cout << "Введите номер кафедры:" << endl;
			while (!(cin >> department_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			insert_lecturer(lecturer_name, department_id, error_code, b_lecturer, e_lecturer, b_department);
			if (error_code != 0)
				cout << "Ошибка при добавлении преподавателя." << endl;
			else
				cout << "Добавление произведено успешно." << endl;
			break;
		case 16:
			error_code = 0;
			cout << "Введите название предмета:" << endl;
			getchar();
			getline(cin, subject_name);
			
			insert_subject(subject_name, error_code, b_subject, e_subject);
			if (error_code != 0)
				cout << "Ошибка при добавлении предмета." << endl;
			else
				cout << "Добавление произведено успешно." << endl;
			break;
		case 17:
			error_code = 0;
			cout << "Введите номер аудитории:" << endl;
			while (!(cin >> class_room_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			insert_class_room(class_room_id, error_code, b_class_room, e_class_room);
			if (error_code != 0)
				cout << "Ошибка при добавлении аудитории." << endl;
			else
				cout << "Добавление произведено успешно." << endl;
			break;
			break;
		case 18:
			cout << "Введите id кафедры:" << endl;
			while (!(cin >> department_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			department = find_department_by_id(department_id, b_department);
			if (department == nullptr)
			{
				cout << "Кафедра не найдена." << endl;
				break;
			}

			remove_all_groups_by_department_id(department_id, b_group, e_group, b_schedule, e_schedule);
			remove_all_lecturers_by_department_id(department_id, b_lecturer, e_lecturer, b_schedule, e_schedule);
			remove_element_from_list(b_department, e_department, department_id);
			break;
		case 19:
			cout << "Введите номер группы:" << endl;
			while (!(cin >> group_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			group = find_group_by_id(group_id, b_group);
			if (group == nullptr)
			{
				cout << "Группа не найдена." << endl;
				break;
			}
			remove_all_schedules_by_parameter(group_id, get_schedule_group_id, b_schedule, e_schedule);
			remove_element_from_list(b_group, e_group, group_id);
			break;
		case 20:
			cout << "Введите id преподавателя:" << endl;
			while (!(cin >> lecturer_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			lecturer = find_lecturer_by_id(lecturer_id, b_lecturer);
			if (lecturer == nullptr)
			{
				cout << "Преподаватель не найден." << endl;
				break;
			}
			remove_all_schedules_by_parameter(lecturer_id, get_schedule_lecturer_id, b_schedule, e_schedule);
			remove_element_from_list(b_lecturer, e_lecturer, lecturer_id);
			break;
		case 21:
			cout << "Введите id расписания:" << endl;
			while (!(cin >> schedule_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			remove_element_from_list(b_schedule, e_schedule, schedule_id);
			break;
		case 22:
			cout << "Введите id предмета:" << endl;
			while (!(cin >> subject_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			if (find_subject_by_id(subject_id, b_subject) == nullptr)
			{
				cout << "Предмет не найден." << endl; 
				break;
			}

			remove_all_schedules_by_parameter(subject_id, get_schedule_subject_id, b_schedule, e_schedule);
			remove_element_from_list(b_subject, e_subject, subject_id);
			break;
		case 23:
			cout << "Введите номер аудитории:" << endl;
			while (!(cin >> class_room_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			if (find_class_room_by_id(class_room_id, b_class_room) == nullptr)
			{
				cout << "Аудитория не найдена." << endl;
				break;
			}

			remove_all_schedules_by_parameter(class_room_id, get_schedule_class_room_id, b_schedule, e_schedule);
			remove_element_from_list(b_class_room, e_class_room, class_room_id);
			break;
		case 24:
			cout << "Введите имя преподавателя:" << endl;
			getchar();
			getline(cin, lecturer_name);
			lecturer = find_lecturers_by_name(lecturer_name, b_lecturer);
			print_lecturers(lecturer);
			clear_list(lecturer, lecturer->previous);
			break;
		case 25:
			cout << "Введите id кафедры:" << endl;
			while (!(cin >> department_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			lecturer = find_lecturers_by_department_id(department_id, b_lecturer);
			print_lecturers(lecturer);
			clear_list(lecturer, lecturer->previous);
			break;
		case 26:
			cout << "Введите id кафедры:" << endl;
			while (!(cin >> department_id))
			{
				cout << "Ошибка. Вводимое значение должно быть числом." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			group = find_groups_by_department_id(department_id, b_group);
			print_groups(group);
			clear_list(group, group->previous);
			break;
		default:
			cout << "Неизвестная команада." << endl;
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

	write_departments(departments_file, b_department);
	write_groups(groups_file, b_group);
	write_lecturers(lecturers_file, b_lecturer);
	write_schedules(schedules_file, b_schedule);
	write_subjects(subjects_file, b_subject);
	write_class_rooms(class_rooms_file, b_class_room);

	system("pause");
	return 0;
}