#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <map>
#include <set>

using namespace std;

class Cities {
public:
    tuple<bool, string> FindCountry(const string& city) const {
        if (city_to_country.count(city) == 1) {
            return {true, city_to_country.at(city)}; // убрал квадратные скобки и обратился к словарю с помощью at, благодаря чему объект, который отстутсвует в словаре не добавляется в словарь
        } else if (ambiguous_cities.count(city) == 1) {
            return {false, "Ambiguous"};
        } else {
            return {false, "Not exists"};
        }
    }
private:
    map<string, string> city_to_country;
    set<string> ambiguous_cities;
};

int main() {
    Cities cities;
    auto t = cities.FindCountry("Volgograd");
    cout << get<1>(t) << endl; // Not exists
    return 0;
}