#include "Functions.h"

void insert_department(string name, int& error_code)
{
	if (find_department_by_name(name) != nullptr)
	{
		cout << "Кафедра с таким названием уже существует." << endl;
		error_code = 1;
		return;
	}
	Department* department = new Department(name);
	if (begin_department == nullptr)
	{
		begin_department = department;
		end_department = department;
		begin_department->next = department;
		begin_department->previous = department;
	}
	else
	{
		end_department->next = department;
		department->previous = end_department;
		end_department = department;
		department->next = begin_department;
		begin_department->previous = end_department;
	}
	error_code = 0;
}

void insert_group(int department_id, int id, int& error_code)
{
	error_code = 0;
	if (find_department_by_id(department_id) == nullptr)
	{
		error_code = 1;
		cout << "Указанной кафедры не существует." << endl << endl;
		return;
	}
	if (find_group_by_id(id) != nullptr)
	{
		error_code = 2;
		cout << "Группа с таким номером уже существует." << endl << endl;
		return;
	}
	Group* group = new Group(department_id, id);
	if (begin_group == nullptr)
	{
		begin_group = group;
		end_group = group;
		begin_group->next = group;
		begin_group->previous = group;
	}
	else
	{
		end_group->next = group;
		group->previous = end_group;
		end_group = group;
		group->next = begin_group;
		begin_group->previous = end_group;
	}
	error_code = 0;
}

void insert_schedule(string subject_name, int group_id, int lecturer_id, int class_room_id, int& error_code, Date date)
{
	if (find_group_by_id(group_id) == nullptr)
	{
		cout << "Группа не найдена." << endl;
		error_code = 2;
		return;
	}
	if (find_lecturer_by_id(lecturer_id) == nullptr)
	{
		cout << "Преподаватель не найден." << endl;
		error_code = 2;
		return;
	}
	Schedule* schedule = new Schedule(subject_name, group_id, lecturer_id, class_room_id, date);
	if (begin_schedule == nullptr)
	{
		begin_schedule = schedule;
		end_schedule = schedule;
		begin_schedule->next = schedule;
		begin_schedule->previous = schedule;
	}
	else
	{
		end_schedule->next = schedule;
		schedule->previous = end_schedule;
		end_schedule = schedule;
		schedule->next = begin_schedule;
		begin_schedule->previous = end_schedule;
	}
	error_code = 0;
}

void insert_lecturer(string name, int department_id, int& error_code)
{
	if (find_department_by_id(department_id) == nullptr)
	{
		error_code = 2;
		return;
	}
	Lecturer* lecturer = new Lecturer(name, department_id);
	if (begin_lecturer == nullptr)
	{
		begin_lecturer = lecturer;
		end_lecturer = lecturer;
		begin_lecturer->next = lecturer;
		begin_lecturer->previous = lecturer;
	}
	else
	{
		end_lecturer->next = lecturer;
		lecturer->previous = end_lecturer;
		end_lecturer = lecturer;
		lecturer->next = begin_lecturer;
		begin_lecturer->previous = end_lecturer;
	}
	error_code = 0;
}

Department* find_department_by_id(int id)
{
	Department* department = begin_department;

	if (department == nullptr)
		return nullptr;

	do
	{
		if (department->id == id)
			return department;
		
		department = department->next;
	} while (department != begin_department);

	return nullptr;
}

Group* find_group_by_id(int id)
{
	Group* group = begin_group;

	if (group == nullptr)
		return nullptr;

	do
	{
		if (group->id == id)
			return group;
		
		group = group->next;
	} while (group != begin_group);

	return nullptr;
}

Group* find_groups_by_department_id(int department_id)
{
	Group* group = begin_group;
	Group* temp = new Group(group->department_id, group->id);
	temp->next = nullptr;
	temp->previous = nullptr;
	Group* begin_temp = temp;

	while (group != nullptr)
	{
		if (group->department_id == department_id)
		{
			temp->next = new Group(group->department_id, group->id);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		if (group->next == begin_group)
			break;
		group = group->next;
	}
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

Lecturer* find_lecturer_by_id(int id)
{
	Lecturer* lecturer = begin_lecturer;

	if (lecturer == nullptr)
		return nullptr;

	do
	{
		if (lecturer->id == id)
			return lecturer;
		
		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);

	return nullptr;
}

Lecturer* find_lecturers_by_name(string name)
{
	Lecturer* lecturer = begin_lecturer;
	Lecturer* temp = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
	temp->next = nullptr;
	temp->previous = nullptr;
	Lecturer* begin_temp = temp;

	while (lecturer != nullptr)
	{
		if (lecturer->name == name)
		{
			temp->next = new Lecturer(name, lecturer->department_id, lecturer->id);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		if (lecturer->next == begin_lecturer)
			break;
		lecturer = lecturer->next;
	}
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

Lecturer* find_lecturers_by_department_id(int department_id)
{
	Lecturer* lecturer = begin_lecturer;
	Lecturer* temp = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
	temp->next = nullptr;
	temp->previous = nullptr;
	Lecturer* begin_temp = temp;

	while (lecturer != nullptr)
	{
		if (lecturer->department_id == department_id)
		{
			temp->next = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		if (lecturer->next == begin_lecturer)
			break;
		lecturer = lecturer->next;
	}
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

Schedule* find_schedule_by_date(string hour, string minute, string day, string month, string year)
{
	Schedule* schedule = begin_schedule;
	Schedule* temp = new Schedule(schedule->subject_name,
		schedule->id,
		schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
	temp->next = nullptr;
	temp->previous = nullptr;
	Schedule* begin_temp = temp;

	while (schedule != nullptr)
	{
		if (schedule->date_of_lesson.day == day 
			&& schedule->date_of_lesson.hour == hour 
			&& schedule->date_of_lesson.minute == minute 
			&& schedule->date_of_lesson.month == month
			&& schedule->date_of_lesson.year == year)
		{
			temp->next = new Schedule(schedule->subject_name,
				schedule->id,
				schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		if (schedule->next == begin_schedule)
			break;
		schedule = schedule->next;
	}
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

Department* find_department_by_name(string name)
{
	Department* department = begin_department;

	if (department == nullptr)
		return nullptr;
	
	do
	{
		if (department->name == name)
			return department;
		
		department = department->next;
	}while (department != begin_department);

	return nullptr;
}

void read_departments(string file_name, int& error_code)
{
	ifstream stream(file_name);
	string str;

	while (getline(stream, str))
	{
		if (str[0] == '\n')
		{
			error_code = 1;
			return;
		}

		insert_department(str, error_code);
		if (error_code == 1)
			return;
	}
	error_code = 0;
	cout << "Файл с кафедрами - данные считаны." << endl;
}

void read_groups(string file_name, int& error_code)
{
	ifstream stream(file_name);
	string str;

	while (getline(stream, str))
	{
		string number;
		int index = 0;

		while (str[index] == ' ')
			index++;
		while (str[index] != ' ')
		{
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				return;
			}
			number += str[index++];
		}

		int id = atoi(number.c_str());
		number = "";
		while (str[index] == ' ')
			index++;
		while (index < str.size())
		{
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				return;
			}
			number += str[index++];
		}
		int department_id = atoi(number.c_str());

		insert_group(department_id, id, error_code);
		if (error_code == 1 || error_code == 2)
			return;
	}
	error_code = 0;
	cout << "Файл с группами - данные считаны." << endl;
}

bool is_digit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return true;
	return false;
}

void print_departments(Department* department)
{
	Department* start = department;
	if (department == nullptr)
	{
		cout << "Список групп пуст." << endl;
		return;
	}
	do
	{
		cout << "Id кафедры: " << department->id << endl;
		cout << "Название кафедры: " << department->name << endl << endl;
		department = department->next;
	} while (department != begin_department);
}

void print_groups(Group* group)
{
	Group* start = group;
	if (group == nullptr)
	{
		cout << "Список групп пуст." << endl;
		return;
	}
	do
	{
		cout << "Id группы: " << group->id << endl;
		cout << "Id кафедры: " << group->department_id << endl << endl;
		group = group->next;
	} while (group != start);
}

void print_lecturers(Lecturer* lecturer)
{
	Lecturer* start = lecturer;
	if (lecturer == nullptr)
	{
		cout << "Список преподавателей пуст." << endl;
		return;
	}
	do
	{
		cout << "Id преподавателя: " << lecturer->id << endl;
		cout << "Имя преподавателя: " << lecturer->name << endl;
		cout << "Id кафедры: " << lecturer->department_id << endl << endl;
		lecturer = lecturer->next;
	} while (lecturer != start);
}

void print_schedules(Schedule* schedule)
{
	Schedule* start = schedule;
	if (schedule == nullptr)
	{
		cout << "Список расписаний пуст." << endl; 
		return;
	}
	do
	{
		cout << "Id расписания: " << schedule->id << endl;
		cout << "Предмет: " << schedule->subject_name << endl;
		cout << "Id группы: " << schedule->group_id << endl;
		cout << "Имя преподавателя: " << find_lecturer_by_id(schedule->lecturer_id)->name << endl;
		cout << "Id аудитории: " << schedule->class_room_id << endl;
		cout << "Дата проведения: " << schedule->date_of_lesson.hour << ':'
			<< schedule->date_of_lesson.minute << ' '
			<< schedule->date_of_lesson.day << ':'
			<< schedule->date_of_lesson.month << ':'
			<< schedule->date_of_lesson.year << endl << endl;
		schedule = schedule->next;
	} while (schedule != start);
}

int get_schedule_group_id(Schedule* schedule)
{
	return schedule->group_id;
}

int get_schedule_lecturer_id(Schedule* schedule)
{
	return schedule->lecturer_id;
}

int get_schedule_class_room_id(Schedule* schedule)
{
	return schedule->class_room_id;
}

string get_schedule_subject_name(Schedule* schedule)
{
	return schedule->subject_name;
}

void read_lecturers(string file_name, int& error_code)
{
	ifstream stream(file_name);
	string str;

	while (getline(stream, str))
	{
		string full_name;
		int index = 0;

		while (str[index] != ':')
			full_name += str[index++];
		index++;
		string number;
		while (str[index] == ' ')
			index++;
		while (index < str.size())
		{
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				return;
			}
			number += str[index++];
		}
		int department_id = atoi(number.c_str());
		insert_lecturer(full_name, department_id, error_code);
		if (error_code == 1)
			return;
	}
	error_code = 0;
	cout << "Файл с преподавателями - данные считаны." << endl;
}

void read_schedules(string file_name, int& error_code)
{
	ifstream stream(file_name);
	string str;

	while (getline(stream, str))
	{
		string subject;
		int index = 0;

		while (str[index] != ':')
			subject += str[index++];
		index++;
		string group_id;
		while (str[index] == ' ')
			index++;
		while (str[index] != ' ')
		{
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				cout << "Неверные данные в файле. Ошибка." << endl;
				return;
			}
			group_id += str[index++];
		}
		int group_id_int = atoi(group_id.c_str());
		string lecturer_id;
		while (str[index] == ' ')
			index++;
		while (str[index] != ' ')
		{
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				cout << "Неверные данные в файле. Ошибка." << endl;
				return;
			}
			lecturer_id += str[index++];
		}
		int lecturer_id_int = atoi(lecturer_id.c_str());
		string class_room_id;
		while (str[index] == ' ')
			index++;
		while (str[index] != ' ')
		{
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				cout << "Неверные данные в файле. Ошибка." << endl;
				return;
			}
			class_room_id += str[index++];
		}
		int class_room_id_int = atoi(class_room_id.c_str());

		string str_date;
		while (index < str.size())
		{
			str_date += str[index];
			index++;
		}
		int year_int = -1, minute_int = -1, hour_int = -1, month_int = -1, day_int = -1;
		string year = "", minute = "", hour = "", month = "", day = "";
		check_date(str_date, error_code, hour_int, minute_int, day_int, month_int, year_int, year, minute, hour, month, day);
		if (error_code == 1)
			return;

		check_date_fields(year_int, error_code, minute_int, hour_int, month_int, day_int);

		if (error_code == 2)
		{
			cout << "Неверный формат даты." << endl;
			return;
		}
		if (error_code == 1)
		{
			cout << "Неверные данные в файле. Ошибка." << endl;
			return;
		}

		Date date;
		date.hour = hour;
		date.minute = minute;
		date.day = day;
		date.month = month;
		date.year = year;

		insert_schedule(subject, group_id_int, lecturer_id_int, class_room_id_int, error_code, date);
	}
	error_code = 0;
	cout << "Файл с расписаниями - данные считаны." << endl;
}

void check_date_fields(int year_int, int& error_code, int minute_int, int hour_int, int month_int, int day_int)
{
	if (year_int < 0)
		error_code = 2;
	if (!(minute_int >= 0 && hour_int < 60))
		error_code = 2;
	if (!(hour_int >= 0 && hour_int < 24))
		error_code = 2;
	switch (month_int)
	{
	case 1:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	case 2:
		if ((year_int % 4 == 0 && year_int % 100 != 0) || (year_int % 400 == 0))
			if (!(day_int > 0 && day_int <= 29))
				error_code = 2;
			else if (!(day_int > 0 && day_int <= 28))
				error_code = 2;
	case 3:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	case 4:
		if (!(day_int > 0 && day_int <= 30))
			error_code = 2;
		break;
	case 5:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	case 6:
		if (!(day_int > 0 && day_int <= 30))
			error_code = 2;
		break;
	case 7:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	case 8:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	case 9:
		if (!(day_int > 0 && day_int <= 30))
			error_code = 2;
		break;
	case 10:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	case 11:
		if (!(day_int > 0 && day_int <= 30))
			error_code = 2;
		break;
	case 12:
		if (!(day_int > 0 && day_int <= 31))
			error_code = 2;
		break;
	default:
		error_code = 2;
		break;
	}
}

void check_date(string str_date, int& error_code, int& hour_int, int &minute_int, int& day_int, int& month_int, int& year_int,
	string& year, string& minute, string& hour, string& month, string& day)
{
	int index = 0;
	while (str_date[index] == ' ')
		index++;

	while (str_date[index] == ' ')
		index++;
	while (str_date[index] != ':')
	{
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		hour += str_date[index++];
	}
	index++;
	hour_int = atoi(hour.c_str());

	while (str_date[index] == ' ')
		index++;
	while (str_date[index] != ' ')
	{
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		minute += str_date[index++];
	}
	minute_int = atoi(minute.c_str());
	while (str_date[index] == ' ')
		index++;
	while (str_date[index] != ':')
	{
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		day += str_date[index++];
	}
	day_int = atoi(day.c_str());

	while (str_date[index] == ':')
		index++;
	while (str_date[index] != ':')
	{
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		month += str_date[index++];
	}
	index++;
	month_int = atoi(month.c_str());

	while (str_date[index] == ':')
		index++;
	while (index < str_date.size())
	{
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		year += str_date[index++];
	}
	year_int = atoi(year.c_str());
	error_code = 0;
}

void write_departments(string file_name)
{
	fstream str;
	str.open(file_name);
	str.clear();
	Department* department = begin_department;
	if (department == nullptr)
		return;
	do
	{
		str << department->name << endl;
		department = department->next;
	} while (department != begin_department);

	str.close();
}

void write_groups(string file_name)
{
	fstream str;
	str.open(file_name);
	str.clear();
	Group* group = begin_group;
	if (group == nullptr)
		return;
	do
	{
		str << group->id << ' ' << group->department_id << endl;
		group = group->next;
	} while (group != begin_group);

	str.close();
}

void write_lecturers(string file_name)
{
	fstream str;
	str.open(file_name);
	str.clear();
	Lecturer* lecturer = begin_lecturer;
	if (lecturer == nullptr)
		return;
	do
	{
		str << lecturer->name << ": " << lecturer->department_id << endl;
		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);

	str.close();
}

void write_schedules(string file_name)
{
	fstream str;
	str.open(file_name);
	str.clear();
	Schedule* schedule = begin_schedule;
	if (schedule == nullptr)
		return;
	do
	{
		str << schedule->subject_name << ": ";
		str << schedule->group_id << ' ';
		str << schedule->lecturer_id << ' ';
		str << schedule->class_room_id << ' ';
		str << schedule->date_of_lesson.hour << ':';
		str << schedule->date_of_lesson.minute << ' ';
		str << schedule->date_of_lesson.day << ':';
		str << schedule->date_of_lesson.month << ':';
		str	<< schedule->date_of_lesson.year << endl;
		schedule = schedule->next;
	} while (schedule != begin_schedule);

	str.close();
}

void remove_all_schedules_by_lecturer_id(int lecturer_id)
{
	Schedule* removing_schedule = find_schedule_by_parameters(lecturer_id, get_schedule_lecturer_id);
	Schedule* end_removing_schedule = removing_schedule->previous;
	Schedule* current = begin_schedule;

	if (removing_schedule == nullptr)
		return;

	do
	{
		while (current != end_schedule)
		{

		}
	} while (removing_schedule != end_removing_schedule);
}

void check_file(string file_name, int& error_code)
{
	fstream fin(file_name);
	if (!fin.is_open()) //проверка на существование
	{
		cout << "ОШИБКА!!! Файл " << file_name << " не найден!" << endl;
		error_code = 1;
		fin.close();
		return;
	}
	if (fin.peek() == EOF) // проверка на содержание (пустоту)
	{
		cout << "ОШИБКА!!! Файл " << file_name << " пуст!" << endl;
		error_code = 1;
		fin.close();
		return;
	}
	fin.close();
	error_code = 0;
}

