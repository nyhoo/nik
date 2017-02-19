/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename E1, typename E2>
struct at
{
	template<typename, size_type> struct strict;

	template<typename Type, Type... v, typename... constants, size_type index>
	struct strict<t<c<Type, v...>, constants...>, index>
	{
		using rtn = typename strict<t<constants...>, index-1>::rtn;
	};

	template<typename Type, Type... v, typename... constants>
	struct strict<t<c<Type, v...>, constants...>, 0>
	{
		using rtn = c<Type, v...>;
	};

	using rtn = typename strict
	<
		typename E1::rtn,
		E2::rtn::value

	>::rtn;
};

