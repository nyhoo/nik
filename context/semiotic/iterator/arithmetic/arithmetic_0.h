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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_0_H
#define CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_0_H

#include<stddef.h>

// Clean up the typedefs/usings namespace stuff.

// standardize location of "carry" as parameter (front or end?)

// overhead dependencies:
#include"../../../context/constant.h"

/*
	The main difference between "componentwise" and "arithmetic" from an algorithmic lens is that with componentwise is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

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
  namespace semiotic
  {
   namespace iterator
   {
    namespace forward
    {
	template<typename size_type>
	struct arithmetic_0
	{
		typedef meta::constant<size_type> constant;

		struct zero
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename InputIterator, typename TerminalIterator>
			static bool no_break(bool carry, InputIterator in, TerminalIterator end)
			{
				while (in != end)
				{
					carry=carry && !*in;
					++in;
				}

				return carry;
			}

			template<typename InputIterator, typename TerminalIterator>
			static bool with_break(InputIterator in, TerminalIterator end)
			{
				while (in != end)
				{
					if (*in) return false;
					++in;
				}

				return true;
			}
		};

		struct equal
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry && (*in1 == *in2);
					++in1; ++in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return false;
					++in1; ++in2;
				}

				return true;
			}
		};

		struct not_equal
		{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry || (*in1 != *in2);
					++in1; ++in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return true;
					++in1; ++in2;
				}

				return false;
			}
		};
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
		template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
		static bool less_than(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
		{
			while (in2 != end2)
			{
				if (*in1 < *in2) carry=true;
				else if (*in1 > *in2) carry=false;

				++in1; ++in2;
			}

			return carry;
		}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
		template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
		static bool less_than_or_equal(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
		{
			while (in2 != end2)
			{
				if (*in1 < *in2) carry=true;
				else if (*in1 > *in2) carry=false;

				++in1; ++in2;
			}

			return carry;
		}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
		template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
		static bool greater_than(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
		{
			while (in2 != end2)
			{
				if (*in1 > *in2) carry=true;
				else if (*in1 < *in2) carry=false;

				++in1; ++in2;
			}

			return carry;
		}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
		template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
		static bool greater_than_or_equal(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
		{
			while (in2 != end2)
			{
				if (*in1 > *in2) carry=true;
				else if (*in1 < *in2) carry=false;

				++in1; ++in2;
			}

			return carry;
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
		struct unroll_0
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct zero
			{
				template<typename Iterator>
				static bool no_break(bool carry, Iterator in)
				{
					carry=carry && !*in;
					return unroll_0<N-1>::zero::no_break(carry, ++in);
				}

				template<typename Iterator>
				static bool with_break(Iterator in)
				{
					if (*in) return false;
					else return unroll_0<N-1>::zero::with_break(++in);
				}
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry && (*in1 == *in2);
					return unroll_0<N-1>::equal::no_break(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return false;
					else return unroll_0<N-1>::equal::with_break(++in1, ++in2);
				}
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry || (*in1 != *in2);
					return unroll_0<N-1>::not_equal::no_break(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return true;
					else return unroll_0<N-1>::not_equal::with_break(++in1, ++in2);
				}
			};
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 < *in2) carry=true;
				else if (*in1 > *in2) carry=false;

				return unroll_0<N-1>::less_than(carry, ++in1, ++in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 < *in2) carry=true;
				else if (*in1 > *in2) carry=false;

				return unroll_0<N-1>::less_than_or_equal(carry, ++in1, ++in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 > *in2) carry=true;
				else if (*in1 < *in2) carry=false;

				return unroll_0<N-1>::greater_than(carry, ++in1, ++in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 > *in2) carry=true;
				else if (*in1 < *in2) carry=false;

				return unroll_0<N-1>::greater_than_or_equal(carry, ++in1, ++in2);
			}
/*
			Intuitively, "right_shift" would be defined here,
			but given its implementation it is actually part of componentwise.h
*/
/*
	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
			struct plus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					unroll_0<N-1>::plus::no_return(++out, ++in1, ++in2, (*out < *in2));
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					return unroll_0<N-1>::plus::with_return(++out, ++in1, ++in2, (*out < *in2));
				}
			};
/*
	In this case, *out+(*in2+carry)=*in1 implies a new carry if: *in1 < *out or *in1 < (*in2+carry)
	but there's the special case that (*in2+carry) already wraps around [(*in2+carry) < *in2, carry].
	In which case---given 0 <= carry <= 1---it's automatic that there's a new carry (but no need
	of worry about a "double carry" because (*in2+carry) if wrapped around would equal zero.

	Because use of *in1 can't be avoided in the new carry test, it requires out and in1 cannot be shallow copies.

	The assumption is addition is no less optimal than subtraction as the algorithm
	should require fewer tests, hence: *out=*in1-(*in2+carry) instead of *out=*in1-*in2-carry.

	carry needs to be set to 0 for the "normal" interpretation.
*/
			struct minus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					carry+=*in2;
					*out=*in1 - carry;
					unroll_0<N-1>::minus::no_return(++out, ++in1, ++in2, (carry < *in2 || *in1 < *out));
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					carry+=*in2;
					*out=*in1 - carry;
					return unroll_0<N-1>::minus::with_return(++out, ++in1, ++in2, (carry < *in2 || *in1 < *out));
				}
			};

			struct assign
			{
				struct plus
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void no_return(OutputIterator out, InputIterator in, ValueType carry)
					{
						*out+=*in + carry;
						unroll_0<N-1>::assign::plus::no_return(++out, ++in, (*out < *in));
					}

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static OutputIterator with_return(OutputIterator out, InputIterator in, ValueType carry)
					{
						*out+=*in + carry;
						return unroll_0<N-1>::assign::plus::with_return(++out, ++in, (*out < *in));
					}
				};
/*
	carry1 needs to be set to 0 for the "normal" interpretation.
	carry2 needs to be set to *out for the "normal" interpretation.
*/
				struct minus
				{
					template<typename ValueType, typename OutputIterator, typename InputIterator>
					static void no_return(ValueType carry1, ValueType carry2, OutputIterator out, InputIterator in)
					{
						carry1+=*in;
						*out-=carry1;
						unroll_0<N-1>::assign::minus::template
							no_return<ValueType>((carry1 < *in || carry2 < *out), *out, ++out, ++in);
					}

					template<typename ValueType, typename OutputIterator, typename InputIterator>
					static OutputIterator with_return(ValueType carry1,
						ValueType carry2, OutputIterator out, InputIterator in)
					{
						carry1+=*in;
						*out-=carry1;
						return unroll_0<N-1>::assign::minus::template
							with_return<ValueType>((carry1 < *in || carry2 < *out), *out, ++out, ++in);
					}
				};
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
			struct zero
			{
				template<typename Iterator>
				static bool no_break(bool carry, Iterator in)
					{ return carry; }
				template<typename Iterator>
				static bool with_break(Iterator in)
					{ return true; }
			};

			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }
				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
					{ return true; }
			};

			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
					{ return false; }
			};

			template<typename Iterator1, typename Iterator2>
			static bool less_than(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			template<typename Iterator1, typename Iterator2>
			static bool greater_than(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			struct plus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ return out; }
			};

			struct minus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ return out; }
			};

			struct assign
			{
				struct plus
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void no_return(OutputIterator out, InputIterator in, ValueType carry)
						{ }

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static OutputIterator with_return(OutputIterator out, InputIterator in, ValueType carry)
						{ return out; }
				};

				struct minus
				{
					template<typename ValueType, typename OutputIterator, typename InputIterator>
					static void no_return(ValueType carry1, ValueType carry2, OutputIterator out, InputIterator in)
						{ }

					template<typename ValueType, typename OutputIterator, typename InputIterator>
					static OutputIterator with_return(ValueType carry1,
						ValueType carry2, OutputIterator out, InputIterator in)
							{ return out; }
				};
			};
		};
	};
    }

    namespace backward
    {
	template<typename size_type>
	struct arithmetic_0
	{
		typedef meta::constant<size_type> constant;

		struct zero
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename InputIterator, typename TerminalIterator>
			static bool no_break(bool carry, InputIterator in, TerminalIterator end)
			{
				while (in != end)
				{
					carry=carry && !*in;
					--in;
				}

				return carry;
			}

			template<typename InputIterator, typename TerminalIterator>
			static bool with_break(InputIterator in, TerminalIterator end)
			{
				while (in != end)
				{
					if (*in) return false;
					--in;
				}

				return true;
			}
		};

		struct equal
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry && (*in1 == *in2);
					--in1; --in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return false;
					--in1; --in2;
				}

				return true;
			}
		};

		struct not_equal
		{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry || (*in1 != *in2);
					--in1; --in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return true;
					--in1; --in2;
				}

				return false;
			}
		};

		struct less_than
		{
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry || (*in1 < *in2);
					--in1; --in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					--in1; --in2;
				}

				return false;
			}
		};

		struct less_than_or_equal
		{
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry && (*in1 <= *in2);
					--in1; --in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					--in1; --in2;
				}

				return true;
			}
		};

		struct greater_than
		{
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry || (*in1 > *in2);
					--in1; --in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					--in1; --in2;
				}

				return false;
			}
		};

		struct greater_than_or_equal
		{
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool no_break(bool carry, InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry && (*in1 >= *in2);
					--in1; --in2;
				}

				return carry;
			}

			template<typename InputIterator1, typename InputIterator2, typename TerminalIterator2>
			static bool with_break(InputIterator1 in1, InputIterator2 in2, TerminalIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					--in1; --in2;
				}

				return true;
			}
		};
/*
	Finds the first occurrence along the iterator path of a non-zero value, returns the iterator position.

	It might appear at first glance this shouldn't be classified as componentwise,
	but the final value is still dependent upon the previous values. The lack of success is the "carry".
*/
		template<typename InputIterator, typename TerminalIterator>
		static InputIterator order(InputIterator in, TerminalIterator end)
		{
			while (in != end && !*in) --in;

			return in;
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
		struct unroll_0
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct zero
			{
				template<typename Iterator>
				static bool no_break(bool carry, Iterator in)
				{
					carry=carry && !*in;
					return unroll_0<N-1>::zero::no_break(carry, --in);
				}

				template<typename Iterator>
				static bool with_break(Iterator in)
				{
					if (*in) return false;
					else return unroll_0<N-1>::zero::with_break(--in);
				}
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry && (*in1 == *in2);
					return unroll_0<N-1>::equal::no_break(carry, --in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return false;
					else return unroll_0<N-1>::equal::with_break(--in1, --in2);
				}
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry || (*in1 != *in2);
					return unroll_0<N-1>::not_equal::no_break(carry, --in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return true;
					else return unroll_0<N-1>::not_equal::with_break(--in1, --in2);
				}
			};
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return unroll_0<N-1>::less_than(--in1, --in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return unroll_0<N-1>::less_than_or_equal(--in1, --in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return unroll_0<N-1>::greater_than(--in1, --in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return unroll_0<N-1>::greater_than_or_equal(--in1, --in2);
			}
/*
			Intuitively, "right_shift" would be defined here,
			but given its implementation it is actually part of componentwise.h
*/
/*
	Finds the first occurrence along the iterator path of a non-zero value, returns the iterator position.

	It might appear at first glance this shouldn't be classified as componentwise,
	but the final value is still dependent upon the previous values. The lack of success is the "carry".
*/
			template<typename Iterator>
			static Iterator order(Iterator in)
			{
				if (*in) return in;
				else return unroll_0<N-1>::order(--in);
			}

			struct assign
			{
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
			struct zero
			{
				template<typename Iterator>
				static bool no_break(bool carry, Iterator in)
					{ return carry; }
				template<typename Iterator>
				static bool with_break(Iterator in)
					{ return true; }
			};

			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }
				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
					{ return true; }
			};

			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
					{ return false; }
			};

			template<typename Iterator1, typename Iterator2>
			static bool less_than(Iterator1 in1, Iterator2 in2)
				{ return false; }
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(Iterator1 in1, Iterator2 in2)
				{ return true; }
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(Iterator1 in1, Iterator2 in2)
				{ return false; }
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(Iterator1 in1, Iterator2 in2)
				{ return true; }

/*
	Does not perform what is otherwise the standard final decrement.
*/
			template<typename Iterator>
			static Iterator order(Iterator in)
				{ return in; }

			struct assign
			{
			};
		};
	};
    }

    namespace bidirectional
    {
	template<typename size_type>
	struct arithmetic_0
	{
		template<size_type N, typename Filler=void>
		struct unroll_0
		{
			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
		};
	};
    }
    
    namespace random_access
    {
	template<typename size_type>
	struct arithmetic_0
	{
		template<size_type N, typename Filler=void>
		struct unroll_0
		{
			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
		};
	};
    }
   }
  }
 }
}

#endif
