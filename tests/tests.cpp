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

/// Unit tests
/** \file
 * \author Anthony J. Greenberg
 * \copyright Copyright (c) 2023 Anthony J. Greenberg
 * \version 0.1
 *
 * Unit tests using Catch2.
 *
 */

#include <string>
#include <unordered_map>
#include <vector>

#include "fastaObj.hpp"
#include "utilities.hpp"

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

TEST_CASE("Can subset FASTA records", "[subset]") {
	SECTION("Exceptions on wrong data") {
		const std::string emptyFile("../tests/empty.fasta");
		REQUIRE_THROWS_WITH(BayesicSpace::Fasta(emptyFile), 
				Catch::Matchers::StartsWith("ERROR: input FASTA file "));
		const std::string wrongFormat("../tests/wrong.fasta");
		REQUIRE_THROWS_WITH(BayesicSpace::Fasta(wrongFormat), 
				Catch::Matchers::StartsWith("ERROR: first line of a FASTA file must begin with "));
	}
	SECTION("Operation on correct data") {
		const std::string testFAfile("../tests/test.fasta");
		BayesicSpace::Fasta testFA(testFAfile);
		const std::vector<std::string>subset{"B.FR.1983.LAI-J19.A07867",
											"B.US.1997.ARES2.AB078005",
											"randomValue",
											"01B.MM.1999.mCSW104.AB097867"
		};
		std::unordered_map<std::string, std::string> vecResult{testFA.subset(subset)};
		REQUIRE(vecResult.size() == subset.size() - 1);
	}
}
