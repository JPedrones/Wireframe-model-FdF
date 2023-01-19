/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:38:58 by jpedrones         #+#    #+#             */
/*   Updated: 2022/09/30 18:33:41 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ERR_USAGE			"Map not defined.\nTry: \033[0;35m./fdf ./maps/42.fdf"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_INVALID_MAP	"The MAP_FILE must end with .fdf"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_MAP_READING	"Map read error"
# define ERR_NEW_COORD		"Error generating new coordinate"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CAMERA_INIT	"Camera initialization error"

#endif //ERROR_MESSAGE_H