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

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct module<Module::bit, Orientation::structural, Interface::media, SizeType>
	{
		typedef SizeType size_type;

		template<Orientation orientation_enum, Interface interface_enum>
		using variadic = module<Module::variadic, orientation_enum, interface_enum, size_type>;

		template<typename enum_type>
		using parameter = typename variadic<Orientation::structural, Interface::semiotic>::template parameter<enum_type>;

		template<typename... params>
		using tuple = typename variadic<Orientation::structural, Interface::semiotic>::template tuple<params...>;

		//

		using functional = module<Module::bit, Orientation::functional, Interface::semiotic, size_type>;

		#include"mask/media.hpp"
	};

}}

