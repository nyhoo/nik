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
namespace numeric	{

	template<typename SizeType>
	struct module<Module::list, Orientation::procedural, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		template<Orientation orientation_enum, Interface interface_enum>
		using variadic = grammaric::module<Module::variadic, orientation_enum, interface_enum, size_type>;

		template<typename enum_type>
		using parameter = typename variadic<Orientation::structural, Interface::semiotic>::template parameter<enum_type>;

		template<typename... params>
		using tuple = typename variadic<Orientation::structural, Interface::semiotic>::template tuple<params...>;

		template<typename L, size_type i>
		using at = typename variadic<Orientation::functional, Interface::semiotic>::template at<L, i>;

		template<typename Field, typename Relation, Relation... params>
		using sortFill = typename variadic<Orientation::functional, Interface::media>::template sortFill<Field, Relation, params...>;

		//

		using IterStrSem = module<Module::iterator, Orientation::structural, Interface::semiotic, size_type>;
		using IterAssoc = typename IterStrSem::Association;

		using IterProcSem = module<Module::iterator, Orientation::procedural, Interface::semiotic, size_type>;
		using IterConno = typename IterProcSem::Connotation;

		//

		template<Interface interface_enum>
		using structural = module<Module::list, Orientation::structural, interface_enum, size_type>;

		using Association = typename structural<Interface::semiotic>::Association;

		template<Association... params>
		using adj_list = typename structural<Interface::semiotic>::template adj_list<params...>;

		template<typename L>
		using Adjective = typename structural<Interface::semiotic>::template Adjective<L>;

		#include"adverb/semiotic.hpp"

		#include"grow/semiotic.hpp"
		#include"shrink/semiotic.hpp"
//		#include"insert/semiotic.hpp"
//		#include"erase/semiotic.hpp"
	};

}}

