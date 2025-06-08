/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:01:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/04 14:43:51 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../ray/ray_struct.h"
#include <pthread.h>
#include <semaphore.h>

typedef struct s_thread {
  t_obj_int valuse[CUBE][CUBE];
  t_camera_ms cam;
  int min_x;
  int min_y;
} t_thread;

t_thread cm_start_theard(t_minirt *rt_struct, int min_x, int min_y) {
  t_thread new;
  new.cam = rt_struct->cam_m;
  new.min_x = min_x;
  new.min_y = min_x;
  return new;
}

void *thread_logic(void *new) {
  t_thread *new_;

  new_ = (t_thread *)new;

  // ray_in_obj = ray_for_objects(rt_struct->word, ray,luz);

  return (NULL);
}

void cm_theard(t_minirt *rt_struct, int x_, int y_, int resul) {
  static pthread_t *threads = NULL;
  static t_thread *new;
  int i;
  int x;
  int y;
  x = 0;
  y = 0;
  i = 0;
  if (threads == NULL) {
    threads = ft_malloc(sizeof(pthread_t) * ((x_ * y_) / CUBE), NULL);
    new = ft_malloc(sizeof(t_thread) * ((x_ * y_) / CUBE), NULL);
  }
  while (x < x_ && x + CUBE < x_) {
    y = 0;
    while (y < y_ && y + CUBE < y_) {
      i++;
      new[i] = cm_start_theard(rt_struct, x, y);
      pthread_create(&threads[i], NULL, thread_logic, (void *)&new[i]);
      y += CUBE;
    }
    x += CUBE;
  }
}
