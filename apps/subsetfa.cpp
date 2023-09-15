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

/// Extract records from a FASTA file
/** \file
 * \author Anthony J. Greenberg
 * \copyright Copyright (c) 2023 Anthony J. Greenberg
 * \version 0.1
 *
 * Uses the fastaObj methods to extract records from a multi-record FASTA file.
 * Records must be listed in a separate file as FASTA headers that match some in the FASTA file.
 *
 */

#include <cstdlib>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

#include "fastaObj.hpp"
#include "utilities.hpp"

int main(int argc, char *argv[]) {
	// set usage message
	const std::string cliHelp = "Available command line flags (in any order):\n" 
		"  --input-fasta   file_name (input multi-record FASTA file name; required).\n" 
		"  --header-list   subset_file_name (list of FASTA headers to extract; required).\n"
		"                  The header list must one whole FASTA header per line,\n"
		"                  with or without the leading '>'.\n"
		"  --out-file      out_file_name (output file name; default is 'subset.fasta').\n";

	try {
		std::unordered_map <std::string, std::string> clInfo;
		std::unordered_map <std::string, std::string> stringVariables;
		BayesicSpace::parseCL(argc, argv, clInfo);
		BayesicSpace::extractCLinfo(clInfo, stringVariables);

		BayesicSpace::Fasta fastaData( stringVariables.at("input-fasta") );
	} catch(std::string &problem) {
		std::cerr << problem << "\n";
		std::cerr << cliHelp;
		return 1;
	}
	return 0;
}
