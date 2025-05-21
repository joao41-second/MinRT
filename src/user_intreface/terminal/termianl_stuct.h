
#include   "../../minRT.h"


typedef struct s_terminos
{
	t_list_ *comands;
		
} t_terminos;

typedef struct s_coamnd
{
	char * name;
	t_list_ * element;
	void *func;
} t_comand;


typedef struct s_element 
{
	void *element;
	t_list_ *opcion;
	void *standard_element;
} t_element;


t_element *cc_add_new_object_elemnt_type();

t_comand *cc_add_new_object();


void ter_tab_logic(t_user_in data,int key, char *str);

void term_change_color(t_user_in data,char *str,int nb_line, int neg_color);
