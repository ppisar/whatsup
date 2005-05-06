/*****************************************************************************\
 *  $Id: nodeupdown_config.h,v 1.3 2005-05-06 18:23:39 achu Exp $
 *****************************************************************************
 *  Copyright (C) 2003 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Albert Chu <chu11@llnl.gov>
 *  UCRL-CODE-155699
 *  
 *  This file is part of Whatsup, tools and libraries for determining up and
 *  down nodes in a cluster. For details, see http://www.llnl.gov/linux/.
 *  
 *  Whatsup is free software; you can redistribute it and/or modify 
 *  it under the terms of the GNU General Public License as published by the 
 *  Free Software Foundation; either version 2 of the License, or (at your 
 *  option) any later version.
 *  
 *  Whatsup is distributed in the hope that it will be useful, but 
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License 
 *  for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with Whatsup; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#ifndef _NODEUPDOWN_CONFIG_H
#define _NODEUPDOWN_CONFIG_H

#include <nodeupdown/nodeupdown_constants.h>

#define NODEUPDOWN_CONFIG_HOSTNAMES_MAX 8

/* 
 * struct nodeupdown_config
 *
 * stores configuration file data
 */
struct nodeupdown_config 
{
  char hostnames[NODEUPDOWN_CONFIG_HOSTNAMES_MAX+1][NODEUPDOWN_MAXHOSTNAMELEN+1];
  int hostnames_len;
  int hostnames_flag;
  int port;
  int port_flag;
  int timeout_len;
  int timeout_len_flag;
};

#endif /* _NODEUPDOWN_CONFIG_H */