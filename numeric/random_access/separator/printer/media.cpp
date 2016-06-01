/*************************************************************************************************************************
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
*************************************************************************************************************************/

/*
template<typename T>
void print(const list<T, size_type> & l)
{
	for (typename list<T, size_type>::const_iterator k=l.begin(); k != l.end(); ++k)
		p_policy::printer << *k << ' ';
}

template<typename T>
void print(const chain<T, size_type> & c)
{
	for (typename chain<T, size_type>::const_iterator k=c.begin(); k != c.end(); ++k)
		p_policy::printer << *k << ' ';
}

template<typename T>
void print(const vector<T, size_type> & v)
{
	for (typename vector<T, size_type>::const_iterator k=v.begin(); k != v.end(); ++k)
		p_policy::printer << *k << ' ';
}
*/

/*
template<typename ValueType>
void print(const node<ValueType> & n)
{
	printf("%zu", u);
}

template<size_type N>
void print(const uint<N> & u)
{
	node<size_type> n;
	while (!u.zero())
	{
		bwd_arit::unroll<u::dimension>::divide::
		n.append();
	}

	print(n);
}
*/

/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
template<size_t N, size_t M=0, size_t L=0>
struct unroll
{
	template<typename Iterator>
	static void block(Iterator i, const char *format)
	{
		printf(format, *i);
		unroll<N-1>::block(--i, format);
	}
};

template<size_t M, size_t L>
struct unroll<0, M, L>
{
	template<typename Iterator>
	static void block(Iterator i, const char *format)
		{ }
};

template<typename Block> void print(const Block & v)
	{ unroll<Block::dimension>::block(v.end()-1, "%zu "); }
*/
