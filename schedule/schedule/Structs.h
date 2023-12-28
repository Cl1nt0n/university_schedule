/*************************************************************************
*                                                                        *
*           ÊÓĞÑÎÂÀß ĞÀÁÎÒÀ ïî äèñöèïëèíå ÏĞÎÃĞÀÌÌÈĞÎÂÀÍÈÅ               *
*                                                                        *
**************************************************************************
*Project type : Visual Studio Solution                                   *
*Project name : Êóğñà÷                                                   *
*File name    : main.cpp                                                 *
*Language     : CPP, MSVS 2022                                           *
*Programmer   : ×èíÿêîâ Èãîğü Ïàâëîâè÷, Ì3Î-210Á-22                      *
*Modified by  :                                                          *
*Created      : 20.12.2023                                               *
*Last revision: 26.12.2023                                               *
*Comment      : Ñïèñî÷íûå áàçû äàííûõ    					             *
*************************************************************************/
#include "fstream"
#include "iostream"
#include "string"
using namespace std;

//************************************************************************
//*                           ÑÒĞÓÊÒÓĞÛ                                  *
//************************************************************************
//Ñòğóêòóğà êàôåäğà
struct Department
{
	int id;			// Íîìåğ êàôåäğû
	string name;    // íàçâàíèå êàôåäğû
	Department* next;//óêàçàòåëü íà ñëåäóşùóş êàôåäğó
	Department* previous;//óêàçàòåëü íà ïğåäûäóùóş êàôåäğó

	//êîíñòğóòêòîğ
	Department(string name)
	{
		this->name = name;
	}
};

//Ñòğóêòóğà ãğóïïà
struct Group
{
	int id;//íîìåğ ãğóïïû
	int department_id;//id êàôåäğû
	Group* next;//óêàçàòåëü íà ñëóäóşùóş ãğóïïó
	Group* previous;//óêàçàòåëü íà ïğåäûäóùóş ãğóïïó

	//êîíñòğóêòîğ
	Group(int department_id, int id)
	{
		this->id = id;
		this->department_id = department_id;
	}
};

//ñòğóòêòóğà äàòà
struct Date
{
	string hour;//÷àñ
	string minute;//ìèíóòà
	string day;//äåíü
	string month;//ìåñÿö
	string year;//ãîä
};

//ñòğóêòóğà ğàñïèñàíèå
struct Schedule
{
	int id;//id ğàñïèñàíèÿ
	int group_id;//íîìåğ ãğóïïû
	int lecturer_id;//id ïğåïîäàâàòåëÿ
	int class_room_id;//íîìåğ àóäèòîğèè
	int subject_id;//íàçâàíèå ïğåäìåòà
	Date date_of_lesson;//äàòà ïğîâåäåíèÿ
	Schedule* next;//óêàçàòåëü íà ñëåäóşùåå ğàñïèñàíèå
	Schedule* previous;//óêàçàòåëü íà ïğåäûäóùåå ğàñïèñàíèå

	//êîíñòğóêòîğ
	Schedule(int subject_id, int group_id, int lecturer_id, int class_room_id, Date date)
	{
		date_of_lesson = date;
		this->subject_id = subject_id;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
	}

	//êîíñòğóêòîğ
	Schedule(int subject_id, int id, int group_id, int lecturer_id, int class_room_id, Date date)
	{
		date_of_lesson = date;
		this->subject_id = subject_id;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
		this->id = id;
	}
};

//ñòğóêòóğà ïğåïîäàâàòåëÿ
struct Lecturer
{
	int id;//id ëåêòîğà
	int department_id;//id êàôåäğû
	string name;//èìÿ ïğåïîäàâàòåëÿ
	Lecturer* next;
	Lecturer* previous;

	//êîíñòğóêòîğ
	Lecturer(string name, int department_id)
	{
		this->name = name;
		this->department_id = department_id;
	}

	//êîíñòğóêòîğ
	Lecturer(string name, int department_id, int id)
	{
		this->name = name;
		this->department_id = department_id;
		this->id = id;
	}
};

struct Subject
{
	int id;
	string name;
	Subject* next;
	Subject* previous;

	Subject(string name)
	{
		this->name = name;
	}
};

struct ClassRoom
{
	int id;
	ClassRoom* next;
	ClassRoom* previous;

	ClassRoom(int id)
	{
		this->id = id;
	}
};

