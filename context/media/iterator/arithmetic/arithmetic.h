/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef CONTEXT_ITERATOR_ARITHMETIC_H
#define CONTEXT_ITERATOR_ARITHMETIC_H

#include<stddef.h>

#include"../componentwise/componentwise.h"

/*
	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
*/

namespace nik
{
	namespace context
	{
		namespace iterator
		{
			template<typename size_type>
			struct arithmetic
			{
				typedef forward::componentwise forward;
				typedef backward::componentwise backward;
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	This could be buggy because of out-1. Probably need to change.
*/
				template<typename OutputIterator>
				static void left_shift_assign(OutputIterator out, size_type length, size_type in)
				{
					size_type last(length-1), diff(last-in);
					backward::assign<void>(out+last, out+diff, out-1);
					forward::repeat(out, out+in, 0);
				}

/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
*/
				template<typename OutputIterator>
				static void right_shift_assign(OutputIterator out, size_type length, size_type in)
				{
					size_type last(length-1), diff(last-in);
					forward::assign<void>(out, out+in, out+length);
					backward::repeat(out+last, out+diff, 0);
				}
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/

				template<size_type N, typename Filler=void>
				struct unroll
				{
/*
	Assumes ascending order.
*/
					template<typename Iterator>
					static bool equal(Iterator in1, Iterator in2)
						{ return (*in1 == *in2) && unroll<N-1>::equal(++in1, ++in2); }
/*
	Assumes ascending order.
*/
					template<typename Iterator>
					static bool not_equal(Iterator in1, Iterator in2)
						{ return (*in1 != *in2) || unroll<N-1>::not_equal(++in1, ++in2); }
/*
	Assumes descending order.
*/
					template<typename Iterator>
					static bool less_than(Iterator in1, Iterator in2)
					{
						if (*in1 != *in2) return (*in1 < *in2);
						else return unroll<N-1>::less_than(--in1, --in2);
					}
/*
	Assumes descending order.
*/
					template<typename Iterator>
					static bool less_than_or_equal(Iterator in1, Iterator in2)
					{
						if (*in1 != *in2) return (*in1 < *in2);
						else return unroll<N-1>::less_than_or_equal(--in1, --in2);
					}
/*
	Assumes descending order.
*/
					template<typename Iterator>
					static bool greater_than(Iterator in1, Iterator in2)
					{
						if (*in1 != *in2) return (*in1 > *in2);
						else return unroll<N-1>::greater_than(--in1, --in2);
					}
/*
	Assumes descending order.
*/
					template<typename Iterator>
					static bool greater_than_or_equal(Iterator in1, Iterator in2)
					{
						if (*in1 != *in2) return (*in1 > *in2);
						else return unroll<N-1>::greater_than_or_equal(--in1, --in2);
					}
/*
	Assumes ascending order.
*/
					template<typename OutputIterator, typename InputIterator>
					static void copy(OutputIterator out, InputIterator in)
					{
						*out=*in;
						unroll<N-1>::copy(++out, ++in);
					}
/*
	Assumes ascending order.
*/
					template<typename Iterator, typename ValueType>
					static void assign(Iterator out, ValueType in)
					{
						*out=in;
						unroll<N-1>::assign(++out, in);
					}
/*
	Assumes ascending order.
*/
					template<typename Iterator, typename ValueType>
					static Iterator rep(Iterator out, ValueType in)
					{
						*out=in;
						return unroll<N-1>::rep(++out, in);
					}
/*
	Assumes ascending order.

	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
					{
						*out=*in1 + *in2 + carry;
						unroll<N-1>::plus(++out, ++in1, ++in2, (*out < *in2));
					}

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
					{
						*out+=*in + carry;
						unroll<N-1>::plus_assign(++out, ++in, (*out < *in));
					}
/*
	Assumes ascending order.

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void minus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
					{
						*out=*in1 - *in2 - carry;
						unroll<N-1>::minus(++out, ++in1, ++in2, (*out > *in2));
					} out+in2+carry=in1	in1 < out, in1 < in2
*/
/*
	Assumes ascending order.

	Obfuscated code ?
*/
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
						{ unroll<N-1>::scale(++out, ++in1, in2, times(*out=carry, *in1, in2)); }

					template<size_type M, typename SubFiller=void>
					struct subroll
					{
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
*/
						template<typename OutputIterator, typename ValueType>
						static void left_shift_assign(OutputIterator out)
						{
							unroll<N-M>::backcopy(out+(N-1), out+(M-1));
							unroll<M>::assign(out, 0);
						}
/*
	Does not assume anything about the existing value of out1.
*/
						template<typename OutputIterator, typename InputIterator>
						static void asterisk(OutputIterator out1,
							OutputIterator out2, InputIterator in1, InputIterator in2)
						{
							unroll<M>::scale(unroll<N-M>::rep(out2, 0), in1, *in2, (size_type) 0);
							plus_assign(out1, out2, 0);
							subroll<M-1>::asterisk(out1, out2, in1, ++in2);
						}
					};

					template<typename SubFiller>
					struct subroll<1, SubFiller>
					{
						template<typename OutputIterator, typename ValueType>
						static void left_shift_assign(OutputIterator out)
						{
							unroll<N-1>::backcopy(out+(N-1), out);
							unroll<1>::assign(out, 0);
						}
		
						template<typename OutputIterator, typename InputIterator>
						static void asterisk(OutputIterator out1,
							OutputIterator out2, InputIterator in1, InputIterator in2)
						{
							unroll<1>::scale(unroll<N-1>::rep(out2, 0), in1, *in2, (size_type) 0);
							plus_assign(out1, out2, 0);
						}
					};
				};

				template<typename Filler>
				struct unroll<1, Filler>
				{
					template<typename Iterator>
					static bool equal(Iterator in1, Iterator in2) { return (*in1 == *in2); }
					template<typename Iterator>
					static bool not_equal(Iterator in1, Iterator in2) { return (*in1 != *in2); }

					template<typename Iterator>
					static bool less_than(Iterator in1, Iterator in2) { return (*in1 < *in2); }
					template<typename Iterator>
					static bool less_than_or_equal(Iterator in1, Iterator in2) { return (*in1 <= *in2); }
					template<typename Iterator>
					static bool greater_than(Iterator in1, Iterator in2) { return (*in1 > *in2); }
					template<typename Iterator>
					static bool greater_than_or_equal(Iterator in1, Iterator in2) { return (*in1 >= *in2); }

					template<typename OutputIterator, typename InputIterator>
					static void copy(OutputIterator out, InputIterator in) { *out=*in; }
					template<typename Iterator, typename ValueType>
					static void assign(Iterator out, ValueType in) { *out=in; }
					template<typename Iterator, typename ValueType>
					static Iterator rep(Iterator out, ValueType in) { *out=in; return ++out; }

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
						{ *out=*in1 + *in2 + carry; }

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
						{ *out+=*in + carry; }
/*
	Obfuscated code ?
*/
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
						{ times(*out=carry, *in1, in2); }
				};

				template<typename Filler>
				struct unroll<0, Filler>
				{
					template<typename Iterator, typename ValueType>
					static Iterator rep(Iterator out, ValueType in) { return out; }
				};
			};
		}
	}
}

#endif