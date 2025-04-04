/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:15:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/04 20:00:47 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ray.h"
#include "../minRT.h"
#include "ray_struct.h"

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
	ret.t[1] = (-(b_) + sqrt((b_*b_) -4 * a_ * c_))/(2 * a_);
	ret.t[0] = (-(b_) - sqrt((b_*b_) -4 * a_ * c_))/(2 * a_);
	ret.ray_start = ray;
	ret.point[1] = ray_t_to_point(ray.origin, ret.t[1]);
	ret.point[0] = ray_t_to_point(ray.origin, ret.t[0]);
	return(ret);
}

t_intersection ray_int_plane(t_ray ray, t_object *plane)
{
    t_ray transformed_ray = ray_transform(ray, plane->u_data.plane.inv_transform);
    
    double denom = dot_product(transformed_ray.direction, create_vector(0, 1, 0));
    
    if (fabs(denom) < EPSILON)
    {
        t_intersection ret;
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    
    double t = -transformed_ray.origin.y / denom;
    printf("Ray intersects the plane at t = %f\n", t);
    if (t < 0)
    {
        t_intersection ret;
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    
    t_intersection ret;
    ret.inter = 1;
    ret.t[0] = t;
    ret.t[1] = -1;
    ret.object = plane;
    
    return ret;
}

t_intersection ray_int_object(t_ray ray, t_object obj)
{
    t_intersection intersection;

    if (obj.type == OBJ_SPHERE)
        intersection = ray_int_sphere(ray, obj.u_data.sphere);
    else if (obj.type == OBJ_PLANE)
        intersection = ray_int_plane(ray, &obj);
    else
    {
        intersection.inter = 0;
        intersection.object = NULL;
        intersection.t[0] = -1;
        intersection.t[1] = -1;
    }

    return intersection;
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



