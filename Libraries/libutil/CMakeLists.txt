#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

add_library(util SHARED
            Sources/FSUtil.cpp
            Sources/SysUtil.cpp
            Sources/Options.cpp
            #
            Sources/Subprocess.cpp
            #
            Sources/Escape.cpp
            Sources/Wildcard.cpp
            #
            Sources/bsd_glob.c
            #
            Sources/md5.c
            )

target_link_libraries(util PUBLIC)
target_include_directories(util PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

ADD_UNIT_GTEST(util FSUtil Tests/test_FSUtil.cpp)
ADD_UNIT_GTEST(util Wildcard Tests/test_Wildcard.cpp)
ADD_UNIT_GTEST(util Escape Tests/test_Escape.cpp)
