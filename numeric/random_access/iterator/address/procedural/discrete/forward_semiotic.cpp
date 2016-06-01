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
	For the "natural" right_shift,
	define in2 = ++RIterator(in1),
	as well as n = p_policy::unit::length-m,
	finally, *out=(*in1>>m) needs appending.
*/

struct right_shift
{
/*
	template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator>
	static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator end, size_type m, size_type n)
	{
		while (in2 != end)
		{
			*out=(*in1>>m)+(*in2<<n);
			++out; ++in1; ++in2;
		}
	}

	template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator>
	static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator end, size_type m, size_type n)
	{
		while (in2 != end)
		{
			*out=(*in1>>m)+(*in2<<n);
			++out; ++in1; ++in2;
		}

		return out;
	}
*/
};

struct assign
{
/*
	For the "natural" right_shift,
	define in2 = ++RIterator(in1),
	as well as n = p_policy::unit::length-m,
	finally, *out=(*in1>>m) needs appending.
	struct right_shift
	{
		template<typename WIterator, typename RIterator, typename ERIterator>
		static void no_return(WIterator out, RIterator in, ERIterator end, size_type m, size_type n)
		{
			while (in != end)
			{
				(*out>>=m)+=(*in<<n);
				++out; ++in;
			}
		}

		template<typename WIterator, typename RIterator, typename ERIterator>
		static WIterator with_return(WIterator out, RIterator in, ERIterator end, size_type m, size_type n)
		{
			while (in != end)
			{
				(*out>>=m)+=(*in<<n);
				++out; ++in;
			}

			return out;
		}
	};
*/
};

struct convert
{
/*
	Not fully satisfied with the categorization or naming scheme within this library.
	template<typename WIterator, typename RIterator, typename ERIterator>
	static void no_return(WIterator out, RIterator in, ERIterator end)
	{
		while (in != end)
		{
			*out=(p_policy::unit::low_pass & *in);
			*++out=*in>>p_policy::unit::half::length;
			++out; ++in;
		}
	}

	template<typename WIterator, typename RIterator, typename ERIterator>
	static WIterator with_return(WIterator out, RIterator in, ERIterator end)
	{
		while (in != end)
		{
			*out=(p_policy::unit::low_pass & *in);
			*++out=*in>>p_policy::unit::half::length;
			++out; ++in;
		}

		return out;
	}

	struct half
	{
		template<typename WIterator, typename RIterator, typename ERIterator>
		static void no_return(WIterator out, RIterator in, ERIterator end)
		{
			while (in != end)
			{
				*out=*in;
				*out+=(*++in<<p_policy::unit::half::length);
				++out; ++in;
			}
		}

		template<typename WIterator, typename RIterator, typename ERIterator>
		static WIterator with_return(WIterator out, RIterator in, ERIterator end)
		{
			while (in != end)
			{
				*out=*in;
				*out+=(*++in<<p_policy::unit::half::length);
				++out; ++in;
			}

			return out;
		}
	};
*/
};

template<size_type N, size_type M=0, size_type L=0>
struct unroll
{
	struct convert
	{
/*
	Not fully satisfied with the categorization or naming scheme within this library.
		template<typename WIterator, typename RIterator>
		static void no_return(WIterator out, RIterator in)
		{
			*out=(p_policy::unit::low_pass & *in);
			*++out=*in>>p_policy::unit::half::length;
			unroll<N-1>::convert::no_return(++out, ++in);
		}

		template<typename WIterator, typename RIterator>
		static WIterator with_return(WIterator out, RIterator in)
		{
			*out=(p_policy::unit::low_pass & *in);
			*++out=*in>>p_policy::unit::half::length;
			return unroll<N-1>::convert::with_return(++out, ++in);
		}

		struct half
		{
			template<typename WIterator, typename RIterator>
			static void no_return(WIterator out, RIterator in)
			{
				*out=*in;
				*out+=(*++in<<p_policy::unit::half::length);
				unroll<N-1>::convert::half::no_return(++out, ++in);
			}

			template<typename WIterator, typename RIterator>
			static WIterator with_return(WIterator out, RIterator in)
			{
				*out=*in;
				*out+=(*++in<<p_policy::unit::half::length);
				return unroll<N-1>::convert::half::with_return(++out, ++in);
			}
		};

	};

	struct right_shift
	{
/*
	For the "natural" right_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = ++RIterator(in1),
	as well as n = p_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1>>m); }.
	Do not add (*in2<<n) as in this specialization, in2 may be past the boundary.
		template<typename WIterator, typename RIterator1, typename RIterator2>
		static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
		{
			*out=(*in1>>m)+(*in2<<n);
			unroll<N-1>::right_shift::no_return(++out, ++in1, ++in2, m, n);
		}

		template<typename WIterator, typename RIterator1, typename RIterator2>
		static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
		{
			*out=(*in1>>m)+(*in2<<n);
			return unroll<N-1>::right_shift::with_return(++out, ++in1, ++in2, m, n);
		}
*/
	};

	struct assign
	{
		struct right_shift
		{
/*
	For the "natural" right_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = ++RIterator(in1),
	as well as n = p_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out>>=m); }.
	Do not add (*in<<n) as in this specialization, in2 may be past the boundary.
			template<typename RWIterator, typename RIterator>
			static void no_return(RWIterator out, RIterator in, size_type m, size_type n)
			{
				(*out>>=m)+=(*in<<n);
				unroll<N-1>::assign::right_shift::no_return(++out, ++in, m, n);
			}

			template<typename RWIterator, typename RIterator>
			static RWIterator with_return(RWIterator out, RIterator in, size_type m, size_type n)
			{
				(*out>>=m)+=(*in<<n);
				return unroll<N-1>::assign::right_shift::with_return(++out, ++in, m, n);
			}
*/
		};
	};
};

template<size_type M, size_type L>
struct unroll<0, M, L>
{
	struct convert
	{
/*
		template<typename WIterator, typename RIterator>
		static void no_return(WIterator out, RIterator in)
			{ }

		template<typename WIterator, typename RIterator>
		static WIterator with_return(WIterator out, RIterator in)
			{ return out; }

		struct half
		{
			template<typename WIterator, typename RIterator>
			static void no_return(WIterator out, RIterator in)
				{ }

			template<typename WIterator, typename RIterator>
			static WIterator with_return(WIterator out, RIterator in)
				{ return out; }
		};
*/
	};

	struct right_shift
	{
/*
		template<typename WIterator, typename RIterator1, typename RIterator2>
		static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
			{ }

		template<typename WIterator, typename RIterator1, typename RIterator2>
		static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
			{ return out; }
*/
	};

	struct assign
	{
		struct right_shift
		{
/*
			template<typename RWIterator, typename RIterator>
			static void no_return(RWIterator out, RIterator in, size_type m, size_type n)
				{ }

			template<typename RWIterator, typename RIterator>
			static RWIterator with_return(RWIterator out, RIterator in, size_type m, size_type n)
				{ return out; }
*/
		};
	};
};
