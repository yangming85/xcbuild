#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

build := build

cmake := cmake
cmake_flags := -G Ninja

ninja := $(if $(shell which llbuild),llbuild ninja build,ninja)
ninja_flags := $(if $(shell echo "$$NINJA_JOBS"),-j$(shell echo "$$NINJA_JOBS"),)

all:
	mkdir -p $(build)
	$(cmake) -B$(build) -H. $(cmake_flags)
	$(ninja) -C $(build) $(ninja_flags)

test: all
	set -e; for test in build/test_*; do echo; echo "$$test"; ./$$test; done

clean:
	rm -rf $(build)

