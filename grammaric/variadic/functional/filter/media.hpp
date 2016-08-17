/************************************************************************************************************************
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
************************************************************************************************************************/

template<size_type t>
struct lessThanOrEqual
{
	static constexpr bool test(size_type current)
	{
		return (current <= t);
	}
};

template<size_type t>
struct greaterThanOrEqual
{
	static constexpr bool test(size_type current)
	{
		return (current >= t);
	}
};

template<typename predicate, typename in>
struct filter
{
	using rtn = typename semiotic::template filter<predicate, typename in::null, in>::rtn;
};
