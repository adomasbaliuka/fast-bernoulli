/**
 * \file cpuid.cc
 */

#include "cpuid.h"

#include <cstdint>
#include <cpuid.h>
#include <x86intrin.h>

namespace NFastBernoulli {

bool IsAVXSupported() noexcept {
    uint32_t eax, ebx, ecx, edx;
    __get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return static_cast<bool>(ecx & bit_AVX);
}

bool IsMMXSupported() noexcept {
    uint32_t eax, ebx, ecx, edx;
    __get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return static_cast<bool>(edx & bit_MMX);
}

bool IsSSESupported() noexcept {
    uint32_t eax, ebx, ecx, edx;
    __get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return static_cast<bool>(edx & bit_SSE);
}

} // namespace NFastBernoulli
