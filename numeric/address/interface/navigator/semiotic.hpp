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

/*
	address type		:= (0 + 1)^np;
	address instance	:= m^i/m^j/s^k = m^i/m^j/s^l -> k = l;

	binary type assumes operators: ;

	Navigators may be optimized as they have limited perspectives.
*/

template<typename Bit, size_type length, Access access = Access::readwrite>
class word_navigator
{
	public:
		using type		= word_navigator;

	protected:
		using type_ptr		= type*;
		using type_ref		= type&;

		using bit_type		= typename read_type<Bit, access>::rtn;
		using bit_type_ptr	= bit_type*;
		using bit_type_ref	= bit_type&;

		using const_type	= word_navigator<Bit, length, Access::readonly>;

		bit_type_ptr location;
	public:
		word_navigator(bit_type_ptr l) : location(l) { }

		~word_navigator() { }

		operator const_type () const
		{
			return (const_type) this;
		}

		bool operator == (const type_ref w) const
		{
			return location == w.location;
		}

		bool operator != (const type_ref w) const
		{
			return location != w.location;
		}

		bit_type_ref operator * () const
		{
			return *location;
		}

		type_ref operator ++ ()
		{
			++location;

			return *this;
		}

		type operator ++ (int)
		{
			return location++;
		}

		type_ref operator += (size_type n)
		{
			location += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return location + n;
		}

		type_ref operator -- ()
		{
			--location;

			return *this;
		}

		type operator -- (int)
		{
			return location--;
		}

		type_ref operator -= (size_type n)
		{
			location -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return location - n;
		}
};

