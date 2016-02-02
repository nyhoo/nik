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

#ifndef CONTEXT_CONTEXT_PARAMETER_MATH_H
#define CONTEXT_CONTEXT_PARAMETER_MATH_H

#include"../../unit/unit.h"
#include"../meta/meta.h"

namespace nik
{
 namespace context
 {
  namespace context
  {
   namespace parameter
   {
	template<typename size_type>
	struct math
	{
		typedef context::unit<size_type> unit;

		template<size_type x>
		struct square
			{ enum : size_type { value=x*x }; };

		template<size_type base, size_type exponent>
		struct exp
		{
			template<size_type primary, size_type secondary, size_type n>
			struct fast_exp
			{
				enum : size_type
				{
					value=meta::if_then_else<(unit::one & n),
						fast_exp<primary*secondary, secondary, n-unit::one>,
						fast_exp<primary, square<secondary>::value, (n>>unit::one)>
							>::return_type::value
				};
			};

			template<size_type primary, size_type secondary>
			struct fast_exp<primary, secondary, unit::zero> { enum : size_type { value=primary }; };

			enum : size_type { value=fast_exp<unit::one, base, exponent>::value };
		};
	};
   }
  }
 }
}

#endif