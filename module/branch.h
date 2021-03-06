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

#ifndef GRAMMARIC_BRANCH_H
#define GRAMMARIC_BRANCH_H

#include"constant.h"

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct BranchModule
	{
		using FS = module
		<
			Module::	branch,
			Orientation::	functional,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Branch_import_conditional()								\
															\
			template<typename P, typename E1, typename E2>							\
			using conditional = typename Branch::FS::template conditional<P, E1, E2>;

		#define grammaric_Branch_import_block()									\
															\
			template<typename P, typename E>								\
			using if_then = typename Branch::FS::template if_then<P, E>;					\
															\
			template<typename P, typename E>								\
			using else_then = typename Branch::FS::template else_then<P, E>;				\
															\
			template<typename E>										\
			using then = typename Branch::FS::template then<E>;						\
															\
			template<typename... E>										\
			using block = typename Branch::FS::template block<E...>;
	};

}}

#include"../grammaric/branch/functional/semiotic.h"
#include"../grammaric/branch/functional/media.h"

#endif
