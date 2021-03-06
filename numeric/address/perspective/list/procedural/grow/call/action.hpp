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
	Return policy is to return the beginning location of the newly introduced pointer(s).

	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Grow
{
	enum struct Manner : size_type
	{
		fixer,

		dimension
	};

	using Selection = tuple
	<
		adv_list<Connotation::after, Connotation::before, Connotation::between>		// fixer
	>;

	template<Connotation... params>
	using verb = Adverb<typename sortFill<Selection, Connotation, params...>::rtn>;

	enum struct Attribute : size_type
	{
		interval,

		dimension
	};

	using Arrangement = tuple
	<
		adj_list<Association::closing, Association::closed, Association::opening, Association::open>	// interval
	>;

	template<Association... params>
	using noun = Adjective<typename sortFill<Arrangement, Association, params...>::rtn>;
};


/***********************************************************************************************************************/


#define SUB_ADJ_PARAMETERS_LIST												\
															\
	typename sub_list,


#define SUB_ADJ_PARAMETERS_POINTER											\
															\
	typename sub_pointer,


/***********************************************************************************************************************/


#define OB_ADJ_PARAMETERS_POINTER											\
															\
	typename ob_pointer


/***********************************************************************************************************************/


#define SUB_LIST_OB_POINTER_PARAMETERS											\
															\
	SUB_ADJ_PARAMETERS_LIST												\
															\
	OB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/


#define SUB_POINTER_OB_POINTER_PARAMETERS										\
															\
	SUB_ADJ_PARAMETERS_POINTER											\
															\
	OB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_TYPE(fixer)													\
															\
	Adverb<adv_list<Connotation::fixer>>


/***********************************************************************************************************************/


#define SUB_ADJ_INTERVAL(interval)											\
															\
	Adjective<adj_list<Association::interval>>


/***********************************************************************************************************************/


#define OB_ADJ_INTERVAL(interval)											\
															\
	Adjective<adj_list<Association::interval>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							before
************************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	+in=out.initial;
	out.initial=in;

	return in;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_pointer in)
{
	+in=out.initial;
	out.initial=in;

	return in;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_pointer in)
{
	+in=+out.initial;
	+out.initial=in;

	return in;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_pointer in)
{
	+in=+out.initial;
	+out.initial=in;

	return in;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	*end=*out.initial;
	+end=+out.initial;
	delete out.initial;
	out.initial=in;

	return in;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closed) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(opening) & ob)
{
	+end=out.initial;
	out.initial=+in;
	delete in;

	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(open) & ob)
{
	*end=*out.initial;
	+end=+out.initial;
	delete out.initial;
	out.initial=+in;
	delete in;

	return out.initial;
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closed) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(opening) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(open) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closed) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(opening) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(open) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closed) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(opening) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(open) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
	return out.initial;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							after
************************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(after) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	out.terminal=+out.terminal=in;

	return in;
	return out.terminal;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(after) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+out.terminal=in;
	out.terminal=end;

	return end;
	return out.terminal;
}


/************************************************************************************************************************
							closing
************************************************************************************************************************/



/************************************************************************************************************************
							closed
************************************************************************************************************************/



/************************************************************************************************************************
							opening
************************************************************************************************************************/



/************************************************************************************************************************
							open
************************************************************************************************************************/



/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							between
************************************************************************************************************************/


/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/

template<SUB_POINTER_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(between) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	+in=+out;
	+out=in;

	return in;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<SUB_POINTER_OB_POINTER_PARAMETERS>
static inline ob_pointer grow(const ADV_TYPE(between) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+end=+out;
	+out=in;

	return in;
}


/************************************************************************************************************************
							closing
************************************************************************************************************************/



/************************************************************************************************************************
							closed
************************************************************************************************************************/



/************************************************************************************************************************
							opening
************************************************************************************************************************/



/************************************************************************************************************************
							open
************************************************************************************************************************/



/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef SUB_ADJ_PARAMETERS_LIST
#undef SUB_ADJ_PARAMETERS_POINTER
#undef OB_ADJ_PARAMETERS_POINTER
#undef SUB_LIST_OB_POINTER_PARAMETERS
#undef SUB_POINTER_OB_POINTER_PARAMETERS
#undef ADV_TYPE
#undef SUB_ADJ_INTERVAL
#undef OB_ADJ_INTERVAL


