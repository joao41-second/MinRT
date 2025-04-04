
#include "../minRT.h"

t_vector lig_normalize(t_point oring_ob,t_point p_the_obj) 
{
	t_vector ret;

	ret = sub_tuples(oring_ob, p_the_obj);
	ret = normalize(&ret);
	return (ret);
}
