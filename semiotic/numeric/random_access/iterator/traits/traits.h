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

#ifndef NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_ITERATOR_TRAITS_H
#define NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_ITERATOR_TRAITS_H

#include"../node/node.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the depth complexity of nested namespaces.
	2) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
 namespace semiotic
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace iterator
    {
/*
*/
	template<typename SizeType>
	struct traits
	{
		typedef SizeType size_type;
/*
	node:
*/
		template<typename T, size_type N>
		using node=iterator::node<node_pointer<T, size_type, N> >;

		template<typename T, size_type N>
		using const_node=iterator::node<const_node_pointer<T, size_type, N> >;
	};
    }
   }
  }
 }
}

#endif
