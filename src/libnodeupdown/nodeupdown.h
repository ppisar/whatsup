/*
 *  $Id: nodeupdown.h,v 1.18 2003-04-25 18:54:05 achu Exp $
 *  $Source: /g/g0/achu/temp/whatsup-cvsbackup/whatsup/src/libnodeupdown/nodeupdown.h,v $
 *    
 */

#ifndef _NODEUPDOWN_H
#define _NODEUPDOWN_H

#include <stdio.h>

/**************************************
 * Definitions                        *
 **************************************/

#define NODEUPDOWN_ERR_SUCCESS            0 /* success */
#define NODEUPDOWN_ERR_NULLHANDLE         1 /* nodeupdown handle is null */
#define NODEUPDOWN_ERR_OPEN               2 /* open file error */
#define NODEUPDOWN_ERR_READ               3 /* read file error */
#define NODEUPDOWN_ERR_CONNECT            4 /* network connection error */
#define NODEUPDOWN_ERR_TIMEOUT            5 /* network connect timeout */
#define NODEUPDOWN_ERR_ADDRESS            6 /* network address error */
#define NODEUPDOWN_ERR_NETWORK            7 /* network error */
#define NODEUPDOWN_ERR_ISLOADED           8 /* data already loaded */
#define NODEUPDOWN_ERR_NOTLOADED          9 /* data not loaded */
#define NODEUPDOWN_ERR_OVERFLOW          10 /* overflow on list/string passed in */
#define NODEUPDOWN_ERR_PARAMETERS        11 /* incorrect parameters passed in */
#define NODEUPDOWN_ERR_NULLPTR           12 /* null pointer in list */
#define NODEUPDOWN_ERR_OUTMEM            13 /* out of memory */
#define NODEUPDOWN_ERR_NODE_CONFLICT     14 /* conflict between gmond & genders */
#define NODEUPDOWN_ERR_NOTFOUND          15 /* node not found */ 
#define NODEUPDOWN_ERR_GENDERS           16 /* internal genders error */
#define NODEUPDOWN_ERR_GANGLIA           17 /* internal ganglia error */
#define NODEUPDOWN_ERR_HOSTLIST          18 /* internal hostlist error */
#define NODEUPDOWN_ERR_MAGIC             19 /* magic number error */
#define NODEUPDOWN_ERR_INTERNAL          20 /* internal system error */
#define NODEUPDOWN_ERR_ERRNUMRANGE       21 /* error number out of range */ 

#define NODEUPDOWN_TIMEOUT_LEN           60

typedef struct nodeupdown *nodeupdown_t;

/* nodeupdown_handle_create
 * - create a nodeupdown handle
 * - returns handle on success, NULL on error
 */
nodeupdown_t nodeupdown_handle_create(void);

/* nodeupdown_handle_destroy
 * - destroy a nodeupdown handle
 * - returns 0 on success, -1 on error
 */
int nodeupdown_handle_destroy(nodeupdown_t handle);

/* nodeupdown_load_data
 * - loads data from genders and ganglia
 * - if filename is null, default genders filename is used.
 * - user may pass in hostname, or IP address (presentable format), or both.  
 * - if both hostname and IP are passed in, IP address is used.
 * - if hostname and IP address is NULL, default IP is used.
 * - if 0 or -1 is passed in for port, default port is used
 * - if timeout_len is 0 or -1, default timeout is used
 * - returns 0 on success, -1 on error
 */
int nodeupdown_load_data(nodeupdown_t handle, 
                         char *genders_filename, 
                         char *gmond_hostname, 
                         char *gmond_ip, 
                         int gmond_port,
                         int timeout_len);

/* nodeupdown_errnum
 * - return the most recent error number
 * - returns error number on success
 */
int nodeupdown_errnum(nodeupdown_t handle);

/* nodeupdown_strerror
 * - return a string message describing an error number
 * - returns pointer to message on success
 */
char *nodeupdown_strerror(int errnum);

/* nodeupdown_errormsg
 * - return a string message describing the most recently
 *   occurred error
 * - returns pointer to message on success
 */
char *nodeupdown_errormsg(nodeupdown_t handle);

/* nodeupdown_perror
 * - output a message to standard error 
 */
void nodeupdown_perror(nodeupdown_t handle, char *msg);

/* nodeupdown_dump
 * - output contents stored in the handle
 * - returns 0 on success, -1 on error
 */
int nodeupdown_dump(nodeupdown_t handle, FILE *stream);

/* nodeupdown_get_up_nodes_string
 * - retrieve a ranged string of up nodes
 * - buffer space assumed to be preallocated with length buflen
 * - returns 0 on success, -1 on error
 */
int nodeupdown_get_up_nodes_string(nodeupdown_t handle, 
                                   char *buf, 
                                   int buflen);

/* nodeupdown_get_down_nodes_string
 * - retrieve a ranged string of down nodes
 * - buffer space assumed to be preallocated with length buflen
 * - returns 0 on success, -1 on error
 */
int nodeupdown_get_down_nodes_string(nodeupdown_t handle, 
                                     char *buf, 
                                     int buflen);

/* nodeupdown_get_up_nodes_list
 * - retrieve a list of up nodes
 * - list assumed to be preallocated with len elements
 * - returns number of nodes copied on success, -1 on error
 */
int nodeupdown_get_up_nodes_list(nodeupdown_t handle, 
                                 char **list, 
                                 int len);

/* nodeupdown_get_down_nodes_list
 * - retrieve a list of down nodes
 * - list assumed to be preallocated with len elements
 * - returns number of nodes copied on success, -1 on error
 */
int nodeupdown_get_down_nodes_list(nodeupdown_t handle, 
                                   char **list, 
                                   int len);

/* nodeupdown_is_node_up
 * - check if a node is up
 * - node must be shortened name of hostname
 * - returns 1 if up, 0 if down, -1 on error
 */
int nodeupdown_is_node_up(nodeupdown_t handle, char *node);

/* nodeupdown_is_node_down
 * - check if a node is down
 * - node must be shortened name of hostname
 * - returns 1 if down, 0 if up, -1 on error
 */
int nodeupdown_is_node_down(nodeupdown_t handle, char *node);

/* nodeupdown_nodelist_create
 * - allocate an array to store node names in
 * - returns number of node entries created on success, -1 on error
 */
int nodeupdown_nodelist_create(nodeupdown_t handle, char ***list);

/* nodeupdown_nodelist_clear
 * - clear a previously allocated nodelist
 * - returns 0 on success, -1 on error
 */
int nodeupdown_nodelist_clear(nodeupdown_t handle, char **list);

/* nodeupdown_nodelist_destroy
 * - destroy the previously allocated nodelist
 * - returns 0 on success, -1 on error
 */
int nodeupdown_nodelist_destroy(nodeupdown_t handle, char **list);

#endif /* _NODEUPDOWN_H */ 
