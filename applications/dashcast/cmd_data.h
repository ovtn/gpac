/*
 *			GPAC - Multimedia Framework C SDK
 *
 *			Authors: Arash Shafiei
 *			Copyright (c) Telecom ParisTech 2000-2013
 *					All rights reserved
 *
 *  This file is part of GPAC / dashcast
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef CMD_DATA_H_
#define CMD_DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <gpac/config_file.h>
#include <gpac/list.h>
#include "audio_data.h"
#include "video_data.h"


/*
 * This structure corresponds to
 * the data in command line
 */
typedef struct  {
	/* input video */
	VideoData vdata;
	/* audio input data */
	AudioData adata;
	/* Configuration file */
	GF_Config * p_conf;
	/* MPD file */
	char psz_mpd[GF_MAX_PATH];
	/* segment duration */
	int i_seg_dur;
	/* fragment duration */
	int i_frag_dur;
	/* Exit signal emitting from user to end the program */
	int i_exit_signal;
	/* List of entries for video in configuration file */
	GF_List * p_video_lst;
	/* List of entries for audio in configuration file */
	GF_List * p_audio_lst;
	/* Indicates that the system is live */
	int i_live;
	/* output directory name */
	char psz_out[GF_MAX_PATH];

} CmdData;
/*
 * Initilize the command data structure
 * 
 * @param cmdd [out] structure to be initilize
 *
 */
void dc_cmd_data_init(CmdData * cmdd);
/*
 * Destroy the command data structure
 *
 * @param cmdd [out] structure to be destroyed
 *
 */
void dc_cmd_data_destroy(CmdData * cmdd);
/*
 * Parse command line
 *
 * @param argc [in] number of arguments
 * @param argv [in] a list of strings each containing one argument
 * @param cmdd [out] the data structure to fill
 *
 */
int dc_parse_command(int argc, char ** argv, CmdData * cmdd);


#endif /* CMD_DATA_H_ */