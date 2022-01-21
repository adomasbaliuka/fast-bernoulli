//
// Created by alice on 21.01.22.
//
#include <iostream>
#include <fast-bernoulli/fast-bernoulli.h>

using namespace NFastBernoulli;

int main() {
// Assume 65536 bits with probability 0.6 should be generated.
    auto probability = 0.6;
    auto nobits = 65536;

// Create an instance of ISampler and make buffer for sampling.
    auto sampler = CreateSampler(probability);
    auto ptr = sampler.MakeBuffer(nobits);

// Use Mersenne Twister as a pseudo-random number generator.
    std::mt19937_64 rng;

// Draw samples from Bernoulli distribution.
    sampler(rng, ptr);

// Expand compressed representation of random values to vector of bools.
    auto values = Expand(ptr, nobits);
    for (auto v : values) {
        std::cout << v << ' ';
    }
}
