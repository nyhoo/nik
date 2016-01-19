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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_1_H
#define CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_1_H

// for debugging:
#include"../../../../media/generic/display/display.h"

#include"../../regist/regist.h"
#include"../componentwise/componentwise.h"

// Clean up the typedefs/usings namespace stuff.

// overhead dependencies:

#include"arithmetic_0.h"

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
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef componentwise<size_type> fwd_comp;
		typedef arithmetic_0<size_type> fwd_arit;

		struct scale
		{
/*
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the constant scalar value.
	carry is the overhead value. Set this to zero for the "normal" interpretation.
*/
			template<typename OutputIterator, typename InputIterator, typename TerminalIterator, typename ValueType>
			static void no_return(OutputIterator out, InputIterator in1, TerminalIterator end1, ValueType in2, ValueType carry)
			{
				while (in1 != end1)
				{
					carry=regist::multiply::return_high(*out=carry, *in1, in2);
					++out; ++in1;
				}
			}
/*
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the constant scalar value.
	carry is the overhead value. Set this to zero for the "normal" interpretation.
*/
			template<typename OutputIterator, typename InputIterator, typename TerminalIterator, typename ValueType>
			static OutputIterator with_return(OutputIterator out,
				InputIterator in1, TerminalIterator end1, ValueType in2, ValueType carry)
			{
				while (in1 != end1)
				{
					carry=regist::multiply::return_high(*out=carry, *in1, in2);
					++out; ++in1;
				}

				return out;
			}
		};
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
		struct unroll_1 : public fwd_arit::template unroll_0<N, Filler>
		{
			template<size_type M>
			using fwd_unroll=typename fwd_arit::template unroll_0<M, Filler>;

			struct scale
			{
/*
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the constant scalar value.
	carry is the overhead value. Set this to zero for the "normal" interpretation.

	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void no_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ unroll_1<N-1>::scale::no_return(++out, ++in1, in2,
						regist::multiply::return_high(*out=carry, *in1, in2)); }
/*
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the constant scalar value.
	carry is the overhead value. Set this to zero for the "normal" interpretation.

	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ return unroll_1<N-1>::scale::with_return(++out, ++in1, in2,
						regist::multiply::return_high(*out=carry, *in1, in2)); }
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
/*
	Does not assume anything about the existing value of out1.

	out2 is meant to be a temporary variable.

	Is it worth testing for *in2 == 0 ?
*/
				template<typename OutputIterator1, typename OutputIterator2, typename InputIterator1, typename InputIterator2>
				static void multiply(OutputIterator1 out1, OutputIterator2 out2, InputIterator1 in1, InputIterator2 in2)
				{
					unroll_1<M>::scale::no_return(fwd_comp::
						template unroll<N-M>::repeat::with_return(out2, 0), in1, *in2, 0);
					fwd_unroll<N>::assign::plus::no_return(out1, out2, 0);
					subroll_1<M-1>::multiply(out1, out2, in1, ++in2);
				}
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
				template<typename OutputIterator1, typename OutputIterator2, typename InputIterator1, typename InputIterator2>
				static void multiply(OutputIterator1 out1, OutputIterator2 out2, InputIterator1 in1, InputIterator2 in2)
					{ }
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
/*
	Obfuscated code ?
*/
			struct scale
			{
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void no_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ }

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ return out; }
			};
		};
	};
    }

    namespace backward
    {
	template<typename size_type>
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef forward::componentwise<size_type> fwd_comp;
		typedef componentwise<size_type> bwd_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef arithmetic_0<size_type> bwd_arit;
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
		struct unroll_1 : public bwd_arit::template unroll_0<N, Filler>
		{
			template<size_type M>
			using bwd_unroll=typename bwd_arit::template unroll_0<M>;

			struct divide
			{
/*
	Given the nature of single digit division, the return value is the remainder.
*/
				struct single_digit
				{
/*
	"out" is the retainer of the returned quotient.
	"carry" is a memory optimization hack. When calling this function, carry needs to be set to *in.
	Assumes "in" is the leftmost digit of the structure.

	Is optimized to assume 0 <= carry < d.

	Assumes "d" is the divisor and that in >= 3.
	If d == 1 why use this at all?
	If d == 2 use bit shifting.
*/
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static ValueType half_register_divisor(OutputIterator out,
						InputIterator in, ValueType d, ValueType carry)
					{
						if (carry) *out=regist::divide::half_register_divisor(carry, carry, *in, d);
						else if (*in < d) { *out=0; carry=*in; }
						else { *out=*in/d; carry=*in%d; }

						return unroll_1<N-1>::divide::single_digit::half_register_divisor(--out, --in, d, carry);
					}
/*
	"out" is the retainer of the returned quotient.
	"carry" is a memory optimization hack. When calling this function, carry needs to be set to *in.
	Assumes "in" is the leftmost digit of the structure.

	Assumes "d" is the divisor and that in >= 3.
	If d == 1 why use this at all?
	If d == 2 use bit shifting.
*/
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static ValueType full_register_divisor(OutputIterator out,
						InputIterator in, ValueType d, ValueType carry)
					{
						if (carry) *out=regist::divide::full_register_divisor(carry, carry, *in, d);
						else if (*in < d) { *out=0; carry=*in; }
						else { *out=*in/d; carry=*in%d; }

						return unroll_1<N-1>::divide::single_digit::full_register_divisor(--out, --in, d, carry);
					}
				};
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
			struct divide
			{
				struct single_digit
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static ValueType half_register_divisor(OutputIterator out,
						InputIterator in, ValueType d, ValueType carry)
							{ return carry; }

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static ValueType full_register_divisor(OutputIterator out,
						InputIterator in, ValueType d, ValueType carry)
							{ return carry; }
				};
			};
		};
	};
    }

    namespace bidirectional
    {
	template<typename size_type>
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef forward::componentwise<size_type> fwd_comp;
		typedef backward::componentwise<size_type> bwd_comp;
		typedef componentwise<size_type> bid_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef arithmetic_0<size_type> bid_arit;

		template<size_type N, typename Filler=void>
		struct unroll_1 : public bwd_arit::template unroll_0<N, Filler>
		{
			template<size_type M>
			using bwd_unroll=typename bwd_arit::template unroll_0<M>;
			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
		};
	};
    }

    namespace random_access
    {
	template<typename size_type>
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef forward::componentwise<size_type> fwd_comp;
		typedef backward::componentwise<size_type> bwd_comp;
		typedef bidirectional::componentwise<size_type> bid_comp;
		typedef componentwise<size_type> rnd_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef bidirectional::arithmetic_1<size_type> bid_arit;
		typedef arithmetic_0<size_type> rnd_arit;

		template<size_type N, typename Filler=void>
		struct unroll_1 : public rnd_arit::template unroll_0<N, Filler>
		{
			template<size_type M>
			using rnd_unroll=typename rnd_arit::template unroll_0<M>;

			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
				struct divide
				{
					template<typename ValueType>
					struct multiple_digit
					{
/*
	N is the block length as reference.

	t is the initial location of a temporary N block used for internal computations.
		Initialization is unnecessary as lazy comparisons are used avoiding values out of bounds.
	q is the final location of the quotient to be determined.
	r is the initial location of the overhead value (carry).
		Set this to the first digits of the numerator of equal length to the denominator for the "normal" interpretation.
		Digits are shifted into r's register until big enough to divide.
	lr is the location of the leading digit of the remainder r.
	n is the second last digit location of the numerator as an N block. In practice this may be the initial location at times.
	d is the initial location of the denominator as an N block.
	ld is the location of the leading digit of the divisor d.

	Assumes (r|n) and d are already normalized for Knuth multiple precision division optimization.

	In all fairness, there are many ways to interpret an unrolling version.
	It's not practical to implement them all, so I have chosen the version I think is most contextually generic.

	OutputIterators are assumed safe for modification.
	In practice this means providing a deep copy if necessary when passing const references as input.

	Assumes b < d <= n.

	Body variables are refactored as function parameters for higher entropy as one then defer type constraints (templating).
	On the otherhand, since size_type is a (more-or-less) known type, it can be declared within the body.

	*** fix parameters and arguements for the N=0 case as well.
	*** only when stabilized, decide where this algorithm best fits (random access?)
*/

// At this point you're prematuraly optimizing. First adhere to the functional best practices of tail recursion,
// with clean concept pseudo code, then optimize after. Keep the pseudo code to go back and reinterpret single digit
// and register versions of this division.
						template<typename OutputIterator1, typename OutputIterator2,
							typename OutputIterator3, typename InputIterator1, typename InputIterator2>
						static void quotient_remainder(OutputIterator1 t,
							OutputIterator2 q, OutputIterator3 r, OutputIterator3 lr,
								InputIterator1 n, InputIterator2 d, InputIterator2 ld)
						{
							size_type tlen, rlen=lr-r, dlen=ld-d;
//							nik::display << rlen << ' ' << dlen << nik::endl;
//							nik::display << fwd_arit::less_than(false, r, d, ld+1) << nik::endl;
							if (rlen < dlen || (rlen == dlen && fwd_arit::less_than(false, r, d, ld+1)))
							{
								*q=0;
								OutputIterator3 olr(lr);
								*bwd_comp::assign::with_return(++lr, olr, r)=*n;
//								nik::display << r[0] << ' ' << r[1] << ' ' << r[2] << nik::endl;
							}
							else
							{
								ValueType max_value(-1);
								*q=(rlen == dlen) ? *lr/(*ld) :
									(*lr < *ld) ? regist::divide::
										full_register_divisor(max_value, *lr, *(lr-1), *ld) :
									max_value;

//								nik::display << *q << nik::endl;
								InputIterator2 ld1=ld+1;

								OutputIterator1 lt=fwd_arit::scale::
									with_return(t, ld-1, ld1+(ld1 != d+N), *q, (ValueType) 0);
								lt-=!*lt; tlen=lt-t;
//								nik::display << t[0] << ' ' << t[1] << ' ' << t[2] << nik::endl;
								if (tlen > rlen || ((tlen == rlen) &&
									fwd_arit::greater_than(false, t, r, lr+1)))
								{
									--*q;
									tlen=fwd_arit::scale::
										with_return(t, ld-1, ld+1, *q, (ValueType) 0)-t;
									if (tlen > rlen || ((tlen == rlen) &&
										fwd_arit::greater_than(false, t, r, lr+1))) --*q;
								}

	// assuming d is properly initialized, this will properly initialize t as well.
								fwd_arit::template unroll_1<N>::scale::with_return(t, d, *q, (ValueType) 0);
								fwd_arit::template unroll_1<N>::assign::minus::
									no_return((ValueType) 0, *r, r, t);
								lr=bwd_arit::order(lr, r);
							}

							subroll_1<M-1>::divide::template multiple_digit<ValueType>::
								quotient_remainder(t, --q, r, lr, --n, d, ld);
						}
					};
				};
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
				struct divide
				{
					template<typename ValueType>
					struct multiple_digit
					{
						template<typename OutputIterator1, typename OutputIterator2,
							typename OutputIterator3, typename InputIterator1, typename InputIterator2>
						static void quotient_remainder(OutputIterator1 t,
							OutputIterator2 q, OutputIterator3 r, OutputIterator3 lr,
								InputIterator1 n, InputIterator2 d, InputIterator2 ld)
									{ }
					};
				};
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
		};
	};
    }
   }
  }
 }
}

#endif
