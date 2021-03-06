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

#ifndef GRAMMARIC_CONSTANT_H
#define GRAMMARIC_CONSTANT_H

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct ConstantModule
	{
		using SS = module
		<
			Module::	constant,
			Orientation::	structural,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Constant_import_constant()								\
															\
			template<typename Type, Type... Value>								\
			using constant = typename Constant::SS::template constant<Type, Value...>;

		#define grammaric_Constant_import_boolean()								\
															\
			template<bool Value>										\
			using boolean = typename Constant::SS::template boolean<Value>;

		using FS = module
		<
			Module::	constant,
			Orientation::	functional,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Constant_import_empty()								\
															\
			template<typename... Exps>									\
			using empty = typename Constant::FS::template empty<Exps...>;

		#define grammaric_Constant_import_is_constant()								\
															\
			template<typename Exp>										\
			using is_constant = typename Constant::FS::template is_constant<Exp>;

		#define grammaric_Constant_import_equal()								\
															\
			template<typename Exp1, typename Exp2>								\
			using equal = typename Constant::FS::template equal<Exp1, Exp2>;

		#define grammaric_Constant_import_less_than()								\
															\
			template<typename Exp1, typename Exp2>								\
			using less_than = typename Constant::FS::template less_than<Exp1, Exp2>;

		#define grammaric_Constant_import_less_than_or_equal()							\
															\
			template<typename Exp1, typename Exp2>								\
			using less_than_or_equal = typename Constant::FS::template less_than_or_equal<Exp1, Exp2>;

		#define grammaric_Constant_import_greater_than()							\
															\
			template<typename Exp1, typename Exp2>								\
			using greater_than = typename Constant::FS::template greater_than<Exp1, Exp2>;

		#define grammaric_Constant_import_greater_than_or_equal()						\
															\
			template<typename Exp1, typename Exp2>								\
			using greater_than_or_equal = typename Constant::FS::template greater_than_or_equal<Exp1, Exp2>;

/***********************************************************************************************************************/

		#define grammaric_Constant_import_Not()									\
															\
			template<typename Exp>										\
			using Not = typename Constant::FS::template Not<Exp>;

		#define grammaric_Constant_import_And()									\
															\
			template<typename Exp1, typename Exp2, typename... Exps>					\
			using And = typename Constant::FS::template And<Exp1, Exp2, Exps...>;

		#define grammaric_Constant_import_Or()									\
															\
			template<typename Exp1, typename Exp2, typename... Exps>					\
			using Or = typename Constant::FS::template Or<Exp1, Exp2, Exps...>;
	};

}}

#include"../grammaric/constant/structural/semiotic.h"
#include"../grammaric/constant/structural/media.h"

#include"../grammaric/constant/functional/semiotic.h"
#include"../grammaric/constant/functional/media.h"

#endif
