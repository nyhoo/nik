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


#define DEFAULT		LIST<directionEnum, imageEnum, iteratorEnum>
#define DEALLOCATE	LIST<directionEnum, Association::deallocate, iteratorEnum>


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type directionEnum,
	size_type imageEnum,
	size_type iteratorEnum
>
static void memory_action(pointer in, const ObjectAdjective<DEFAULT> & adj)
	{ }


/***********************************************************************************************************************/


template<typename pointer, size_type directionEnum, size_type iteratorEnum>
static void memory_action(pointer in, const ObjectAdjective<DEALLOCATE> & adj)
{
	delete in;
}


