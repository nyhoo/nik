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

template<typename Type, Type v>
struct c
{
	using type = Type;

	static constexpr Parameter value = v;
};

template<bool B> struct boolean
{
	struct rtn
	{
		static constexpr bool value = B;
	};
};

template<typename Parameter>
struct parameter
{
	template<Parameter v>
	struct constant
	{
		struct rtn
		{
			static constexpr Parameter value = v;
		};
	};

	template<Parameter... params>
	struct list
	{
		using rtn = list;
	};

	using null_list = list<>;
};

template<typename T>
struct kind
{
	struct rtn
	{
		using type = T;
	};
};

