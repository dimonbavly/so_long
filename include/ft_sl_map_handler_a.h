/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_map_handler_a.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:03:51 by                   #+#    #+#             */
/*   Updated: 2021/10/02 11:03:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SL_MAP_HANDLER_A_H
# define FT_SL_MAP_HANDLER_A_H

char	**ft_list_to_char_arr(t_list *list);
void	ft_check_map_name(char *filename);
void	ft_check_map_dimensions_and_elements(char **map);
void	ft_check_map_symbols(int *arr);
void	ft_check_borders_and_len(char **map);

#endif //FT_SL_MAP_HANDLER_A_H
