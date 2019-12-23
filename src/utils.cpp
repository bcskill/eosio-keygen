/**
 * MIT License
 *
 * Copyright (c) 2019 EOS Sw/eden
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <algorithm>
#include <cctype>
#include "utils.h"

std::vector<std::string> strsplit(const std::string& str, const std::string& delim) {

	std::vector<std::string> r;
	size_t s = 0, e = 0, dlen = delim.length();

	while((e = str.find(delim, s)) != std::string::npos) {
		r.push_back(str.substr(s, e - s));
		s = e + dlen;
	}

	r.push_back(str.substr(s));
	return r;
}

void strtolower(std::string& str) {

	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
}

std::string& ltrim(std::string& str)
{
  auto it = std::find_if(str.begin(), str.end(), [](char ch){ return !std::isspace(ch); });
  str.erase(str.begin(), it);
  return str;
}

std::string& rtrim(std::string& str)
{
  auto it = std::find_if(str.rbegin(), str.rend(), [](char ch){ return !std::isspace(ch); });
  str.erase(it.base(), str.end());
  return str;
}


std::string& trim(std::string& str) {
	return ltrim(rtrim(str));
}