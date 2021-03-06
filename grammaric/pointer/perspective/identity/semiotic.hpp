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

struct identity
{
	struct eq_verb
	{
		bool rtn;

		eq_verb() : rtn(false) { }

		template<typename type_ptr>
		bool closing_pattern(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub == *ob);

			return !rtn;
		}

		template<typename type_ptr>
		void closed_pattern(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub == *ob);
		}
	};

	struct neq_verb
	{
		bool rtn;

		neq_verb() : rtn(true) { }

		template<typename type_ptr>
		bool closing_pattern(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub != *ob);

			return rtn;
		}

		template<typename type_ptr>
		void closed_pattern(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub != *ob);
		}
	};

template<Interval sub_interval, Direction sub_direction>
struct subject														{

template<Interval ob_interval, Direction ob_direction>
struct object														{

	using method =	typename generic::template
			subject<sub_interval, sub_direction>::template
			object<ob_interval, ob_direction>;

	template<typename type_ptr>
	static bool equals(type_ptr sub, type_ptr ob, type_ptr end)
	{
		eq_verb eq;

		method::compare(eq, sub, ob, end);

		return eq.rtn;
	}

	template<typename type_ptr>
	static bool not_equals(type_ptr sub, type_ptr ob, type_ptr end)
	{
		neq_verb neq;

		method::compare(neq, sub, ob, end);

		return neq.rtn;
	}

};};

};
