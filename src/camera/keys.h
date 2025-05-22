/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:19:49 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 11:49:32 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef struct s_key_info
{
	int			keycode;
	const char	*name;
	const char	*description;
	int			separator;
}	t_key_info;

# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define NUMPAD_0	65438
# define NUMPAD_1	65436
# define NUMPAD_2	65433
# define NUMPAD_3	65435
# define NUMPAD_4	65430
# define NUMPAD_5	65437
# define NUMPAD_6	65432
# define NUMPAD_7	65429
# define NUMPAD_8	65431
# define NUMPAD_9	65434
# define NUMPAD_PLUS	65451
# define NUMPAD_MINUS	65453
# define NUMPAD_ENTER	65421
# define NUMPAD_DOT	65439

# define NUMKEY_0	48
# define NUMKEY_1	49
# define NUMKEY_2	50
# define NUMKEY_3	51
# define NUMKEY_4	52
# define NUMKEY_5	53
# define NUMKEY_6	54
# define NUMKEY_7	55
# define NUMKEY_8	56
# define NUMKEY_9	57

# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_SPACE	32
# define KEY_TAB	65289
# define KEY_ENTER	13
# define KEY_BACKSPACE	8

# define KEY_Z		122
# define KEY_X		120
# define KEY_C		99
# define KEY_V		118
# define KEY_B		98
# define KEY_N		110
# define KEY_M		109
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_F		102
# define KEY_G		103
# define KEY_H		104
# define KEY_J		106
# define KEY_K		107
# define KEY_L		108
# define KEY_Q		113
# define KEY_W		119
# define KEY_E		101
# define KEY_R		114
# define KEY_T		116
# define KEY_Y		121
# define KEY_U		117
# define KEY_I		105
# define KEY_O		111
# define KEY_P		112

# define KEY_ESC	65307
# define KEY_F1		65470
# define KEY_F2		65471
# define KEY_F3		65472
# define KEY_F4		65473
# define KEY_F5		65474
# define KEY_F6		65475
# define KEY_F7		65476
# define KEY_F8		65477
# define KEY_F9		65478
# define KEY_F10	65479
# define KEY_F11	65480
# define KEY_F12	65481
# define KEY_SHIFT	65505
# define KEY_CTRL	65507

static const t_key_info	g_key_info[] = {
{KEY_W, "W", "Move forward", 0},
{KEY_S, "S", "Move backward", 0},
{KEY_A, "A", "Move left", 0},
{KEY_D, "D", "Move right", 0},
{KEY_UP, "Up Arrow", "Move camera up", 0},
{KEY_DOWN, "Down Arrow", "Move camera down", 0},
{KEY_LEFT, "Left Arrow", "Move camera left", 0},
{KEY_RIGHT, "Right Arrow", "Move camera right", 1},
{KEY_ESC, "Esc", "Exit program", 0},
{KEY_TAB, "Tab", "Toggle menu", 1},
{KEY_Z, "Z", "Rotate plane around Z-axis", 0},
{KEY_X, "X", "Rotate plane around X-axis", 0},
{KEY_Y, "Y", "Rotate plane around Y-axis", 0},
{KEY_R, "R", "Reset plane transform", 0},
{NUMPAD_3, "Numpad 3", "Translate plane up", 0},
{NUMPAD_6, "Numpad 6", "Translate plane down", 1},
{NUMPAD_1, "Numpad 1", "Set front view", 0},
{NUMPAD_4, "Numpad 4", "Set right view", 0},
{NUMPAD_7, "Numpad 7", "Set top view", 0},
{NUMPAD_2, "Numpad 2", "Set back view", 0},
{NUMPAD_5, "Numpad 5", "Set left view", 0},
{NUMPAD_8, "Numpad 8", "Set bottom view", 1},
{KEY_O, "O", "Move light right", 0},
{KEY_P, "P", "Move light left", 0},
{KEY_I, "I", "Move light up", 0},
{KEY_K, "K", "Move light down", 0},
{KEY_L, "L", "Move light forward", 0},
{KEY_J, "J", "Move light backward", 0},
{KEY_SPACE, "Space", "Reset light position", 0},
{KEY_M, "M", "Switch camera mode", 1},
{NUMKEY_9, "Numkey 9", "Increase render quality", 0},
{NUMKEY_8, "Numkey 8", "Decrease render quality", 0},
{0, "", "", 0}
};

#endif