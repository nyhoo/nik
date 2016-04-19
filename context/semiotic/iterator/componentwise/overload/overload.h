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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_OVERLOAD_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_OVERLOAD_H

/*
	Overload operators are similar enough to factorize and pass the specific operator
	as a method, but it is more cpu efficient to NOT---especially given there are few practical
	contexts in which many different such operators will all be used together.

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

	The struct "repeat" though by name does not associate with an operator overload, is in fact
	a special case of the proper assignment operator overload. The name change is a semantic convenience.
*/

#include"define/test/loop.h"
#include"define/test/count.h"
#include"define/test/unroll.h"
#include"define/test/initial.h"

#include"define/post_test/loop.h"
#include"define/post_test/count.h"
#include"define/post_test/unroll.h"
#include"define/post_test/initial.h"

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace componentwise
    {
     namespace forward
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		#include"../../define/plus/loop.h"

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
			#include"../../define/plus/unroll.h"
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
			#include"../../define/plus/initial.h"
		};
	};
     }

     namespace backward
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		#include"../../define/minus/loop.h"

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
			#include"../../define/minus/unroll.h"
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
			#include"../../define/minus/initial.h"
		};
	};
     }

     namespace bidirectional
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
		};
	};
     }

     namespace random_access
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
		};
	};
     }
    }
   }
  }
 }
}

#include"../../undef/post_test/initial.h"
#include"../../undef/post_test/unroll.h"
#include"../../undef/post_test/count.h"
#include"../../undef/post_test/loop.h"

#include"../../undef/test/initial.h"
#include"../../undef/test/unroll.h"
#include"../../undef/test/count.h"
#include"../../undef/test/loop.h"

#endif
