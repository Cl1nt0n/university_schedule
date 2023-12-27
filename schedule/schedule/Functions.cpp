#include "Functions.h"
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

//Функция вставки кафедры
void insert_department(string name, int& error_code, Department*& begin_department, Department*& end_department)
{
	//проверка на уникальность названия кафедры
	if (find_department_by_name(name, begin_department) != nullptr)
	{
		cout << "Кафедра с таким названием уже существует." << endl;
		error_code = 1;
		return;
	}
	//создание новой кафедры
	Department* department = new Department(name);
	//добавление
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

//Вставка новой группы
void insert_group(int department_id, int id, int& error_code, Group*& begin_group, Group*& end_group, Department*& begin_department)
{
	error_code = 0;
	//Проверка на существование кафедры, к которой привязана группа
	if (find_department_by_id(department_id, begin_department) == nullptr)
	{
		error_code = 1;
		cout << "Указанной кафедры не существует." << endl << endl;
		return;
	}
	//проверка на уникальность номера группы
	if (find_group_by_id(id, begin_group) != nullptr)
	{
		error_code = 2;
		cout << "Группа с таким номером уже существует." << endl << endl;
		return;
	}
	//создание новой группы
	Group* group = new Group(department_id, id);
	//добавление
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

//Функция вставки нового расписания
void insert_schedule(string subject_name, int group_id, int lecturer_id, int class_room_id, int& error_code, Date date, Schedule*& begin_schedule, 
	Schedule*& end_schedule, Group*& begin_group, Lecturer*& begin_lecturer)
{
	//Проверка существования группы с указанным номером
	if (find_group_by_id(group_id, begin_group) == nullptr)
	{
		cout << "Группа не найдена." << endl;
		error_code = 2;
		return;
	}
	//Проверка существования преподавателя с указанным номером
	if (find_lecturer_by_id(lecturer_id, begin_lecturer) == nullptr)
	{
		cout << "Преподаватель не найден." << endl;
		error_code = 2;
		return;
	}
	//Создание нового расписания
	Schedule* schedule = new Schedule(subject_name, group_id, lecturer_id, class_room_id, date);
	//добавление
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

//Функция вставки нового преподавателя
void insert_lecturer(string name, int department_id, int& error_code, Lecturer*& begin_lecturer, Lecturer*& end_lecturer, Department*& begin_department)
{
	//Проверка существования кафедры с указанным id
	if (find_department_by_id(department_id, begin_department) == nullptr)
	{
		error_code = 2;
		return;
	}
	//создание нового преподавателя
	Lecturer* lecturer = new Lecturer(name, department_id);
	//добавление
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

//Функция поиск кафедры по id
Department* find_department_by_id(int id, Department*& begin_department)
{
	//создание указателя на начальный элемент
	Department* department = begin_department;

	//Проверка на пустоту списка
	if (department == nullptr)
		return nullptr;

	//цикл поиска
	do
	{
		//сравнение id кафедры с искомым id
		if (department->id == id)
			return department;

		department = department->next;
	} while (department != begin_department);

	return nullptr;
}

//Функция поиска группы по id
Group* find_group_by_id(int id, Group*& begin_group)
{
	//создание указателя на начальный элемент
	Group* group = begin_group;

	//Проверка на пустоту списка
	if (group == nullptr)
		return nullptr;

	//цикл поиска
	do
	{
		//сравнение id кафедры с искомым id
		if (group->id == id)
			return group;

		group = group->next;
	} while (group != begin_group);

	return nullptr;
}

//Функция поиска групп по номеру кафедры
Group* find_groups_by_department_id(int department_id, Group*& begin_group)
{
	//Создание указателя на начальный элемент
	Group* group = begin_group;

	//проверка на пустоту списка
	if (group == nullptr)
		return nullptr;

	//Создание нового списка, который будет хранить только искомые элементы
	Group* temp = new Group(group->department_id, group->id);
	temp->next = nullptr;
	temp->previous = nullptr;
	Group* begin_temp = temp;

	//цикл поиска
	do
	{
		//Сравнение текущих данных с входными
		if (group->department_id == department_id)
		{
			temp->next = new Group(group->department_id, group->id);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		group = group->next;
	} while (group != begin_group);

	//Если список искомых элементов пуст
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}

	//Удаление первого элемента списка
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

//Функция поиска преподавателя по id
Lecturer* find_lecturer_by_id(int id, Lecturer*& begin_lecturer)
{
	//Создание указателя на начальный элемент
	Lecturer* lecturer = begin_lecturer;

	//Проверка на пустоту списка
	if (lecturer == nullptr)
		return nullptr;

	//цикл поиска
	do
	{
		if (lecturer->id == id)
			return lecturer;

		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);

	return nullptr;
}

//Функция поиска расписания по id
Schedule* find_schedule_by_id(int id, Schedule*& begin_schedule)
{
	//Создание указателя на начальный элемент
	Schedule* schedule = begin_schedule;

	//проверка на пустоту
	if (schedule == nullptr)
		return nullptr;

	//цикл поиска
	do
	{
		if (schedule->id == id)
			return schedule;

		schedule = schedule->next;
	} while (schedule != begin_schedule);

	return nullptr;
}

//Функция поиска преподавателей по имени
Lecturer* find_lecturers_by_name(string name, Lecturer*& begin_lecturer)
{
	//Создание указателя на начальный элемент
	Lecturer* lecturer = begin_lecturer;

	//проверка на пустоту списка
	if (lecturer == nullptr)
		return nullptr;

	//создание нового списка искомых элементов
	Lecturer* temp = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
	temp->next = nullptr;
	temp->previous = nullptr;
	Lecturer* begin_temp = temp;

	//цикл поиска
	do
	{
		//Сравнение имени текущего элемента с входными данными
		if (lecturer->name == name)
		{
			temp->next = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);

	//Если не один элемент не найден
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}

	//Удаление первого элемента
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

//Функция поиска преподавателей по id 
Lecturer* find_lecturers_by_department_id(int department_id, Lecturer*& begin_lecturer)
{
	//Создание указателя на первый элемент
	Lecturer* lecturer = begin_lecturer;

	//проверка на пустоту
	if (lecturer == nullptr)
		return nullptr;

	//Создание нового списка искомых элементов
	Lecturer* temp = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
	temp->next = nullptr;
	temp->previous = nullptr;
	Lecturer* begin_temp = temp;

	//цикл поиска
	do
	{
		//сравнение id кафедры теекущего элемента с входными данными
		if (lecturer->department_id == department_id)
		{
			temp->next = new Lecturer(lecturer->name, lecturer->department_id, lecturer->id);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);

	//если ни один элемент не найден
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}

	//Удаление первого элемента
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

//Функция поиска расписания по дате
Schedule* find_schedule_by_date(string hour, string minute, string day, string month, string year, Schedule*& begin_schedule)
{
	//указатель на первый элемент
	Schedule* schedule = begin_schedule;

	//проверка на пустоту списка
	if (schedule == nullptr)
		return nullptr;

	//создание нового списка с искомыми элементами
	Schedule* temp = new Schedule(schedule->subject_name,
		schedule->id,
		schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
	temp->next = nullptr;
	temp->previous = nullptr;
	Schedule* begin_temp = temp;

	//цикл поиска
	do
	{
		//сравнение даты текущего элемента с входными данными
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
		schedule = schedule->next;
	} while (schedule != begin_schedule);

	//если ни один элемент не найден
	if (temp->next == nullptr)
	{
		delete temp;
		return nullptr;
	}

	//удаление первого элемента
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}

//Функция поиска кафедры по имени
Department* find_department_by_name(string name, Department*& begin_department)
{
	//создание уаказателя на первый элемент
	Department* department = begin_department;

	//проверка на пустоту
	if (department == nullptr)
		return nullptr;

	//цикл поиска
	do
	{
		if (department->name == name)
			return department;

		department = department->next;
	} while (department != begin_department);

	return nullptr;
}

//Функция считывания кафедр из файла
void read_departments(string file_name, int& error_code, Department*& begin_department, Department*& end_department)
{
	//открытие файла
	ifstream stream(file_name);
	string str;

	//построчное считывание
	while (getline(stream, str))
	{
		//проверяем каждый символ на конец строки
		if (str[0] == '\n')
		{
			error_code = 1;
			return;
		}

		//Вставка кафедры
		insert_department(str, error_code, begin_department, end_department);
		//проверка на успешность вставки
		if (error_code == 1)
			return;
	}
	error_code = 0;
	cout << "Файл с кафедрами - данные считаны." << endl;
}

//Функция считывания групп из файла
void read_groups(string file_name, int& error_code, Group*& begin_group, Group*& end_group, Department*& begin_department)
{
	//открытие файла
	ifstream stream(file_name);
	string str;

	//Построчное считывание
	while (getline(stream, str))
	{
		string number;
		int index = 0;

		//считывание и проверка каждого символа
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
		//считывание и проверка каждого символа
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

		//вставка группы
		insert_group(department_id, id, error_code, begin_group, end_group, begin_department);
		//проверка кода ошибки
		if (error_code == 1 || error_code == 2)
			return;
	}
	error_code = 0;
	cout << "Файл с группами - данные считаны." << endl;
}

//Функция проверки символа на цифру
bool is_digit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return true;
	return false;
}

//Функция печати кафедр
void print_departments(Department* department)
{
	//создание указателя на входной элемент
	Department* start = department;
	//проверка на путсоту списка
	if (department == nullptr)
	{
		cout << "Список групп пуст." << endl;
		return;
	}
	//цикл вывода
	do
	{
		//вывод данных
		cout << "Id кафедры: " << department->id << endl;
		cout << "Название кафедры: " << department->name << endl << endl;
		department = department->next;
	} while (department != start);
}

//Функция печати групп
void print_groups(Group* group)
{
	//создание указателя на входной элемент
	Group* start = group;
	//проверка на путсоту списка
	if (group == nullptr)
	{
		cout << "Список групп пуст." << endl;
		return;
	}
	//цикл вывода
	do
	{
		//вывод
		cout << "Id группы: " << group->id << endl;
		cout << "Id кафедры: " << group->department_id << endl << endl;
		group = group->next;
	} while (group != start);
}

//Функция печати преподавателей
void print_lecturers(Lecturer* lecturer)
{
	//указатель на входной элемент
	Lecturer* start = lecturer;
	//проверка на пустоту списка
	if (lecturer == nullptr)
	{
		cout << "Список преподавателей пуст." << endl;
		return;
	}
	//цикл вывода
	do
	{
		//вывод данных о преподаватле
		cout << "Id преподавателя: " << lecturer->id << endl;
		cout << "Имя преподавателя: " << lecturer->name << endl;
		cout << "Id кафедры: " << lecturer->department_id << endl << endl;
		lecturer = lecturer->next;
	} while (lecturer != start);
}

//Функция печати расписаний
void print_schedules(Schedule* schedule, Lecturer*& begin_lecturer)
{
	//указатель на входной элемент
	Schedule* start = schedule;
	//проверка на пустоту списка
	if (schedule == nullptr)
	{
		cout << "Список расписаний пуст." << endl;
		return;
	}

	//цикл вывода
	do
	{
		//вывод данных о расписании
		cout << "Id расписания: " << schedule->id << endl;
		cout << "Предмет: " << schedule->subject_name << endl;
		cout << "Id группы: " << schedule->group_id << endl;
		cout << "Имя преподавателя: " << find_lecturer_by_id(schedule->lecturer_id, begin_lecturer)->name << endl;
		cout << "Id аудитории: " << schedule->class_room_id << endl;
		cout << "Дата проведения: " << schedule->date_of_lesson.hour << ':'
			<< schedule->date_of_lesson.minute << ' '
			<< schedule->date_of_lesson.day << ':'
			<< schedule->date_of_lesson.month << ':'
			<< schedule->date_of_lesson.year << endl << endl;
		schedule = schedule->next;
	} while (schedule != start);
}

//Функция получения id группы рапсисания
int get_schedule_group_id(Schedule* schedule)
{
	if (schedule != nullptr)
		return -1;

	return schedule->group_id;
}

//Функция получения id преподавателя рапсисания
int get_schedule_lecturer_id(Schedule* schedule)
{
	if (schedule != nullptr)
		return -1;

	return schedule->lecturer_id;
}

//Функция получения id класса рапсисания
int get_schedule_class_room_id(Schedule* schedule)
{
	if (schedule != nullptr)
		return -1;

	return schedule->class_room_id;
}

//Функция получения названия предмета рапсисания
string get_schedule_subject_name(Schedule* schedule)
{
	return schedule->subject_name;
}

//Функция считывания преподавателей из файла
void read_lecturers(string file_name, int& error_code, Lecturer*& begin_lecturer, Lecturer*& end_lecturer, Department*& begin_department)
{
	//открытие файла
	ifstream stream(file_name);
	string str;

	//построчное считывание
	while (getline(stream, str))
	{
		string full_name;
		int index = 0;

		//посимвольная проверка
		while (str[index] != ':')
			full_name += str[index++];
		index++;
		string number;
		//посимвольная проерка
		while (str[index] == ' ')
			index++;
		while (index < str.size())
		{
			//проверка символа на int
			if (is_digit(str[index]) != true)
			{
				error_code = 1;
				return;
			}
			number += str[index++];
		}
		int department_id = atoi(number.c_str());
		//вставка преподавателя
		insert_lecturer(full_name, department_id, error_code, begin_lecturer, end_lecturer, begin_department);

		//проерка успешности вставки
		if (error_code == 1)
			return;
	}
	error_code = 0;
	cout << "Файл с преподавателями - данные считаны." << endl;
}

//Функция считывания расписаний
void read_schedules(string file_name, int& error_code, Schedule*& begin_schedule, Schedule*& end_schedule, Group*& begin_group, Lecturer*& begin_lecturer)
{
	//открытие фалйа
	ifstream stream(file_name);
	string str;

	//построчное считывание
	while (getline(stream, str))
	{
		string subject;
		int index = 0;

		//проверка каждого символа
		while (str[index] != ':')
			subject += str[index++];
		index++;
		string group_id;
		//проверка каждого символа
		while (str[index] == ' ')
			index++;
		while (str[index] != ' ')
		{
			//проверка каждого символа на цифру
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
		//посимвольное считывание
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
		//посимвольное считывание
		while (str[index] == ' ')
			index++;
		while (str[index] != ' ')
		{
			//проерка символа на цифру
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
		//посимвольное считывание
		while (index < str.size())
		{
			str_date += str[index];
			index++;
		}
		int year_int = -1, minute_int = -1, hour_int = -1, month_int = -1, day_int = -1;
		string year = "", minute = "", hour = "", month = "", day = "";
		//проверка коррекстности даты
		check_date(str_date, error_code, hour_int, minute_int, day_int, month_int, year_int, year, minute, hour, month, day);
		if (error_code == 1)
			return;

		//проерка значений даты на корректность часов, минут, дней, месяцев
		check_date_fields(year_int, error_code, minute_int, hour_int, month_int, day_int);

		//проверка на ошибки
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

		//создание структуры с датой
		Date date;
		date.hour = hour;
		date.minute = minute;
		date.day = day;
		date.month = month;
		date.year = year;

		//вставка расписания
		insert_schedule(subject, group_id_int, lecturer_id_int, class_room_id_int, error_code, date, begin_schedule, end_schedule, begin_group, begin_lecturer);
	}
	error_code = 0;
	cout << "Файл с расписаниями - данные считаны." << endl;
}

//Функция проверки значений даты
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

//Функция проверки на корректность введенных в дату значений
void check_date(string str_date, int& error_code, int& hour_int, int& minute_int, int& day_int, int& month_int, int& year_int,
	string& year, string& minute, string& hour, string& month, string& day)
{
	int index = 0;
	//посимвольное считывание
	while (str_date[index] == ' ')
		index++;

	while (str_date[index] == ' ')
		index++;
	while (str_date[index] != ':')
	{
		//проерка символа на цифру
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

	//gjcbvdjkmyjt cxbnsdfybt
	while (str_date[index] == ' ')
		index++;
	while (str_date[index] != ' ')
	{
		//проверка символа на цифру
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		minute += str_date[index++];
	}
	minute_int = atoi(minute.c_str());
	//поисмвольное считывание
	while (str_date[index] == ' ')
		index++;
	while (str_date[index] != ':')
	{
		//проверка символа на цифру
		if (is_digit(str_date[index]) != true)
		{
			error_code = 1;
			cout << "Неверные данные в вводимом значении." << endl;
			return;
		}
		day += str_date[index++];
	}
	day_int = atoi(day.c_str());

	//посимвольное считывание
	while (str_date[index] == ':')
		index++;
	while (str_date[index] != ':')
	{
		//проерка на цифру
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

	//посимвольное считывание
	while (str_date[index] == ':')
		index++;
	while (index < str_date.size())
	{
		//проверка на цифру
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

//Функция перезаписи кафедр в файл
void write_departments(string file_name, Department*& begin_department)
{
	//открытие файла
	fstream str;
	str.open(file_name);
	//очистка файла
	str.clear();
	//Создание указателя на начальный элемент
	Department* department = begin_department;
	//проверка на пустоту
	if (department == nullptr)
		return;

	//цикл вставка
	do
	{
		//вставка
		str << department->name << endl;
		department = department->next;
	} while (department != begin_department);

	//закрытие файла
	str.close();
}


//Функция перезаписи групп в файл
void write_groups(string file_name, Group*& begin_group)
{
	//открытие файла
	fstream str;
	str.open(file_name);
	//очистка файла
	str.clear();
	//Создание указателя на начальный элемент
	Group* group = begin_group;
	//проерка на пустоту
	if (group == nullptr)
		return;

	//цикл вставкки
	do
	{
		//вставка
		str << group->id << ' ' << group->department_id << endl;
		group = group->next;
	} while (group != begin_group);

	str.close();
}

//Функция перезаписи преподавателей в файл
void write_lecturers(string file_name, Lecturer*& begin_lecturer)
{
	//открытие файла
	fstream str;
	str.open(file_name);
	//очистка файла
	str.clear();
	//создание указателя на начальный элемент
	Lecturer* lecturer = begin_lecturer;

	//проверка на пустоту списка
	if (lecturer == nullptr)
		return;

	//цикл вставки
	do
	{
		//вставкка
		str << lecturer->name << ": " << lecturer->department_id << endl;
		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);

	str.close();
}

//Функция перезаписи расписаний в файл
void write_schedules(string file_name, Schedule*& begin_schedule)
{
	//открытие файла
	fstream str;
	str.open(file_name);
	//очистка файла
	str.clear();
	//Создание указателя на началный элмент
	Schedule* schedule = begin_schedule;

	//проерка на пустоту списка
	if (schedule == nullptr)
		return;

	//цикл вставки
	do
	{
		//вставкка
		str << schedule->subject_name << ": ";
		str << schedule->group_id << ' ';
		str << schedule->lecturer_id << ' ';
		str << schedule->class_room_id << ' ';
		str << schedule->date_of_lesson.hour << ':';
		str << schedule->date_of_lesson.minute << ' ';
		str << schedule->date_of_lesson.day << ':';
		str << schedule->date_of_lesson.month << ':';
		str << schedule->date_of_lesson.year << endl;
		schedule = schedule->next;
	} while (schedule != begin_schedule);

	str.close();
}

//Функция удаления расписания по заданному парметру
void remove_all_schedules_by_parameter(int parameter, int(*function)(Schedule*), Schedule*& begin_schedule, Schedule*& end_schedule)
{
	//Создание указателя на начальный элемент
	Schedule* schedule = begin_schedule;

	//проерка на пустоту
	if (schedule == nullptr)
	{
		cout << "Список расписаний пуст." << endl;
		return;
	}

	//цикл удаления
	do
	{
		int id = function(schedule);
		int schedule_id = schedule->id;
		//сравнение текущих параметров с входными
		while (id == parameter)
		{
			schedule = schedule->next;
			//удаление
			remove_element_from_list(begin_schedule, end_schedule, schedule_id);

			id = function(schedule);
			schedule_id = schedule->id;
		}
		schedule = schedule->next;
	}while (schedule != begin_schedule);
}

//Функция удаления преподавателей по id кафедры
void remove_all_lecturers_by_department_id(int department_id, Lecturer*& begin_lecturer, Lecturer*& end_lecturer, Schedule*& begin_schedule, Schedule*& end_schedule)
{
	//создание указателя на начальный элемент
	Lecturer* lecturer = begin_lecturer;

	//проерка на пустоту
	if (begin_lecturer == nullptr)
	{
		cout << "Список преподавателей пуст." << endl; 
		return;
	}

	int id = lecturer->department_id;
	int lecturer_id = lecturer->id;

	//цикл удаления
	do
	{
		id = lecturer->department_id;
		lecturer_id = lecturer->id;
		//если id кафедры текущего преподавателя равен входному
		while (id == department_id)
		{
			lecturer = lecturer->next;
			//удаление
			remove_all_schedules_by_parameter(lecturer_id, get_schedule_lecturer_id, begin_schedule, end_schedule);
			remove_element_from_list(begin_lecturer, end_lecturer, lecturer_id);

			id = lecturer->department_id;
			lecturer_id = lecturer->id;
		}
		lecturer = lecturer->next;
	} while (lecturer != begin_lecturer);
}

//Удаление всех групп по id кафедры
void remove_all_groups_by_department_id(int department_id, Group*& begin_group, Group*& end_group, Schedule*& begin_schedule, Schedule*& end_schedule)
{
	//создание указателя на начальный элемент
	Group* group = begin_group;

	//проерка на пустоту
	if (begin_group== nullptr)
	{
		cout << "Список групп пуст." << endl;
		return;
	}

	//цикл удаления
	do
	{
		int id = group->department_id;
		int group_id = group->id;

		//если id кафедры текущей группы равен входному
		while (id == department_id)
		{
			group = group->next;
			//удаление
			remove_all_schedules_by_parameter(group_id, get_schedule_group_id, begin_schedule, end_schedule);
			remove_element_from_list(begin_group, end_group, group_id);
			
			id = group->department_id;
			group_id = group->id;
		}
		group = group->next;
	} while (group != begin_group);
}

//проверка существования фалйа
void check_file(string file_name, int& error_code)
{
	//открытие файла
	fstream fin(file_name);
	//если файл не открыт
	if (!fin.is_open()) //проверка на существование
	{
		//вывод ошибки
		cout << "ОШИБКА!!! Файл " << file_name << " не найден!" << endl;
		error_code = 1;
		fin.close();
		return;
	}
	//проерка на пустоту файла
	if (fin.peek() == EOF) // проверка на содержание (пустоту)
	{
		//вывод ошибка
		cout << "ОШИБКА!!! Файл " << file_name << " пуст!" << endl;
		error_code = 1;
		fin.close();
		return;
	}
	fin.close();
	error_code = 0;
}

