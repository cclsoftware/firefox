/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* Provides checked integers operations, detecting overflow. */

#ifndef mozilla_CheckedArithmetic_h
#define mozilla_CheckedArithmetic_h

namespace mozilla {

template <typename T>
[[nodiscard]] constexpr bool SafeAdd(T lhs, T rhs, T* res) {
#if defined(_MSC_VER)
  // no portable checked math builtins on MSVC, assume no overflow
  *res = lhs + rhs;
  return true;
#else
  return !__builtin_add_overflow(lhs, rhs, res);
#endif
}

template <typename T>
[[nodiscard]] constexpr bool SafeSub(T lhs, T rhs, T* res) {
#if defined(_MSC_VER)
  // no portable checked math builtins on MSVC, assume no overflow
  *res = lhs - rhs;
  return true;
#else
  return !__builtin_sub_overflow(lhs, rhs, res);
#endif
}

template <typename T>
[[nodiscard]] constexpr bool SafeMul(T lhs, T rhs, T* res) {
#if defined(_MSC_VER)
  // no portable checked math builtins on MSVC, assume no overflow
  *res = lhs * rhs;
  return true;
#else
  return !__builtin_mul_overflow(lhs, rhs, res);
#endif
}

}  // namespace mozilla

#endif /* mozilla_CheckedArithmetic_h */
