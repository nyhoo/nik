/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik.
**
** nik is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** nik is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik. If not, see
** <http://www.gnu.org/licenses/>.
**
*************************************************************************************************************************/

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
	It is meant to be bootstrapped with a given macro interpretation.
*/


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_return(										\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			delete_policy, count_policy)							\
													\
	declare_loop											\
	(												\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			delete_policy, count_policy, apply_return					\
	)												\
													\
	declare_loop											\
	(												\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			delete_policy, count_policy, omit_return					\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_count_return(									\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			delete_policy)									\
													\
	declare_loop_return										\
	(												\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			delete_policy, omit_count 							\
	)												\
													\
	declare_loop_return										\
	(												\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			delete_policy, apply_count							\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_delete_count_return(								\
			out_interval, out_direction,							\
			in_interval, in_direction)							\
													\
	declare_loop_count_return									\
	(												\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			omit_delete									\
	)												\
													\
	declare_loop_count_return									\
	(												\
			out_interval, out_direction,							\
			in_interval, in_direction,							\
			apply_delete									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_in_direction_delete_count_return(							\
			out_interval, out_direction,							\
			in_interval)									\
													\
	declare_loop_delete_count_return								\
	(												\
			out_interval, out_direction,							\
			in_interval, in_as_forward							\
	)												\
													\
	declare_loop_delete_count_return								\
	(												\
			out_interval, out_direction,							\
			in_interval, in_as_backward							\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_in_interval_in_direction_delete_count_return(					\
			out_interval, out_direction)							\
													\
	declare_loop_in_direction_delete_count_return							\
	(												\
			out_interval, out_direction,							\
			in_as_closing									\
	)												\
													\
	declare_loop_in_direction_delete_count_return							\
	(												\
			out_interval, out_direction,							\
			in_as_closed									\
	)												\
													\
	declare_loop_in_direction_delete_count_return							\
	(												\
			out_interval, out_direction,							\
			in_as_opening									\
	)												\
													\
	declare_loop_in_direction_delete_count_return							\
	(												\
			out_interval, out_direction,							\
			in_as_open									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_out_direction_in_interval_in_direction_delete_count_return(			\
			out_interval)									\
													\
	declare_loop_in_interval_in_direction_delete_count_return					\
	(												\
			out_interval, out_as_forward							\
	)												\
													\
	declare_loop_in_interval_in_direction_delete_count_return					\
	(												\
			out_interval, out_as_backward							\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_out_interval_out_direction_in_interval_in_direction_delete_count_return()		\
													\
	declare_loop_out_direction_in_interval_in_direction_delete_count_return				\
	(												\
			out_as_closing									\
	)												\
													\
	declare_loop_out_direction_in_interval_in_direction_delete_count_return				\
	(												\
			out_as_closed									\
	)												\
													\
	declare_loop_out_direction_in_interval_in_direction_delete_count_return				\
	(												\
			out_as_opening									\
	)												\
													\
	declare_loop_out_direction_in_interval_in_direction_delete_count_return				\
	(												\
			out_as_open									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


declare_loop_out_interval_out_direction_in_interval_in_direction_delete_count_return()

