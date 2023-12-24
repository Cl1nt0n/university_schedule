#include "Structs.h"

void insert_department(string name, int& error_code);
void read_departments(string file_name, int& error_code);
void read_groups(string file_name, int& error_code);
void read_lecturers(string file_name, int& error_code);
void read_schedules(string file_name, int& error_code);
void check_file(string file_name, int &error_code);
void insert_lecturer(string name, int department_id, int& error_code);
void insert_group(int department_id, int id, int& error_code);
void insert_schedule(string subject_name, int group_id, int lecturer_id, int class_room_id, int& error_code, Date date);
Department* find_department_by_id(int id);
Department* find_department_by_name(string name);
Group* find_group_by_id(int id);
Lecturer* find_lecturer_by_id(int id);
Lecturer* find_lecturer_by_name(string name);

template <typename T>
Schedule* find_schedule_parameters_id(T class_room_id, T(*function)(Schedule*));

bool is_digit(char symbol);
void print_departments();
void print_groups();
void print_lecturers();
void print_schedules(Schedule* schedule);

int get_schedule_group_id(Schedule* schedule);
int get_schedule_lecturer_id(Schedule* schedule);
int get_schedule_class_room_id(Schedule* schedule);
string get_schedule_subject_name(Schedule* schedule);

