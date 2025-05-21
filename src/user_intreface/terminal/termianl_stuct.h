
#include   "../../minRT.h"


typedef struct s_terminos
{
	t_list_ *comands;
		
} t_terminos;

typedef struct s_coamnd
{
	char * name;
	t_list_ * element;
	void (*exec)(t_user_in *data,void *,void *,void*);
	void *viod1;
	void *viod2;
	void *viod3;
	void (*use_str_set_valuse)(char * str,void *,void *,void*);

} t_comand;


typedef struct s_element 
{
	void *element;
	t_list_ *opcion;
} t_element;


t_element *cc_add_new_object_elemnt_type();

t_comand *cc_add_new_object();

void ter_exec_obj(t_user_in *data,void* v1,void*v2,void *v3);


void ter_exec(t_user_in *data,char *str);

void ter_tab_logic(t_user_in data,int key, char *str);

void term_change_color(t_user_in data,char *str,int nb_line, int neg_color);
