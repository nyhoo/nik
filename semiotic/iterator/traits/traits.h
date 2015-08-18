/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef SEMIOTIC_ITERATOR_TRAITS_H
#define SEMIOTIC_ITERATOR_TRAITS_H

#include"../block/block.h"
//#include"../topos/topos.h"
//#include"../list/list.h"
//#include"../chain/chain.h"

/*
	The justification for this traits class is threefold:

	1) Is a modularization strategy toward mitigating the nested namespaces.
	2) in addition, if you look at the "fwd_arit_subroll" typedef ("using") declaration below for example,
		you will see it is also to ease the grammar constraints of C++ templates.
	3) It allows one to include the "traits.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
	namespace semiotic
	{
		namespace iterator
		{
/*
*/
			struct traits
			{
/*
	container:
*/
				template<typename ContainerType, typename ValueType, typename SizeType>
				struct container
				{
					typedef ContainerType type;
					typedef ContainerType* address;

					typedef ValueType value_type;
					typedef ValueType& reference;
					typedef ValueType const & const_reference;
					typedef ValueType* pointer;
					typedef ValueType const * const_pointer;

					typedef SizeType size_type;
				};
			};
		}
	}
}

#endif