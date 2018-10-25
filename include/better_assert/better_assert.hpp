/**
 * Copyright 2018-present Antonio Mallia <me@antoniomallia.it>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#define _STRINGIZE_I(x) #x
#define _STRINGIZE(x) _STRINGIZE_I(x)


inline void _better_assert(const char *       condition,
                           const std::string &message,
                           const char *       fileline) {
    std::cerr << "[" << fileline << "] "
              << "Assertion `" << condition << "` failed.\n"
              << message << std::endl;

    std::abort();
}

#ifdef NDEBUG
#define better_assert(condition, message) static_cast<void>(0)
#else
#define better_assert(condition, message) \
    static_cast<bool>(condition)          \
        ? static_cast<void>(0)            \
        : _better_assert(#condition, message, __FILE__ ":" _STRINGIZE(__LINE__))
#endif
