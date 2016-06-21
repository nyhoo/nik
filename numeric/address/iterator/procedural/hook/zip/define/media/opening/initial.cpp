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

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, ValueType in) \
	{ stmt }

#define opening_initial_no_return_0(dir, inv, op)			_opening_initial_0(dir, inv, op, no, void, )
#define opening_initial_with_return_0(dir, inv, op)			_opening_initial_0(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_lr_0(dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
	{ stmt }

#define opening_initial_no_return_left_0(dir, inv, op)			_opening_initial_lr_0(dir, inv, no, void, , op, )
#define opening_initial_with_return_left_0(dir, inv, op)		_opening_initial_lr_0(dir, inv, with, WPointer, return out;, op, )

#define opening_initial_no_return_right_0(dir, inv, op)			_opening_initial_lr_0(dir, inv, no, void, , , op)
#define opening_initial_with_return_right_0(dir, inv, op)		_opening_initial_lr_0(dir, inv, with, WPointer, return out;, , op)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_new_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
	{ stmt }

#define opening_initial_no_return_new_0(dir, inv)			_opening_initial_new_0(dir, inv, no, void, )
#define opening_initial_with_return_new_0(dir, inv)			_opening_initial_new_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_new_brackets_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type in) \
	{ stmt }

#define opening_initial_no_return_new_brackets_0(dir, inv)		_opening_initial_new_brackets_0(dir, inv, no, void, )
#define opening_initial_with_return_new_brackets_0(dir, inv)		_opening_initial_new_brackets_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0], N != 0
*/

#define _opening_initial_delete_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	delete op *out; \
	delete out; \
 \
	stmt \
}

#define opening_initial_no_return_delete_0(dir, inv)			_opening_initial_delete_0(dir, inv, , no, void, )
#define opening_initial_with_return_delete_0(dir, inv)			// would return a deallocated memory location!

#define opening_initial_no_return_delete_brackets_0(dir, inv)		_opening_initial_delete_0(dir, inv, [], no, void, )
#define opening_initial_with_return_delete_brackets_0(dir, inv)		// would return a deallocated memory location!

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_lr_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
	{ stmt }

#define opening_initial_no_return_1(dir, inv, op)			_opening_initial_lr_1(dir, inv, op, no, void, , , )
#define opening_initial_with_return_1(dir, inv, op)			_opening_initial_lr_1(dir, inv, op, with, WPointer, return out;, , )

#define opening_initial_no_return_right_1(dir, inv, op, r)		_opening_initial_lr_1(dir, inv, op, no, void, , , r)
#define opening_initial_with_return_right_1(dir, inv, op, r)		_opening_initial_lr_1(dir, inv, op, with, WPointer, return out;, , r)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_new_brackets_1(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer> \
static rtn label##_return(WPointer out, RPointer in) \
	{ stmt }

#define opening_initial_no_return_new_brackets_1(dir, inv)		_opening_initial_new_brackets_1(dir, inv, no, void, )
#define opening_initial_with_return_new_brackets_1(dir, inv)		_opening_initial_new_brackets_1(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2) \
	{ stmt }

#define opening_initial_no_return_2(dir, inv, op)			_opening_initial_2(dir, inv, op, no, void, )
#define opening_initial_with_return_2(dir, inv, op)			_opening_initial_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	(0, N=0]
*/

#define _opening_initial_brackets_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2) \
	{ stmt }

#define opening_initial_no_return_brackets_2(dir, inv, op)		_opening_initial_brackets_2(dir, inv, op, no, void, )
#define opening_initial_with_return_brackets_2(dir, inv, op)		_opening_initial_brackets_2(dir, inv, op, with, WPointer, return out;)

