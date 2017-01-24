/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Connotations and Manners of "{omit, apply} functor" are implicit in the build and it is tempting to minimize,
	but 1) This is bad design because I would be relying on an implementation feature to enforce specification design,
	2) Without explicitly specifying them, the compiler cannot distinguish the partial specializations below.

	This is a very delicate setup---not at all robust---and must follow very strict design rules.

	1) no cross conversion.
*/



enum struct Connotation : size_type
{
	omit_functor,
	apply_functor,

	omit_count,
	apply_count,

	after,
	before,
	between,

	prototype,
	specialize,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


using bit = typename bitmask::template bit<Connotation>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params> struct Adverb;


/************************************************************************************************************************
							1
***********************************************************************************************************************/


struct Adverb_Null { };


/***********************************************************************************************************************/

struct ApplyFunctor { };
struct ApplyCount { };

template<size_type mask, typename F>
struct Adverb<mask, ApplyFunctor, F>
{
	F functor;

	Adverb(const F & f) : functor(f) { }
};


template<size_type mask>
struct Adverb<mask, ApplyCount>
{
	size_type count;

	Adverb(const size_type & c) : count(c) { }
};


/************************************************************************************************************************
							2
***********************************************************************************************************************/


struct ApplyApply
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Connotation::apply_functor,
		Connotation::apply_count

	>::rtn;
};

struct ApplyOmit
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Connotation::apply_functor,
		Connotation::omit_count

	>::rtn;
};


template<size_type mask, typename F>
struct Adverb<mask, ApplyApply, F> :

		public Adverb<mask, ApplyFunctor, F>,
		public Adverb<mask, ApplyCount>
{
	static constexpr size_type bitmask = ApplyApply::bitmask;

	Adverb(const F & f, size_type c) :

			Adverb<mask, ApplyFunctor, F>(f),
			Adverb<mask, ApplyCount>(c)

		{ }
};


template<size_type mask, typename F>
struct Adverb<mask, ApplyOmit, F> :

		public Adverb<mask, ApplyFunctor, F>
{
	static constexpr size_type bitmask = ApplyOmit::bitmask;

	Adverb(const F & f) :

			Adverb<mask, ApplyFunctor, F>(f)

		{ }
};


struct OmitApply
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Connotation::omit_functor,
		Connotation::apply_count

	>::rtn;
};

struct OmitOmit
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Connotation::omit_functor,
		Connotation::omit_count

	>::rtn;
};


template<size_type mask>
struct Adverb<mask, OmitApply> :

		public Adverb<mask, ApplyCount>
{
	static constexpr size_type bitmask = OmitApply::bitmask;
};


struct Prototype
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Connotation::prototype

	>::rtn;
};


template<size_type mask>
struct Adverb<mask, OmitOmit>
{
	static constexpr size_type bitmask = OmitOmit::bitmask;

	static constexpr size_type castmask = mask | ApplyOmit::bitmask;

	template<typename F>
	static Adverb<castmask, Prototype, F> cast(const F & f)
	{
		return Adverb<castmask, Prototype, F>(f);
	}
};


/************************************************************************************************************************
							3
***********************************************************************************************************************/


template<size_type mask>
using pattern = typename bit::template pattern<mask>;

template<size_type mask, typename... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask>
using safe_match = typename match
<
	mask,

	Adverb
	<
		pattern<mask>::template tail<OmitOmit::bitmask>::rtn,
		OmitOmit
	>,

	Adverb
	<
		pattern<mask>::template tail<OmitApply::bitmask>::rtn,
		OmitApply
	>,

	Adverb_Null

>::rtn;

template<size_type mask, typename F>
using functor_match = typename match
<
	mask,

	Adverb
	<
		pattern<mask>::template tail<ApplyOmit::bitmask>::rtn,
		ApplyOmit,
		F
	>,

	Adverb
	<
		pattern<mask>::template tail<ApplyApply::bitmask>::rtn,
		ApplyApply,
		F
	>,

	Adverb_Null

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename Optimizer>
struct Adverb<mask, Optimizer> : public safe_match<mask>
{
	static constexpr size_type bitmask = Optimizer::bitmask;
};


template<size_type mask, typename Optimizer, typename F>
struct Adverb<mask, Optimizer, F> : public functor_match<mask, F>
{
	static constexpr size_type bitmask = Optimizer::bitmask;

	Adverb(const F & f) : functor_match<mask, F>(f) { }
};


/***********************************************************************************************************************/


template<size_type mask>
struct Adverb<mask> : public match
<
	mask,

	Adverb
	<
		mask,//pattern<mask>::template tail<Prototype::bitmask>::rtn,
		Prototype
	>,

	Adverb_Null

>::rtn { };


