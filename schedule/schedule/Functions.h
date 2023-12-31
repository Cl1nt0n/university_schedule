#include "Structs.h"
/*************************************************************************
*                                                                        *
*           �������� ������ �� ���������� ����������������               *
*                                                                        *
**************************************************************************
*Project type : Visual Studio Solution                                   *
*Project name : ������                                                   *
*File name    : main.cpp                                                 *
*Language     : CPP, MSVS 2022                                           *
*Programmer   : ������� ����� ��������, �3�-210�-22                      *
*Modified by  :                                                          *
*Created      : 20.12.2023                                               *
*Last revision: 26.12.2023                                               *
*Comment      : ��������� ���� ������    					             *
*************************************************************************/
//************************************************************************
//*                     ��������� �������                                *
//************************************************************************

//������� ���������� ������ �� �����
void read_departments(string file_name, //��� �����
	int& error_code);//��� ������

//������� ���������� ����� �� �����
void read_groups(string file_name, //��� �����
	int& error_code);//��� ������

//������� ���������� �������������� �� �����
void read_lecturers(string file_name, //��� �����
	int& error_code);//��� ������

//������� ���������� ���������� �� �����
void read_schedules(string file_name, //��� �����
	int& error_code);//��� ������

//������� �������� ����� ����
void check_date_fields(int year_int, //��� 
	int& error_code, //��� ������
	int minute_int, //������
	int hour_int, //���
	int month_int, //�����
	int day_int);//����

//������� �������� ����� 
void check_file(string file_name, //�������� �����
	int& error_code); //��� ������

//������� ������� �������
void insert_department(string name, //��������
	int& error_code); //��� ������

//������� ������� �������������
void insert_lecturer(string name, //���
	int department_id, //id �������
	int& error_code); //��� ������

//������� ������� ������
void insert_group(int department_id, //id �������
	int id, //����� ������
	int& error_code); //��� ������

//������� ������� ����������
void insert_schedule(string subject_name, //�������� ��������
	int group_id, //id ������
	int lecturer_id, //id �������������
	int class_room_id, //id ������
	int& error_code, //��� ������
	Date date); //����

//������� ������ ������� �� id
Department* find_department_by_id(int id); //id

//������� ������ ������� �� �����
Department* find_department_by_name(string name); //�������� �������

//������� ������ ������ �� id
Group* find_group_by_id(int id); //id

//������� ������ ����� �� id �������
Group* find_groups_by_department_id(int department_id); //id �������

//������� ������ ������������� �� id
Lecturer* find_lecturer_by_id(int id); //id

//������� ������ �������������� �� �����
Lecturer* find_lecturers_by_name(string name); //���

//������� ������ �������������� �� id �������
Lecturer* find_lecturers_by_department_id(int department_id); //id �������

//������� ������ ���������� �� id
Schedule* find_schedule_by_id(int id); //id

//������� ������ ���������� �� ����
Schedule* find_schedule_by_date(string hour, //���
	string minute, //������
	string day, //����
	string month, //�����
	string year); //���

//������� �������� ������� �� �����
bool is_digit(char symbol); //������

//������� ������ ������
void print_departments(Department* department); //�������

//������� ������ �����
void print_groups(Group* group); //������

//������� ������ ��������������
void print_lecturers(Lecturer* lecturer); //�������������

//������� ������ ����������
void print_schedules(Schedule* schedule); //����������

//������� ��������� id ������ ���������
int get_schedule_group_id(Schedule* schedule);//����������

//������� ��������� id ������������� ����������
int get_schedule_lecturer_id(Schedule* schedule);//����������

//������� ��������� id ������ ����������
int get_schedule_class_room_id(Schedule* schedule);//����������

//������� ��������� �������� �������� ����������
string get_schedule_subject_name(Schedule* schedule);//����������

//������� �������� ����
void check_date(string str_date, //��������� ����
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

//������� ���������� ����� � ���������
void write_departments(string file_name);//��� �����

//������� ���������� ����� � ��������
void write_groups(string file_name);//��� �����

//������� ���������� ����� � ���������������
void write_lecturers(string file_name);//��� �����

//������� ���������� ����� � �����������
void write_schedules(string file_name);//��� �����

//������� �������� ���� ���������� �� �������� ����������
void remove_all_schedules_by_parameter(int parameter, //��������
	int(*function)(Schedule*));//������� ��������� ��������� ����������

//������� �������� ���� ���������� �� id �������
void remove_all_lecturers_by_department_id(int department_id);//id �������

//������� �������� ���� ����� �� id �������
void remove_all_groups_by_department_id(int department_id);//id �������

//������� ������� ������ ���������� ����
template<typename T>
void clear_list(T*& start, //��������� �������
	T*& end)//�������� �������
{
	//�������� �� ������� ������
	if (start == nullptr)
	{
		cout << "������ ����." << endl;
		return;
	}
	T* current = start;
	T* previous = end;

	//��������, ������� �� � ������ ������ ���� �������
	if (current == previous)
	{
		delete start;
		start = nullptr;
		end = nullptr;
		cout << "������� ������ �� ������." << endl;
		return;
	}

	//����, ���� ��������� ������� �� ������
	do
	{
		current = start;
		start->previous->next = start->next;
		start->next->previous = start->previous;
		start = start->next;
		delete current;
		if (start == current)
			start = nullptr;
	} while (start != nullptr);
}


//������� �������� �������� �� ������
template<typename T>
void remove_element_from_list(T*& start, //��������� �������
	T*& end, //�������� �������
	int id)//id ��������
{
	//�������� �� ������� ������
	if (start == nullptr)
	{
		cout << "������ ����." << endl;
		return;
	}

	T* current = start;
	T* previous = end;

	//��������, ������� �� � ������ ������ ���� �������
	if (current == previous)
	{
		//��������, �������� �� ���� ������� �������
		if (current->id == id)
		{
			delete start;
			start = nullptr;
			end = nullptr;
			cout << "������� ������ �� ������." << endl;
			return;
		}
	}


	//����, ���� �� ��������� ��� �������� ������ 
	do
	{
		//��������, �������� �� ������� �������
		if (current->id == id)
		{
			//��������, �������� �� ���� ������� ���������
			if (current == start)
			{
				start = current->next;
				end->next = current->next;
			}
			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
			cout << "������� ������ �� ������." << endl;
			return;
		}

		current = current->next;
	} while (current != start);

	cout << "������� �� ������." << endl;
}


//������� ���������� ���������� �� �������� ����������
template<typename T>
Schedule* find_schedule_by_parameters(T parameter, //��������
	T(*function)(Schedule*))//������� ��������� ���� ���������
{
	//���������� ����������
	Schedule* schedule = begin_schedule;

	if (schedule == nullptr)
		return nullptr;

	Schedule* temp = new Schedule(schedule->subject_name,
		schedule->id,
		schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
	temp->next = nullptr;
	temp->previous = nullptr;
	Schedule* begin_temp = temp;

	//����, ���� �� ��������� ��� �������� ������
	do
	{
		//��������, �������� �� ������� �������
		if (function(schedule) == parameter)
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

	//��������, ���� �� ������ �� ���� �������
	if (temp->next == nullptr)
	{
		//�������� ������� �������� ������ ������
		delete temp;
		return nullptr;
	}
	//�������� ������� �������� ������ ������
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}