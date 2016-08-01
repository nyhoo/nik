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

		template<typename listParams, size_type car = listParams::car>
		struct listArguments { };

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

			#include"define/semiotic/allocate/loop.cpp"
			#include"../../macro/define/map/allocate/loop.cpp"

	private:

		template<typename listParams>
		struct listArguments<listParams, arg::list::allocate>
		{
			struct intervalArgs
			{
				#include"../../macro/define/map/allocate/loop.h"

				using loop = allocate_loop<typename listParams::cdr>;

				#include"../../macro/undef/map/allocate/loop.h"
			};
		};

			#include"../../macro/undef/map/allocate/loop.cpp"
			#include"undef/semiotic/allocate/loop.cpp"

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
			#include"define/semiotic/deallocate/loop.cpp"
			#include"../../macro/define/map/deallocate/loop.cpp"

	private:

		template<typename listParams>
		struct listArguments<listParams, arg::list::deallocate>
		{
			struct emptyArgs
			{
				#include"../../macro/define/map/deallocate/loop.h"

				using loop = deallocate_loop<typename listParams::cdr>;

				#include"../../macro/undef/map/deallocate/loop.h"
			};
		};

			#include"../../macro/undef/map/deallocate/loop.cpp"
			#include"undef/semiotic/deallocate/loop.cpp"
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
			#include"define/semiotic/mutate/loop.cpp"
			#include"../../macro/define/map/mutate/loop.cpp"

	private:

		template<typename listParams>
		struct listArguments<listParams, arg::list::mutate>
		{
			struct emptyArgs
			{
				#include"../../macro/define/map/mutate/loop.h"

				using loop = mutate_loop<typename listParams::cdr>;

				#include"../../macro/undef/map/mutate/loop.h"
			};
		};

			#include"../../macro/undef/map/mutate/loop.cpp"
			#include"undef/semiotic/mutate/loop.cpp"
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

	public:

		template<size_type... params>
		using mapArgs = mapArguments<typename gvf_media::template sortFill<arg::map::bounds, params...>::rtn>;
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

