/**
 * \file cpuid.h
 */

#pragma once

namespace NFastBernoulli {

bool IsAVXSupported() noexcept;
bool IsMMXSupported() noexcept;
bool IsSSESupported() noexcept;

} // namespace NFastBernoulli
