#include "Functions.h"

void insert_department(string name)
{
	Department* department = new Department(name);
	if (begin_department == nullptr)
	{
		begin_department = department;
		end_department = department;
	}
	else
	{
		end_department->next = department;
		department->previous = end_department;
		end_department = department;
	}
}

void insert_group(int department_id, int id)
{
	Group* group = new Group(department_id, id);
	if (begin_group == nullptr)
	{
		begin_group = group;
		end_group = group;
	}
	else
	{
		end_group->next = group;
		group->previous = end_group;
		end_group = group;
	}
}

Department* find_department_by_id(int id)
{
	Department* department = begin_department;
	while (department != nullptr)
	{
		if (department->id == id)
		{
			return department;
		}
		department = department->next;
	}

	return nullptr;
}

void read_data(string file_name)
{
	ifstream stream(file_name);

	while (!stream.eof())
	{
		string name;
		stream >> name;
		int a;
		while (a != '\n')
		{
			stream >> a;
			
		}

		cout << "Название кафедры: " << name;

		insert_department(name);

		cout << "Номер кафедры: " << department_id;
	}

	cout << "Данные считаны." << endl;
}
