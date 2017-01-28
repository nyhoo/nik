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
	Note:	This collection does not interpret the combination sub_adj<backward, mutate, hook>
		and leaves it undefined.

		the repeat variable 'n' is of size_type which breaks semantically for negative numbers (signed types).

		No need for "memory_action(sub)" at body's end, as it would only be called for a segment deallocate,
		in which case there's no need for such an expensive loop to begin with. This special case is branched.
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define PARAMETERS													\
															\
	size_type verb_mask,												\
	typename... F,													\
															\
	typename sub_pointer,												\
															\
	size_type sub_mask,												\
	typename... T


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	tuple/list data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.

	When dispatches are properly partitioned, there is no need for a match error.
*/


struct Repeat
{
	template<size_type mask>
	using functor = typename dispatch
	<
		mask,

		module::adverb<OmitFunctor>

	>::rtn;

	template<size_type mask, typename F>
	using functor_F = typename dispatch
	<
		mask,

		module::adverb<ApplyFunctor, F>

	>::rtn;

	template<size_type mask>
	using tracer = typename dispatch
	<
		mask,

		module::adverb<OmitCount>,
		module::adverb<ApplyCount, void>

	>::rtn;


/***********************************************************************************************************************/


	template<size_type mask, size_type base, typename... params>
	struct adverb;


	template<size_type mask, typename F>
	struct adverb
	<
		mask,
		match<mask, Prototype, Specialize>::rtn,
		F
	> :

			public functor_F<mask, F>,
			public tracer<mask>

	{
		adverb(const F & f) : functor_F<mask, F>(f) { }
	};


	template<size_type mask>
	struct adverb
	<
		mask,
		match<mask, Prototype, Specialize>::rtn
	> :

			public functor<mask>,
			public tracer<mask>

	{
		static constexpr size_type functor_mask = apply< deduct<mask, Functor>::rtn, ApplyFunctor>::rtn;
		static constexpr size_type tracer_mask = apply< deduct<mask, Tracer>::rtn, ApplyCount>::rtn;
		static constexpr size_type base = match<mask, Prototype, Specialize>::rtn;

		template<typename F>
		static adverb<functor_mask, base, F> apply_functor(const F & f)
		{
			return adverb<functor_mask, base, F>(f);
		}

		static adverb<tracer_mask, base> apply_count(const size_type & c)
		{
			return adverb<tracer_mask, base>(c);
		}
	};


/***********************************************************************************************************************/


	template<Connotation... params>
	struct Adverb
	{
		enum struct Manner : size_type
		{
			functor,
			tracer,
			optimizer,

			dimension
		};

		using Selection = tuple
		<
			adv_list<Connotation::omit_functor, Connotation::apply_functor>,	// functor
			adv_list<Connotation::omit_count, Connotation::apply_count>,		// tracer
			adv_list<Connotation::prototype, Connotation::specialize>		// optimizer
		>;

		static constexpr size_type mask = bit::mask::template cast
		<
			typename sortFill<Selection, Connotation, params...>::rtn

		>::rtn;

		static constexpr size_type base = match<mask, Prototype, Specialize>::rtn;
	};


	template<Connotation... params>
	using verb = adverb
	<
		Adverb<params...>::mask,
		Adverb<params...>::base
	>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<size_type mask>
	using direction = typename dispatch
	<
		mask,

		module::adjective<ForwardAllocateHook>,
		module::adjective<ForwardAllocateLink>,

		module::adjective<ForwardDeallocateHook>,
		module::adjective<ForwardDeallocateLink>,

		module::adjective<Forward>,

		module::adjective<BackwardAllocateHook>,
		module::adjective<BackwardAllocateLink>,

		module::adjective<BackwardDeallocateHook>,
		module::adjective<BackwardDeallocateLink>,

		module::adjective<Backward>

	>::rtn;

	template<size_type mask>
	using interval = typename dispatch
	<
		mask,

		module::adjective<Closing>,
		module::adjective<Closed>,
		module::adjective<Opening>,
		module::adjective<Open>

	>::rtn;

	template<size_type mask>
	using image = typename dispatch
	<
		mask,

		module::adjective<Image>

	>::rtn;

	template<size_type mask, typename T>
	using iterator_T = typename dispatch
	<
		mask,

		adjective<DeallocateSegment, T>,

		adjective<Iterator>

	>::rtn;

	template<size_type mask>
	using iterator = typename dispatch
	<
		mask,

		adjective<AllocateSegment, void>,
		adjective<Segment>,

		adjective<Iterator>

	>::rtn;


/***********************************************************************************************************************/


	template<size_type mask, size_type base, typename... params>
	struct adjective;


	template<size_type mask, typename T>
	struct adjective
	<
		mask,
		match<mask, Closing, Closed, Opening, Open>::rtn,
		T
	> :

			public direction<mask>,
			public interval<mask>,
			public image<mask>,
			public iterator_T<mask, T>

	{
		adjective(T *o) : iterator_T<mask, T>(o) { }
	};


	template<size_type mask>
	struct adjective
	<
		mask,
		match<mask, Closing, Closed, Opening, Open>::rtn
	> :

			public direction<mask>,
			public interval<mask>,
			public image<mask>,
			public iterator<mask>

	{
		adjective() : iterator<mask>() { }
		adjective(size_type l, size_type o) : iterator<mask>(l, o) { }

		static constexpr size_type allocate_mask = apply< deduct<mask, Image>::rtn, AllocateSegment>::rtn;
		static constexpr size_type deallocate_mask = apply< deduct<mask, Image>::rtn, DeallocateSegment>::rtn;
		static constexpr size_type base = match<mask, Closing, Closed, Opening, Open>::rtn;

		static adjective<allocate_mask, base> allocate_segment(size_type l, size_type o = 0)
		{
			return adjective<allocate_mask, base>(l, o);
		}

		template<typename T>
		static adjective<deallocate_mask, base, T> deallocate_segment(T *o)
		{
			return adjective<deallocate_mask, base, T>(o);
		}
	};


/***********************************************************************************************************************/


	template<Association... params>
	struct Adjective
	{
		enum struct Attribute : size_type
		{
			direction,
			interval,
			image,
			iterator,

			dimension
		};

		using Arrangement = tuple
		<
			adj_list<Association::forward, Association::backward>,						// direction
			adj_list<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
			adj_list<Association::mutate, Association::allocate, Association::deallocate>,			// image
			adj_list<Association::segment, Association::hook, Association::link>				// iterator
		>;

		static constexpr size_type mask = bit::mask::template cast
		<
			typename sortFill<Arrangement, Association, params...>::rtn

		>::rtn;

		static constexpr size_type base = match<mask, Closing, Closed, Opening, Open>::rtn;
	};

	template<Association... params>
	using subject = adjective
	<
		Adjective<params...>::mask,
		Adjective<params...>::base
	>;
};


template<size_type mask, size_type base, typename... params>
using RepeatVerb = typename Repeat::template adverb<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using RepeatSubject = typename Repeat::template adjective<mask, base, params...>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define STATIC_ASSERT													\
															\
	static_assert													\
	(														\
		sub_directionEnum != Association::backward				||				\
		(													\
			sub_imageEnum != Association::mutate				&&				\
			sub_imageEnum != Association::deallocate							\
		)									||				\
		sub_iteratorEnum != Association::hook					,				\
															\
		"\n\nmap is undefined for Subject<backward, hook>.\n"							\
	);


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_FULL & sub);


template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, SUB_ADJ_FULL & sub,

			size_type n);
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[out, end)
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Closing, T...> & sub)
{
//	STATIC_ASSERT

	while (out != end)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[out, out + n)
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Closing, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

	while (n)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
		--n;
	}

	return out;
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[out, end]
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Closed, T...> & sub)
{
//	STATIC_ASSERT

	while (out != end)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
	}

	functor_action(ad, out);
	count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[out, out + n]
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Closed, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

	while (n)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
		--n;
	}

	functor_action(ad, out);
	count_action(ad);

	return out;
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	(out, end]
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Opening, T...> & sub)
{
//	STATIC_ASSERT

	while (out != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out);
		count_action(ad);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(out, out + n]
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Opening, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

	while (n)
	{
		iterate_action(out, sub);

		functor_action(ad, out);
		count_action(ad);

		--n;
	}

	return out;
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	(out, end), out != end
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Open, T...> & sub)
{
//	STATIC_ASSERT

	iterate_action(out, sub);

	while (out != end)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(out, out + n+1)
*/


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Open, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

	iterate_action(out, sub);

	while (n)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
		--n;
	}

	return out;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Notice in this case the sub_adjective can be const because we know enough about it to optimize as such.
*/


/*
template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, TRepeatSubject<T, Association::deallocate, Association::Segment> & sub)

	{ memory_action(sub); }


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, sub_pointer end, const RepeatSubject<sub_mask, AllocateSegment, T...> & sub)
{
	RepeatSubject<sub_mask, MutateSegment, T...> sub_mutate;

	return repeat(ad, memory_action(origin, sub), end, sub_mutate);
}


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, const RepeatSubject<sub_mask, AllocateSegment, T...> & sub,

			size_type n)
{
	RepeatSubject<sub_mask, MutateSegment, T...> sub_mutate;

	return repeat(ad, memory_action(origin, sub), sub_mutate, n);
}
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef PARAMETERS
#undef STATIC_ASSERT


