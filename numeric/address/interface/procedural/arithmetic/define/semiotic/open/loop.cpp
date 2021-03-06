/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
************************************************************************************************************************/

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

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_zero(dir, inv, label, rtn, stmt)

#define open_loop_no_break_zero(dir, inv)				_open_loop_zero(dir, inv, no, void, )
#define open_loop_with_break_zero(dir, inv)				_open_loop_zero(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_zero_fast(dir, inv, label, rtn, stmt)

#define open_loop_no_break_zero_fast(dir, inv)				_open_loop_zero_fast(dir, inv, no, void, )
#define open_loop_with_break_zero_fast(dir, inv)			_open_loop_zero_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_equal(dir, inv, label, rtn, stmt)

#define open_loop_no_break_equal(dir, inv)				_open_loop_equal(dir, inv, no, void, )
#define open_loop_with_break_equal(dir, inv)				_open_loop_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_equal_fast(dir, inv, label, rtn, stmt)

#define open_loop_no_break_equal_fast(dir, inv)				_open_loop_equal_fast(dir, inv, no, void, )
#define open_loop_with_break_equal_fast(dir, inv)			_open_loop_equal_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_not_equal(dir, inv, label, rtn, stmt)

#define open_loop_no_break_not_equal(dir, inv)				_open_loop_not_equal(dir, inv, no, void, )
#define open_loop_with_break_not_equal(dir, inv)			_open_loop_not_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_not_equal_fast(dir, inv, label, rtn, stmt)

#define open_loop_no_break_not_equal_fast(dir, inv)			_open_loop_not_equal_fast(dir, inv, no, void, )
#define open_loop_with_break_not_equal_fast(dir, inv)			_open_loop_not_equal_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_less_than(dir, inv, label, rtn, stmt)

#define open_loop_no_return_less_than(dir, inv)				_open_loop_less_than(dir, inv, no, void, )
#define open_loop_with_return_less_than(dir, inv)			_open_loop_less_than(dir, inv, with, WPointer, return out;)
#define open_loop_fast_return_less_than(dir, inv)			_open_loop_less_than(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_less_than_or_equal(dir, inv, label, rtn, stmt)

#define open_loop_no_return_less_than_or_equal(dir, inv)		_open_loop_less_than_or_equal(dir, inv, no, void, )
#define open_loop_with_return_less_than_or_equal(dir, inv)		_open_loop_less_than_or_equal(dir, inv, with, WPointer, return out;)
#define open_loop_fast_return_less_than_or_equal(dir, inv)		_open_loop_less_than_or_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_greater_than(dir, inv, label, rtn, stmt)

#define open_loop_no_return_greater_than(dir, inv)			_open_loop_greater_than(dir, inv, no, void, )
#define open_loop_with_return_greater_than(dir, inv)			_open_loop_greater_than(dir, inv, with, WPointer, return out;)
#define open_loop_fast_return_greater_than(dir, inv)			_open_loop_greater_than(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_greater_than_or_equal(dir, inv, label, rtn, stmt)

#define open_loop_no_return_greater_than_or_equal(dir, inv)		_open_loop_greater_than_or_equal(dir, inv, no, void, )
#define open_loop_with_return_greater_than_or_equal(dir, inv)		_open_loop_greater_than_or_equal(dir, inv, with, WPointer, return out;)
#define open_loop_fast_return_greater_than_or_equal(dir, inv)		_open_loop_greater_than_or_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_plus(dir, inv, label, rtn, stmt)

#define open_loop_no_return_plus(dir, inv)				_open_loop_plus(dir, inv, no, void, )
#define open_loop_with_return_plus(dir, inv)				_open_loop_plus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_plus_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_plus_half(dir, inv)				_open_loop_plus_half(dir, inv, no, void, )
#define open_loop_with_return_plus_half(dir, inv)			_open_loop_plus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_minus(dir, inv, label, rtn, stmt)

#define open_loop_no_return_minus(dir, inv)				_open_loop_minus(dir, inv, no, void, )
#define open_loop_with_return_minus(dir, inv)				_open_loop_minus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_minus_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_minus_half(dir, inv)			_open_loop_minus_half(dir, inv, no, void, )
#define open_loop_with_return_minus_half(dir, inv)			_open_loop_minus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_scale(dir, inv, label, rtn, stmt)

#define open_loop_no_return_scale(dir, inv)				_open_loop_scale(dir, inv, no, void, )
#define open_loop_with_return_scale(dir, inv)				_open_loop_scale(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_scale_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_scale_half(dir, inv)			_open_loop_scale_half(dir, inv, no, void, )
#define open_loop_with_return_scale_half(dir, inv)			_open_loop_scale_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_multiply(dir, inv, label, rtn, stmt)

#define open_loop_no_return_multiply(dir, inv)				_open_loop_multiply(dir, inv, no, void, )
#define open_loop_with_return_multiply(dir, inv)			_open_loop_multiply(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_multiply_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_multiply_half(dir, inv)			_open_loop_multiply_half(dir, inv, no, void, )
#define open_loop_with_return_multiply_half(dir, inv)			_open_loop_multiply_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_divide(dir, inv, label, rtn, stmt)

#define open_loop_no_return_divide(dir, inv)				_open_loop_divide(dir, inv, no, void, )
#define open_loop_with_return_divide(dir, inv)				_open_loop_divide(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_divide_half_digit(dir, inv, label, rtn, stmt)

#define open_loop_no_return_divide_half_digit(dir, inv)			_open_loop_divide_half_digit(dir, inv, no, void, )
#define open_loop_with_return_divide_half_digit(dir, inv)		_open_loop_divide_half_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_divide_single_digit(dir, inv, label, rtn, stmt)

#define open_loop_no_return_divide_single_digit(dir, inv)		_open_loop_divide_single_digit(dir, inv, no, void, )
#define open_loop_with_return_divide_single_digit(dir, inv)		_open_loop_divide_single_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_divide_single_digit_half(dir, inv)		_open_loop_divide_single_digit_half(dir, inv, no, void, )
#define open_loop_with_return_divide_single_digit_half(dir, inv)	_open_loop_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_radix(dir, inv, label, rtn, stmt)

#define open_loop_no_return_radix(dir, inv)				_open_loop_radix(dir, inv, no, void, )
#define open_loop_with_return_radix(dir, inv)			_open_loop_radix(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_radix_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_radix_half(dir, inv)			_open_loop_radix_half(dir, inv, no, void, )
#define open_loop_with_return_radix_half(dir, inv)			_open_loop_radix_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_plus(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_plus(dir, inv)			_open_loop_assign_plus(dir, inv, no, void, )
#define open_loop_with_return_assign_plus(dir, inv)			_open_loop_assign_plus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_plus_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_plus_half(dir, inv)			_open_loop_assign_plus_half(dir, inv, no, void, )
#define open_loop_with_return_assign_plus_half(dir, inv)		_open_loop_assign_plus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_minus(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_minus(dir, inv)			_open_loop_assign_minus(dir, inv, no, void, )
#define open_loop_with_return_assign_minus(dir, inv)			_open_loop_assign_minus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_minus_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_minus_half(dir, inv)			_open_loop_assign_minus_half(dir, inv, no, void, )
#define open_loop_with_return_assign_minus_half(dir, inv)		_open_loop_assign_minus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_scale(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_scale(dir, inv)			_open_loop_assign_scale(dir, inv, no, void, )
#define open_loop_with_return_assign_scale(dir, inv)			_open_loop_assign_scale(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_scale_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_scale_half(dir, inv)			_open_loop_assign_scale_half(dir, inv, no, void, )
#define open_loop_with_return_assign_scale_half(dir, inv)		_open_loop_assign_scale_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_multiply(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_multiply(dir, inv)			_open_loop_assign_multiply(dir, inv, no, void, )
#define open_loop_with_return_assign_multiply(dir, inv)			_open_loop_assign_multiply(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_multiply_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_multiply_half(dir, inv)		_open_loop_assign_multiply_half(dir, inv, no, void, )
#define open_loop_with_return_assign_multiply_half(dir, inv)		_open_loop_assign_multiply_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_divide(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_divide(dir, inv)			_open_loop_assign_divide(dir, inv, no, void, )
#define open_loop_with_return_assign_divide(dir, inv)			_open_loop_assign_divide(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_divide_half_digit(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_divide_half_digit(dir, inv)		_open_loop_assign_divide_half_digit(dir, inv, no, void, )
#define open_loop_with_return_assign_divide_half_digit(dir, inv)	_open_loop_assign_divide_half_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_divide_single_digit(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_divide_single_digit(dir, inv)	_open_loop_assign_divide_single_digit(dir, inv, no, void, )
#define open_loop_with_return_assign_divide_single_digit(dir, inv)	_open_loop_assign_divide_single_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_divide_single_digit_half(dir, inv)	_open_loop_assign_divide_single_digit_half(dir, inv, no, void, )
#define open_loop_with_return_assign_divide_single_digit_half(dir, inv)	_open_loop_assign_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_radix(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_radix(dir, inv)			_open_loop_assign_radix(dir, inv, no, void, )
#define open_loop_with_return_assign_radix(dir, inv)			_open_loop_assign_radix(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _open_loop_assign_radix_half(dir, inv, label, rtn, stmt)

#define open_loop_no_return_assign_radix_half(dir, inv)		_open_loop_assign_radix_half(dir, inv, no, void, )
#define open_loop_with_return_assign_radix_half(dir, inv)		_open_loop_assign_radix_half(dir, inv, with, WPointer, return out;)

