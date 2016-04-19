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

#ifndef NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_POLICY_H
#define NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_POLICY_H

#include"../pointer/pointer.h"
#include"../arithmetic/arithmetic.h"
//#include"../vector/vector.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the depth complexity of nested namespaces.
	2) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
 namespace context
 {
  namespace media
  {
   namespace iterator
   {
    namespace componentwise
    {
/*
*/
	template<typename SizeType>
	struct policy
	{
		typedef SizeType size_type;
/*
	pointer:
*/
			using ptr=pointer<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using ptr_unroll=typename ptr::template unroll<N, M, L>;
/*
	forward:
*/
/*
		arithmetic:
*/
			using fwd_arit=forward::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using fwd_arit_unroll=typename fwd_arit::template unroll<N, M, L>;
/*
	backward:
*/
/*
		arithmetic:
*/
			using bwd_arit=backward::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bwd_arit_unroll=typename bwd_arit::template unroll<N, M, L>;
/*
	bidirectional:
*/
/*
		arithmetic:
*/
			using bid_arit=bidirectional::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bid_arit_unroll=typename bid_arit::template unroll<N, M, L>;
/*
	random_access:
*/
/*
		arithmetic:
*/
			using rnd_arit=random_access::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using rnd_arit_unroll=typename rnd_arit::template unroll<N, M, L>;
	};
    }
   }
  }
 }
}

#endif
