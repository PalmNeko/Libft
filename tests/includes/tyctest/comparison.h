/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:33:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/06 02:33:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARISON_H
# define COMPARISON_H

# define NUM_EQ(val1, val2) ((val1) == (val2))
# define NUM_NE(val1, val2) ((val1) != (val2))
# define NUM_LT(val1, val2) ((val1) < (val2))
# define NUM_LE(val1, val2) ((val1) <= (val2))
# define NUM_GT(val1, val2) ((val1) > (val2))
# define NUM_GE(val1, val2) ((val1) >= (val2))
# define STR_EQ(val1, val2) (strcmp(val1, val2) == 0)
# define STR_NE(val1, val2) (strcmp(val1, val2) != 0)
# define STR_CASEEQ(val1, val2) (stricmp(val1, val2) == 0)
# define STR_CASENE(val1, val2) (stricmp(val1, val2) != 0)

#endif