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
 * \version 0.5
 *
 * Implementation of the class that holds FASTA file data.
 *
 */

#include <cstddef>
#include <string>
#include <unordered_map>
#include <fstream>

#include "fastaObj.hpp"

using namespace BayesicSpace;

Fasta::Fasta(const std::string &inFileName) {
	std::fstream inFASTA;
	std::string eachLine;
	inFASTA.open(inFileName, std::ios::in);
	std::getline(inFASTA, eachLine);
	if ( eachLine.empty() ) {
		throw std::string("ERROR: input FASTA file ") + inFileName + std::string(" empty in ")
										+ std::string( static_cast<const char*>(__PRETTY_FUNCTION__) );
	}
	if (eachLine.front() != '>') {
		throw std::string("ERROR: first line of a FASTA file must begin with '>' in ") + std::string( static_cast<const char*>(__PRETTY_FUNCTION__) );
	}
	std::string currentHeader = eachLine.substr(1); // remove the starting '>'
	std::string sequence;
	while ( std::getline(inFASTA, eachLine) ) {
		if (eachLine.front() == '>') {
			fastaData_.emplace(currentHeader, sequence);
			currentHeader = eachLine.substr(1);
			sequence.clear();
			continue;
		}
		sequence.append(eachLine);
	}
	fastaData_.emplace(currentHeader, sequence);
	inFASTA.close();
}

std::unordered_map<std::string, std::string> Fasta::subset(const std::vector<std::string> &headerList) const {
	std::unordered_map<std::string, std::string> subset;
	for (const auto &eachHeader : headerList) {
		auto search = fastaData_.find(eachHeader);
		if ( search != fastaData_.end() ) {
			subset.emplace(search->first, search->second);
		}
	}
	return subset;
}
std::unordered_map<std::string, std::string> Fasta::subset(const std::string &headerFileName) const {
	std::fstream inSubsetList;
	inSubsetList.open(headerFileName, std::ios::in);
	std::vector<std::string> headers;
	std::string eachLine;
	while ( std::getline(inSubsetList, eachLine) ) {
		if ( !eachLine.empty() ) {
			headers.emplace_back( eachLine.substr( static_cast<size_t>(eachLine.at(0) == '>') ) );      // remove starting '>' if exists
		}
	}
	inSubsetList.close();
	return this->subset(headers);
}
