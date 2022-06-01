/* file      : odb/mysql/details/config.h.in
 * copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
 * license   : GNU GPL v2; see accompanying LICENSE file
 */

/* This file is automatically processed by configure. */

#ifndef ODB_MYSQL_DETAILS_CONFIG_H
#define ODB_MYSQL_DETAILS_CONFIG_H

#undef LIBODB_MYSQL_STATIC_LIB

#define LIBODB_MYSQL_DYNAMIC_LIB
#define DLL_EXPORT
#ifdef WIN32
#define LIBODB_MYSQL_INCLUDE_SHORT
#undef LIBODB_MYSQL_INCLUDE_LONG
#else
#define LIBODB_MYSQL_INCLUDE_LONG
#undef LIBODB_MYSQL_INCLUDE_SHORT
#endif

#undef LIBODB_MYSQL_THR_KEY_VISIBLE

#endif /* ODB_MYSQL_DETAILS_CONFIG_H */
