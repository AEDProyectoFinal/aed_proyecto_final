#include <algorithm>
#include "nlohmann/json.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

using json = nlohmann::json; // Por que si coloco esto funciona ? lol

int main() {
	ifstream archivo("Twitter_API.json");
	json j;
	archivo >> j;
	cout << j.at("text") << endl;

	system("pause");
	return 0;
}