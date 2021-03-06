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

template<typename... Expressions>
struct tuple
{
	using rtn = tuple;

	using null = tuple<>;

//		Navigational:

	using car = typename Tuple::FS::template car<rtn>;

	using cdr = typename Tuple::FS::template cdr<rtn>;

//		Existential:

	template<typename E1>
	using equals = typename Constant::FS::template equal<rtn, E1>;

	using empty = typename Constant::FS::template empty<Expressions...>;

	using length = typename Tuple::FS::template length<rtn>;

//		Generational:

	template<typename Expression>
	using cons = typename Tuple::FS::template cons<Expression, rtn>;

	template<typename last>
	using push = typename Tuple::FS::template push<rtn, last>;

	template<typename E1>
	using prepend = typename Tuple::FS::template catenate<E1, rtn>;

	template<typename E1>
	using append = typename Tuple::FS::template catenate<rtn, E1>;

//		Translational:

	template<typename Type, Type... Values>
	using parameter = typename Tuple::FS::template parameter<Type, Values...>;
};

using null_tuple = tuple<>;

