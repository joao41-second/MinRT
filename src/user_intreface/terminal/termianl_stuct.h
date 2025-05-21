
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


