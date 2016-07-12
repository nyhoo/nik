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

/*
	The main design point when it comes to conversions is that the context is preserved/modified, and only
	the filler end points are gained or lost:

	[x, y) --> [x, y-1]
	[x, y) --> (x-1, y-1]
	[x, y) --> (x-1, y)
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/////// out_as_nullary, in_as_unary


// parentheses


#define function_type_deny_count_out_as_nullary_in_as_unary_parentheses(rtn, label)					\
															\
	template<typename WPointer, typename EWPointer>									\
	static rtn label##_return(WPointer in, EWPointer end)


		#define function_type_deny_return_deny_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_deny_count_out_as_nullary_in_as_unary_parentheses(void, no)

		#define function_type_allow_return_deny_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_deny_count_out_as_nullary_in_as_unary_parentheses(WPointer, with)

#define function_type_allow_count_out_as_nullary_in_as_unary_parentheses(rtn, label)					\
															\
	template<typename WPointer, typename EWPointer>									\
	static rtn label##_return(size_type & count, WPointer in, EWPointer end)


		#define function_type_deny_return_allow_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_allow_count_out_as_nullary_in_as_unary_parentheses(void, no)

		#define function_type_allow_return_allow_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_allow_count_out_as_nullary_in_as_unary_parentheses(WPointer, with)


/////// out_as_unary, in_as_nullary


// parentheses


#define function_type_deny_count_out_as_unary_in_as_nullary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename ValueType>							\
	static rtn label##_return(WPointer out, size_type n, ValueType value)


		#define function_type_deny_return_deny_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_deny_count_out_as_unary_in_as_nullary_parentheses(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_deny_count_out_as_unary_in_as_nullary_parentheses(WPointer, with)

#define function_type_allow_count_out_as_unary_in_as_nullary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename ValueType>							\
	static rtn label##_return(size_type & count, WPointer out, size_type n, ValueType value)


		#define function_type_deny_return_allow_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_allow_count_out_as_unary_in_as_nullary_parentheses(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_allow_count_out_as_unary_in_as_nullary_parentheses(WPointer, with)


// parentheses_new


#define function_type_deny_count_out_as_unary_in_as_nullary_parentheses_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(WPointer out, size_type n)


		#define function_type_deny_return_deny_count_out_as_unary_in_as_nullary_parentheses_new()		\
			function_type_deny_count_out_as_unary_in_as_nullary_parentheses_new(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_nullary_parentheses_new()		\
			function_type_deny_count_out_as_unary_in_as_nullary_parentheses_new(WPointer, with)

#define function_type_allow_count_out_as_unary_in_as_nullary_parentheses_new(rtn, label)				\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(size_type & count, WPointer out, size_type n)


		#define function_type_deny_return_allow_count_out_as_unary_in_as_nullary_parentheses_new()		\
			function_type_allow_count_out_as_unary_in_as_nullary_parentheses_new(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_nullary_parentheses_new()		\
			function_type_allow_count_out_as_unary_in_as_nullary_parentheses_new(WPointer, with)


// brackets_new


#define function_type_deny_count_out_as_unary_in_as_nullary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(WPointer out, size_type n, size_type in)


		#define function_type_deny_return_deny_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_deny_count_out_as_unary_in_as_nullary_brackets_new(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_deny_count_out_as_unary_in_as_nullary_brackets_new(WPointer, with)

#define function_type_allow_count_out_as_unary_in_as_nullary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(size_type & count, WPointer out, size_type n, size_type in)


		#define function_type_deny_return_allow_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_allow_count_out_as_unary_in_as_nullary_brackets_new(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_nullary_brackets_new()		\
			function_type_allow_count_out_as_unary_in_as_nullary_brackets_new(WPointer, with)


/////// out_as_unary, in_as_unary


// parentheses


#define function_type_deny_count_out_as_unary_in_as_unary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>				\
	static rtn label##_return(WPointer out, RIterator in, ERIterator end)


		#define function_type_deny_return_deny_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_deny_count_out_as_unary_in_as_unary_parentheses(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_deny_count_out_as_unary_in_as_unary_parentheses(WPointer, with)

#define function_type_allow_count_out_as_unary_in_as_unary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>				\
	static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end)


		#define function_type_deny_return_allow_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_allow_count_out_as_unary_in_as_unary_parentheses(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_allow_count_out_as_unary_in_as_unary_parentheses(WPointer, with)


// brackets_new


#define function_type_deny_count_out_as_unary_in_as_unary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer, typename RIterator, typename ERIterator>		\
	static rtn label##_return(WPointer out, RIterator in, ERIterator end)


		#define function_type_deny_return_deny_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_deny_count_out_as_unary_in_as_unary_brackets_new(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_deny_count_out_as_unary_in_as_unary_brackets_new(WPointer, with)

#define function_type_allow_count_out_as_unary_in_as_unary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer, typename RIterator, typename ERIterator>		\
	static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end)


		#define function_type_deny_return_allow_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_allow_count_out_as_unary_in_as_unary_brackets_new(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_allow_count_out_as_unary_in_as_unary_brackets_new(WPointer, with)


/////// out_as_unary, in_as_binary


// parentheses


#define function_type_deny_count_out_as_unary_in_as_binary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator>	\
	static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2)


		#define function_type_deny_return_deny_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_deny_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_deny_count_out_as_unary_in_as_binary_parentheses(WPointer, with)

		#define function_type_deny_return_deny_count_out_as_unary_in_as_binary_brackets()			\
			function_type_deny_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_allow_return_deny_count_out_as_unary_in_as_binary_brackets()			\
			function_type_deny_count_out_as_unary_in_as_binary_parentheses(WPointer, with)

#define function_type_allow_count_out_as_unary_in_as_binary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator>	\
	static rtn label##_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2)


		#define function_type_deny_return_allow_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_allow_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_allow_count_out_as_unary_in_as_binary_parentheses(WPointer, with)

		#define function_type_deny_return_allow_count_out_as_unary_in_as_binary_brackets()			\
			function_type_allow_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_allow_return_allow_count_out_as_unary_in_as_binary_brackets()			\
			function_type_allow_count_out_as_unary_in_as_binary_parentheses(WPointer, with)



/************************************************************************************************************************/

/*
	function_type:

*/


#define function_type(return_policy, count_policy, operator_policy) \
	function_type_##return_policy##_##count_policy##_##operator_policy()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	operator_policy:

		out_as_nullary_in_as_unary_parentheses

		out_as_unary_in_as_nullary_parentheses
		out_as_unary_in_as_nullary_parentheses_new
		out_as_unary_in_as_nullary_brackets_new

		out_as_unary_in_as_unary_parentheses
		out_as_unary_in_as_unary_brackets_new

		out_as_unary_in_as_binary_parentheses
		out_as_unary_in_as_binary_brackets
*/


#define out_as_nullary_in_as_unary_parentheses(op_a, op_l, op_r)		op_a op_l (*in) op_r;


//


#define out_as_unary_in_as_nullary_parentheses(op_a, op_l, op_r)		(*out) op_a op_l (value) op_r;


#define out_as_unary_in_as_nullary_parentheses_new(op_a, op_l, op_r)		(*out) op_a op_l () op_r;


#define out_as_unary_in_as_nullary_brackets_new(op_a, op_l, op_r)		(*out) op_a op_l [value] op_r;


//


#define out_as_unary_in_as_unary_parentheses(op_a, op_l, op_r)			(*out) op_a op_l (*in) op_r;


#define out_as_unary_in_as_unary_brackets_new(op_a, op_l, op_r)			(*out) op_a op_l [*in] op_r;


//


#define out_as_unary_in_as_binary_parentheses(op_a, op_l, op_r)			(*out) op_a (*in1) op_l (*in2) op_r;


#define out_as_Unary_in_as_binary_brackets(op_a, op_l, op_r)			(*out) op_a (*in1) op_l [*in2] op_r;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_variables_out_as_forward()


#define declare_variables_out_as_backward()					WPointer current; \


/************************************************************************************************************************/


/*
	out_direction:

		out_as_forward
		out_as_backward
*/


#define declare_variables(out_direction) \
	declare_variables_##out_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	out_direction:

		out_as_forward
		out_as_backward
*/


#define out_direction(dir)							out=dir(out)=new WNode;


	#define out_as_forward()						out_direction(+)


	#define out_as_backward()						current=out; \
										out=new WNode; \
										+out=current;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define in_direction_deny_delete_in_as_unary(dir)				dir##dir(in);


	#define in_as_forward_deny_delete_in_as_unary()				in_direction_deny_delete_in_as_unary(+)
	#define in_as_backward_deny_delete_in_as_unary()			in_direction_deny_delete_in_as_unary(-)


#define in_direction_allow_delete_in_as_unary(dir)				delete (in)dir##dir;


	#define in_as_forward_allow_delete_in_as_unary()			in_direction_allow_delete_in_as_unary(+)
	#define in_as_backward_allow_delete_in_as_unary()			in_direction_allow_delete_in_as_unary(-)


#define in_direction_deny_delete_in_as_binary(dir)				dir##dir(in1); \
										dir##dir(in2);


	#define in_as_forward_deny_delete_in_as_binary()			in_direction_deny_delete_in_as_binary(+)
	#define in_as_backward_deny_delete_in_as_binary()			in_direction_deny_delete_in_as_binary(-)


#define in_direction_allow_delete_in_as_binary(dir)				delete (in1)dir##dir; \
										delete (in2)dir##dir;


	#define in_as_forward_allow_delete_in_as_binary()			in_direction_allow_delete_in_as_binary(+)
	#define in_as_backward_allow_delete_in_as_binary()			in_direction_allow_delete_in_as_binary(-)


/************************************************************************************************************************/


/*
	in_direction:

		in_as_forward
		in_as_backward
*/


#define in_as_forward(delete_policy, in_arity) \
	in_as_forward_##delete_policy##_##in_arity()

#define in_as_backward(delete_policy, in_arity) \
	in_as_backward_##delete_policy##_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define peek_type_unary(dir)							dir(in) != end


	#define no_peek_in_as_unary_in_as_forward()				peek_type_unary( )
	#define no_peek_in_as_unary_in_as_backward()				peek_type_unary( )

	#define with_peek_in_as_unary_in_as_forward()				peek_type_unary(+)
	#define with_peek_in_as_unary_in_as_backward()				peek_type_unary(-)


#define peek_type_binary(dir)							dir(in2) != end2


	#define no_peek_in_as_binary_in_as_forward()				peek_type_binary( )
	#define no_peek_in_as_binary_in_as_backward()				peek_type_binary( )

	#define with_peek_in_as_binary_in_as_forward()				peek_type_binary(+)
	#define with_peek_in_as_binary_in_as_backward()				peek_type_binary(-)


/************************************************************************************************************************/

/*
	peek_type:

		no_peek
		with_peek
*/


#define no_peek(in_arity, in_direction) \
	no_peek_##in_arity##_##in_direction()

#define with_peek(in_arity, in_direction) \
	with_peek_##in_arity##_##in_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define deny_delete_in_as_unary()


#define allow_delete_in_as_unary()						delete in;


#define deny_delete_in_as_binary()


#define allow_delete_in_as_binary()						delete in1; \
										delete in2;


/************************************************************************************************************************/


/*
	delete_policy:

		deny_delete
		allow_delete
*/


#define deny_delete(in_arity) \
	deny_delete_##in_arity()

#define allow_delete(in_arity) \
	allow_delete_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	count_policy:

		deny_count
		allow_count
*/


#define deny_count()


#define allow_count()								++count;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	return_policy:

		deny_return
		allow_return
*/


#define deny_return()


#define allow_return()								return out;
