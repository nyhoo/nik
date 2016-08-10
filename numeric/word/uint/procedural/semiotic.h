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

#ifndef NIK_NUMERIC_WORD_UINT_PROCEDURAL_SEMIOTIC_H
#define NIK_NUMERIC_WORD_UINT_PROCEDURAL_SEMIOTIC_H

namespace nik		{
namespace numeric	{
namespace word		{
namespace uint		{
namespace procedural	{

	template<typename SizeType> struct media;

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef grammaric::control_flow::functional::media<size_type> gcf_media;
		typedef functional::semiotic<size_type> f_semiotic;

		typedef functional::media<size_type> media;

		#include"overload/semiotic.hpp"
		#include"discrete/semiotic.hpp"
//		#include"math/semiotic.hpp"
		#include"sift/semiotic.hpp"
	};

}}}}}

#endif
