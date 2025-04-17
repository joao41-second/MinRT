/* ************************************************************************** *//*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:15:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/25 18:18:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "../minRT.h"
#include "ray_struct.h"
#include <stdio.h>

double mutl_dub(double nb1,double nb2)
{
	return (nb1*nb2);
}

t_ray ray_gener(t_point point,t_vector dir)
{
	t_ray ray;
	ray.direction = dir;
	ray.origin = point;
	return (ray);
}

t_point ray_position(t_ray ray,double nb)
{
	t_point new;
	new  =  add_tuples( ray.origin,create_point(nb, nb, nb));

	lig_print_tuple(new);

	if(nb == 0)
		return (new);
	return(create_point( ray.direction.x * new.x ,  ray.direction.y * new.y , ray.direction.z * new.z)); 
}

t_point ray_t_to_point(t_point const point,double t)
{
	t_point new;
	
	new = point;
	if(t*point.x != 0)
		new.x = point.x + (t);
	if(t*point.y != 0)
		new.y = point.y + (t);
	if(t*point.z != 0)
		new.z = point.z + (t);
	return (new);
}

// At2+By+C=0
//
//A=dx2+dy2+dz2
//B=2[dx(px−cx)+dy(py−cy)+dz(pz−cz)]
//C=(px−cx)2+(py−cy)2+(pz−cz)2−R2
//
t_intersection ray_int_sphere(t_ray ray_,t_sphere shp)
{
	t_intersection ret;
	double a_;
	double b_;
	double c_;
	double temp;
	t_ray ray;

	ray = ray_transform(ray_,shp.inv_transform);
	//t_ray final =  ray_transform(ray_,shp.inv_transform);

	//printf("%f %f %f point %f %f %f ray",
	//		final.all[0].x, final.all[0].y, final.all[0].z,final.all[1].x, final.all[1].y, final.all[1].z);
	   
	a_ = ((ray.direction.x * ray.direction.x) + (ray.direction.y * ray.direction.y )+ (ray.direction.z * ray.direction.z)) ;

	b_ = 2 * ((ray.direction.x * (ray.origin.x - shp.center.x)) +
			(ray.direction.y * (ray.origin.y - shp.center.y)) +
				(ray.direction.z * (ray.origin.z - shp.center.z)));
	c_ = ((ray.origin.x - shp.center.x)*(ray.origin.x - shp.center.x)) +
		((ray.origin.y - shp.center.y)*(ray.origin.y - shp.center.y)) +
			((ray.origin.z - shp.center.z)*(ray.origin.z - shp.center.z))
				- (shp.ray_s * shp.ray_s);
	ret.object = &shp;
	ret.inter = (b_*b_) -4 * a_ * c_;
	temp = sqrt(ret.inter);	

	ret.t[1] = 0 ;
	ret.t[0] = 0;

	ret.t[1] += (-(b_) + temp)/(2 * a_);
	ret.t[0] += (-(b_) - temp)/(2 * a_);
	if(isnan(ret.t[0]))
		ret.t[0] = + ret.t[0];
	if(isnan(ret.t[1]))
		ret.t[1] = + ret.t[1];

	//printf("the ret 1 = %f \n",ret.t[1]);
	ret.ray_start = ray;

	return(ret);
}

double ray_model_venct(t_vector vect)
{
	double ret;

	ret = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
	return(ret);
}

t_tuple ray_ang_to_vect(double x,double y,double z)
{
	t_vector vect;
	double module_v;

	module_v = 1;
	vect.z = 1*cos(z);
	vect.x = 1*cos(x);
	vect.y = 1*cos(y);
	return(vect);
}
