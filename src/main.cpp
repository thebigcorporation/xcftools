/*******************************************************************************
 * Copyright (C) 2022-2023 Olivier Delaneau
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#define _DECLARE_TOOLBOX_HERE
#include <viewer/viewer_header.h>
#include <concat/concat_header.h>

#include "../versions/versions.h"

using namespace std;

int main(int argc, char ** argv) {
	vector < string > args;

	string mode = (argc>1)?string(argv[1]):"";

	if (argc == 1 || (mode != "view" && mode != "concat")) {

		vrb.title("[XCFtools] Manage XCF files");
		vrb.bullet("Authors       : Olivier DELANEAU and Simone RUBINACCI");
		vrb.bullet("Contact       : olivier.delaneau@gmail.com");
		vrb.bullet("Version       : 0." + string(XCFTLS_VERSION) + " / commit = " + string(__COMMIT_ID__) + " / release = " + string (__COMMIT_DATE__));
		vrb.bullet("Run date      : " + tac.date());

		//List possible modes
		vrb.title("Supported modes:");
		vrb.bullet("[view]\t| Converts between XCF and BCF files");
		vrb.bullet("[concat]\t| Concat multiple XCF files together");

	} else {
		//Get args
		for (int a = 2 ; a < argc ; a ++) args.push_back(string(argv[a]));

		//
		string mode = string(argv[1]);

		if (mode == "view") {
			viewer().view(args);
		} else if (mode == "concat") {
			concat().concatenate(args);
		}
	}
	return 0;
}

