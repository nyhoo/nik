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

template<typename Ordering, typename inBase, typename outBase = typename inBase::null>
struct fill;

/*
template<typename modifier, typename... params, Parameter... in_params, Parameter... out_params>
struct fill<base<modifier, params...>, base<in_params...>, base<out_params...>>
{
	struct modifer_contains
	{
		template<typename...> struct lambda;

		template<typename Front>
		struct lambda<Front> { static constexpr bool value = typename modifier::template contains<Front::value>::value; };
	};

	struct out_push
	{
		template<typename...> struct lambda;

		template<typename Front>
		struct lambda<Front> { using type = base<out_params..., Front::value>; };
	};

	static constexpr Parameter modifier_first = modifier::car::value;

	using inBase = base<in_params...>;

	using modifier_contains_in_first = apply<modifier_contains, typename inBase::car>;

	using outFront = apply<out_push, typename inBase::car>;

	//

	using in_base = typename block
	<
		if_then
		<
			typename inBase::empty,
			null_base

		>, else_then
		<
			modifier_contains_in_first,
			base<args...>

		>, then
		<
			base<front, args...>
		>

	>::type;

	//

	using out_base = typename block // can be reduced further.
	<
		if_then
		<
			typename inBase::empty,
			base<out_params..., first>

		>, else_then
		<
			contains_front,
			outFront

		>, then
		<
			base<out_params..., first>
		>

	>::type;

	//

	using type = typename fill<base<params...>, in_base, out_base>::type;
};
*/

template<typename modifier, typename... params, Parameter... in_params, Parameter... out_params>
struct fill<base<modifier, params...>, base<in_params...>, base<out_params...>>
{
	static constexpr Parameter first = modifier::car::value;

	//

	template<typename Base, typename Filler = void>
	struct safe_in;

	template<Parameter front, Parameter... args, typename Filler>
	struct safe_in<base<front, args...>, Filler>
	{
		using type = typename block
		<
			if_then
			<
				typename modifier::template contains<front>,
				base<args...>

			>, then
			<
				base<front, args...>
			>

		>::type;
	};

	template<typename Filler>
	struct safe_in<null_base, Filler>
	{
		using type = null_base;
	};

	using in_base = typename safe_in<base<in_params...>>::type;

	//


	template<typename Base, typename Filler = void>
	struct safe_out;

	template<Parameter front, Parameter... args, typename Filler>
	struct safe_out<base<front, args...>, Filler>
	{
		using type = typename block
		<
			if_then
			<
				typename modifier::template contains<front>,
				base<out_params..., front>

			>, then
			<
				base<out_params..., first>
			>

		>::type;
	};

	template<typename Filler>
	struct safe_out<null_base, Filler>
	{
		using type = base<out_params..., first>;
	};

	using out_base = typename safe_out<base<in_params...>>::type;

	//

	using type = typename fill<base<params...>, in_base, out_base>::type;
};

/*
	Assumes length<in> <= length<Ordering> and ends when empty<Ordering>. As such, it is implied empty<in> as well.
*/

template<Parameter... out_params>
struct fill<null_base, null_base, base<out_params...>>
{
	using type = base<out_params...>;
};

