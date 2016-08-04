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
	"Side effects" at the general coder level is bad policy,
	but at this intended low level where safety is minimal it is more memory efficient.

	Methods that have more than one template typename (eg. Iterator1, Iterator2) have so for higher
	entropy, but in practice you may need to optimize (eg. Iterator2=const Iterator1 &).
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).
	As far as debugging goes, keep in mind the location of an array (as pointer) is c_policy::unit and thus not
	allowed as a reference, so for example if you declare "int array[100]" you can't pass "array" directly
	if you're template parameter is specified as a variable. Instead you need to make a copy of array:
		"int *a=array", so then you can pass "a" instead.

	If there is no "with_return" variant of a given method, it means it has and "end"
	parameter which is already equivalent to such a returned value. Would be redundant.
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


class map
{
	private:
		typedef nik::arg<size_type> Arg;

		typedef typename Arg::interval Interval;
		typedef typename Arg::list List;
		typedef typename Arg::verse Verse;

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

	private:

		template<typename paramList>
		struct verse
		{
			template<size_type... params>
			struct interval
			{
				#include"macro/define/semiotic/interval/loop.cpp"
				#include"macro/define/semiotic/basis/loop.cpp"
				#include"macro/define/semiotic/interval/loop.h"

				using loop = verse_interval_loop
				<
					paramList,
					typename gvf_media::template sortFill<Interval, params...>::rtn
				>;

//				#include"macro/undef/semiotic/interval/loop.h"
//				#include"macro/undef/semiotic/basis/loop.cpp"
//				#include"macro/undef/semiotic/interval/loop.cpp"
			};

/*
			template<size_type... params>
			struct list
			{
				#include"macro/define/list/semiotic/loop.cpp"
				#include"macro/define/extension/semiotic/loop.cpp"
				#include"macro/define/list/semiotic/loop.h"

				using loop = verse_list_loop
				<
					paramList,
					typename gvf_media::template sortFill<List, params...>::rtn
				>;

				#include"macro/undef/list/semiotic/loop.cpp"
				#include"macro/undef/extension/semiotic/loop.cpp"
				#include"macro/undef/list/semiotic/loop.h"
			};
*/
		};

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

	public:

		template<size_type... params>
		using id = verse<
					typename gvf_media::template sortFill<Verse, params...>::rtn
				>;
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
