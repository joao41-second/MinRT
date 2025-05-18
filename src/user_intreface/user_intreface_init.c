#include "user_interface_struct.h"
#include "user_intreface.h"

void user_intreface_key_clear()
{
}

void user_intreface_key_reset()
{
}

void user_intrefaces_update()
{
}

t_user_in user_intrefaces_init(t_canva canva,t_list_ *word )
{
	t_user_in ret;
	
	ret.word =word;
	ret.canvas = &canva;
	return (ret);	
}
