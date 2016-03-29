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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_OVERLOAD_MACRO_POST_TEST_DEFINE_LOOP_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_OVERLOAD_MACRO_POST_TEST_DEFINE_LOOP_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.
*/

#define post_test_loop_no_return_0(dir, op) \
template<typename RWIterator, typename EIterator, typename ValueType> \
static void no_return(RWIterator out, EIterator end, ValueType in) \
{ \
	do \
	{ \
		dir##dir(out); \
		(*out)op(in); \
	} \
	while (out != end); \
}

#define post_test_loop_with_return_0(dir, op) \
template<typename RWIterator, typename EIterator, typename ValueType> \
static RWIterator with_return(RWIterator out, EIterator end, ValueType in) \
{ \
	do \
	{ \
		dir##dir(out); \
		(*out)op(in); \
	} \
	while (out != end); \
 \
	return out; \
}

#define post_test_loop_no_return_left_0(dir, op) \
template<typename RWIterator, typename EIterator> \
static void no_return(RWIterator out, EIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		op(*out); \
	} \
	while (out != end); \
}

#define post_test_loop_with_return_left_0(dir, op) \
template<typename RWIterator, typename EIterator> \
static RWIterator with_return(RWIterator out, EIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		op(*out); \
	} \
	while (out != end); \
 \
	return out; \
}

#define post_test_loop_no_return_right_0(dir, op) \
template<typename RWIterator, typename EIterator> \
static void no_return(RWIterator out, EIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		(*out)op; \
	} \
	while (out != end); \
}

#define post_test_loop_with_return_right_0(dir, op) \
template<typename RWIterator, typename EIterator> \
static RWIterator with_return(RWIterator out, EIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		(*out)op; \
	} \
	while (out != end); \
 \
	return out; \
}

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with RWIterator as reference (assuming referencing is preferred).
*/
#define post_test_loop_no_return_1(dir, op) \
template<typename RWIterator, typename RIterator, typename ERIterator> \
static void no_return(RWIterator out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in); \
		(*out)op(*in); \
	} \
	while (in != end); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define post_test_loop_with_return_1(dir, op) \
template<typename RWIterator, typename RIterator, typename ERIterator> \
static RWIterator with_return(RWIterator out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in); \
		(*out)op(*in); \
	} \
	while (in != end); \
 \
	return out; \
}

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with RWIterator as reference (assuming referencing is preferred).
*/
#define post_test_loop_no_return_right_1(dir, op, r) \
template<typename RWIterator, typename RIterator, typename ERIterator> \
static void no_return(RWIterator out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in); \
		(*out)op(*in)r; \
	} \
	while (in != end); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define post_test_loop_with_return_right_1(dir, op, r) \
template<typename RWIterator, typename RIterator, typename ERIterator> \
static RWIterator with_return(RWIterator out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in); \
		*(out)op(*in)r; \
	} \
	while (in != end); \
 \
	return out; \
}

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with RWIterator as reference (assuming referencing is preferred).
*/
#define post_test_loop_no_return_2(dir, op) \
template<typename RWIterator, typename RIterator1, typename RIterator2, typename ERIterator> \
static void no_return(RWIterator out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in1); dir##dir(in2); \
		(*out)=(*in1)op(*in2); \
	} \
	while (in2 != end2); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define post_test_loop_with_return_2(dir, op) \
template<typename RWIterator, typename RIterator1, typename RIterator2, typename ERIterator> \
static RWIterator with_return(RWIterator out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in1); dir##dir(in2); \
		(*out)=(*in1)op(*in2); \
	} \
	while (in2 != end2); \
 \
	return out; \
}

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with RWIterator as reference (assuming referencing is preferred).
*/
#define post_test_loop_no_return_bracket_2(dir, op) \
template<typename RWIterator, typename RIterator1, typename RIterator2, typename ERIterator> \
static void no_return(RWIterator out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in1); dir##dir(in2); \
		(*out)=(*in1)op[*in2]; \
	} \
	while (in2 != end2); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define post_test_loop_with_return_bracket_2(dir, op) \
template<typename RWIterator, typename RIterator1, typename RIterator2, typename ERIterator> \
static RWIterator with_return(RWIterator out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		dir##dir(out); dir##dir(in1); dir##dir(in2); \
		(*out)=(*in1)op[*in2]; \
	} \
	while (in2 != end2); \
 \
	return out; \
}

/************************************************************************************************************************/

#define post_test_loop_no_return_new_0(dir) \
template<typename Pointer, typename WIterator, typename EWIterator> \
static void no_return(WIterator out, EWIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		*out=new Pointer(); \
	} \
	while (out != end); \
}

#define post_test_loop_with_return_new_0(dir) \
template<typename Pointer, typename WIterator, typename EWIterator> \
static WIterator with_return(WIterator out, EWIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		*out=new Pointer(); \
	} \
	while (out != end); \
 \
	return out; \
}

#define post_test_loop_no_return_delete_0(dir) \
template<typename WIterator, typename EWIterator> \
static void no_return(WIterator out, EWIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		delete *out; \
	} \
	while (out != end); \
}

#define post_test_loop_with_return_delete_0(dir) \
template<typename WIterator, typename EWIterator> \
static WIterator with_return(WIterator out, EWIterator end) \
{ \
	do \
	{ \
		dir##dir(out); \
		delete *out; \
	} \
	while (out != end); \
 \
	return out; \
}

#endif