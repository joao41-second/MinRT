/* ************************************************************************** *//*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:15:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/25 18:18:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

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
	new  = add_tuples(ray.origin, ray.direction);
	if(nb == 0)
		return (new);
	return(scalar_mult_tuples(new, nb)); 
}
// At2+By+C=0
//
//A=dx2+dy2+dz2
//B=2[dx(px−cx)+dy(py−cy)+dz(pz−cz)]
//C=(px−cx)2+(py−cy)2+(pz−cz)2−R2
//
t_object_ ray_int_sphere(t_ray ray,t_sphere shp)
{
	t_object_ ret;
	t_point point;
	double a_;
	double b_;
	double c_;

	
	ret.object = &shp;
	a_ = dot_product(&ray.direction,&ray.direction);
	b_ = 2 * ((ray.direction.x * (ray.origin.x - shp.center.x)) +
			(ray.direction.y * (ray.origin.y - shp.center.y)) +
				(ray.direction.z * (ray.origin.z - shp.center.z)));
	c_ = ((ray.origin.x - shp.center.x)*(ray.origin.x - shp.center.x)) +
		((ray.origin.y - shp.center.y)*(ray.origin.y - shp.center.y)) +
			((ray.origin.z - shp.center.z)*(ray.origin.z - shp.center.z))
				- (shp.ray_s * shp.ray_s);
	ret.t[0] = (-b_ + sqrt((b_*b_) - (4 * a_ * c_))/(2 * a_));
	ret.t[1] = (-b_ - sqrt((b_*b_) - (4 * a_ * c_))/(2 * a_));
	return(ret);
}
