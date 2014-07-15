// g++ -Wall -g -o regex{,.cpp} $(pkg-config --cflags --libs glibmm-2.4)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <glibmm/ustring.h>
#include <glibmm/regex.h>

int main (int argc, char *argv[])
{
	Glib::ustring text = "volumes 1 1 wz--n- 1000203091968 0 pzzgUG-I1YG-QT26-5f0L-UTGP-HSOn-M8Ck6S 4194304 238467 0 2";
	Glib::ustring pattern = "([a-z0-9/]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+) +([^ ]+)$";

	std::cout << text << std::endl;

	std::vector<Glib::ustring> results;
	Glib::RefPtr<Glib::Regex> myregexp = Glib::Regex::create (pattern);

	results = myregexp->split (text);
	printf ("\t%ld columns\n", results.size());
	for (unsigned int i = 0; i < results.size(); i++) {
		printf ("\t\t>>%s<<\n", results[i].c_str());
	}

	return 0;
}

