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


// Adjective Associations:


struct Association
{
	enum : size_type
	{
		closing,
		closed,
		opening,
		open,

		dimension
	};
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Adjective Attributes:
*/


struct Attribute
{
	enum : size_type
	{
		interval,

		dimension
	};
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L>
struct Adjective
{
	using parameter_list = L;

	static constexpr size_type interval_enum	= AT<L, Association::interval	>::rtn;

	Adjective() { }
};



