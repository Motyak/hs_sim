#include <iostream>
#include <iomanip>
#include <random>
#include <cstdint>

#define LEN(x) (sizeof(x)/sizeof((x)[0]))

#define unless(x) if(!(x))

struct Rarity {
    std::string str;
    double prob;
};

std::vector<Rarity> table = {
    {"Common", 0.6997},
    {"Rare", 0.2284},
    {"Epic", 0.0428},
    {"Golden Common", 0.0147},
    {"Legendary", 0.0108},
    {"Golden Rare", 0.0028},
    {"Golden Epic", 0.0007},
    {"Golden Legendary", 0.0001},
};

std::vector<Rarity> table2 = {
    {"Common", 0.0000},
    {"Rare", 0.7729},
    {"Epic", 0.1448},
    {"Golden Common", 0.0000},
    {"Legendary", 0.0365},
    {"Golden Rare", 0.0338},
    {"Golden Epic", 0.0091},
    {"Golden Legendary", 0.0027},
};

uint64_t seed;
uint64_t a = 48271;
uint64_t m = 2147483647; // nombre premier de Mersenne (2^31 - 1)

// return between 0.0 and 1.0
double myrand() {
    seed = seed * a % m;
    return double(seed) / m;
}

int main() {
    {
        std::random_device rd;
        seed = rd() % (m - 1) + 1;
        // seed = 820977577;
        std::cout << "seed: " << seed << std::endl;
    }

    Rarity rolled[5] = {};
    for (int i = 0; i < LEN(rolled); ++i) {
        auto rand = myrand();
        auto acc = 0.0;
        for (const auto& rarity: table) {
            acc += rarity.prob;
            if (rand <= acc) {
                rolled[i] = rarity;
                break;
            }
        }
    }

    bool all_common = true;
    for (int i = 0; i < LEN(rolled); ++i) {
        all_common &= rolled[i].str == "Common" || rolled[i].str == "Golden Common";
    }

    if (all_common)
    {
        auto rand = myrand();
        auto acc = 0.0;
        for (int i = 0; i < 5; i += 1) {
            acc += 0.20;
            if (rand <= acc) {
                auto rand = myrand();
                auto acc = 0.0;
                for (const auto& rarity: table2) {
                    acc += rarity.prob;
                    if (rand <= acc) {
                        rolled[i] = rarity;
                        break;
                    }
                }
                break;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < 5; ++i) {
        std::cout << rolled[i].str << std::endl;
    }
}
