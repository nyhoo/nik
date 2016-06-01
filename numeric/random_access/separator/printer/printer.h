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

#ifndef NIK_NUMERIC_RANDOM_ACCESS_PRINTER_H
#define NIK_NUMERIC_RANDOM_ACCESS_PRINTER_H

#include"../../processor/policy/policy.h"

//#include"../list/structural/traits/traits.h"
//#include"../traits/structural/traits/traits.h"
//#include"../vector/structural/traits/traits.h"

namespace nik
{
 namespace numeric
 {
  namespace random_access
  {
	template<typename SizeType>
	struct printer
	{
		typedef SizeType size_type;

		typedef processor::policy<size_type> p_policy;

		#include"media.cpp"
	};
  }
 }
}

#endif