/*
 * Copyright (c) 2023 Anthony J. Greenberg
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/// Extract a subset of records from a multi-sequence FASTA file
/** \file
 * \author Anthony J. Greenberg
 * \copyright Copyright (c) 2023 Anthony J. Greenberg
 * \version 0.1
 *
 * Definitions and interface documentation for the class that holds FASTA file data.
 *
 */

#pragma once

#include <cstddef>
#include <string>
#include <unordered_map>

namespace BayesicSpace {
	class Fasta;

	/** \brief Fasta file data
	 *
	 * Data read from a FASTA multi-sequence file. Sequence portions can be on multiple lines and do not have to be the same length for each sequence.
	 */
	class Fasta {
	public:
		/** \brief Default constructor */
		Fasta() = default;
		/** \brief Constructor with input file name 
		 *
		 * Takes the input file name and reads the data.
		 *
		 * \param[in] inFileName input FASTA file name
		 */
		Fasta(const std::string &inFileName);
		/** \brief Copy constructor 
		 *
		 * \param[in] toCopy object to copy
		 * \return copied object
		 */
		Fasta(const Fasta &toCopy) = default;
		/** \brief Copy assignment operator 
		 *
		 * \param[in] toCopy object to copy
		 * \return copied object
		 */
		Fasta& operator=(const Fasta &toCopy) = default;
		/** \brief Move constructor 
		 *
		 * \param[in] toMove object to move
		 * \return moved object
		 */
		Fasta(Fasta &&toCopy) = default;
		/** \brief Move assignment operator 
		 *
		 * \param[in] toMove object to move
		 * \return moved object
		 */
		Fasta& operator=(Fasta &&toMove) = default;
	protected:
		std::unordered_map<std::string, std::string> fastaData_;
	};
}
