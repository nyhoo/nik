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
*/

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	As "out" is assign shifted when its "dir(out)" is allocated, there is no need to increment seperately.
*/

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_clear(dir, inv, label, rtn, stmt) \
template<typename WPointer, typename ERPointer> \
static rtn label##_return(size_type & count, WPointer out, ERPointer end) \
{ \
	while (out != end) \
	{ \
		delete (out)dir##dir; \
		++count; \
	} \
 \
	delete (out)dir##dir; \
	++count; \
 \
	stmt \
}

#define closed_count_no_return_clear(dir, inv)				_closed_count_clear(dir, inv, no, void, )
#define closed_count_with_return_clear(dir, inv)			_closed_count_clear(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_close_left(dir, inv, label, rtn, stmt)

#define closed_count_no_return_close_left(dir, inv)			_closed_count_close_left(dir, inv, no, void, )
#define closed_count_with_return_close_left(dir, inv)			_closed_count_close_left(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_close_right(dir, inv, label, rtn, stmt)

#define closed_count_no_return_close_right(dir, inv)			_closed_count_close_right(dir, inv, no, void, )
#define closed_count_with_return_close_right(dir, inv)			_closed_count_close_right(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_open_left(dir, inv, label, rtn, stmt)

#define closed_count_no_return_open_left(dir, inv)			_closed_count_open_left(dir, inv, no, void, )
#define closed_count_with_return_open_left(dir, inv)			_closed_count_open_left(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_open_right(dir, inv, label, rtn, stmt)

#define closed_count_no_return_open_right(dir, inv)			_closed_count_open_right(dir, inv, no, void, )
#define closed_count_with_return_open_right(dir, inv)			_closed_count_open_right(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_assign_as_closing(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	out=zip::assign::closed::count::template with_return<WNode>(count, out, in, end); \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_count_no_return_assign_as_closing(dir, inv)		_closed_count_assign_as_closing(dir, inv, no, void, )
#define closed_count_with_return_assign_as_closing(dir, inv)		_closed_count_assign_as_closing(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_assign_as_closed(dir, inv, label, rtn, stmt)

#define closed_count_no_return_assign_as_closed(dir, inv)		_closed_count_assign_as_closed(dir, inv, no, void, )
#define closed_count_with_return_assign_as_closed(dir, inv)		_closed_count_assign_as_closed(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_assign_as_opening(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		*out=*in; \
		dir##dir(in); \
		++count; \
	} \
 \
	out=dir(out)=new WNode; \
	*out=*in; \
	++count; \
 \
	stmt \
}

#define closed_count_no_return_assign_as_opening(dir, inv)		_closed_count_assign_as_opening(dir, inv, no, void, )
#define closed_count_with_return_assign_as_opening(dir, inv)		_closed_count_assign_as_opening(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_assign_as_open(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		*out=*in; \
		dir##dir(in); \
		++count; \
	} \
 \
	out=dir(out)=new WNode; \
	*out=*in; \
	++count; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_count_no_return_assign_as_open(dir, inv)			_closed_count_assign_as_open(dir, inv, no, void, )
#define closed_count_with_return_assign_as_open(dir, inv)		_closed_count_assign_as_open(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_catenate_with_closing(dir, inv, label, rtn, stmt)

#define closed_count_no_return_catenate_with_closing(dir, inv)		_closed_count_catenate_with_closing(dir, inv, no, void, )
#define closed_count_with_return_catenate_with_closing(dir, inv)	_closed_count_catenate_with_closing(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_catenate_with_closed(dir, inv, label, rtn, stmt)

#define closed_count_no_return_catenate_with_closed(dir, inv)		_closed_count_catenate_with_closed(dir, inv, no, void, )
#define closed_count_with_return_catenate_with_closed(dir, inv)		_closed_count_catenate_with_closed(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_catenate_with_opening(dir, inv, label, rtn, stmt)

#define closed_count_no_return_catenate_with_opening(dir, inv)		_closed_count_catenate_with_opening(dir, inv, no, void, )
#define closed_count_with_return_catenate_with_opening(dir, inv)	_closed_count_catenate_with_opening(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_count_catenate_with_open(dir, inv, label, rtn, stmt)

#define closed_count_no_return_catenate_with_open(dir, inv)		_closed_count_catenate_with_open(dir, inv, no, void, )
#define closed_count_with_return_catenate_with_open(dir, inv)		_closed_count_catenate_with_open(dir, inv, with, WPointer, return out;)

