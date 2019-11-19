# Copyright (c) 2019 The Felicia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

load("@com_github_chokobole_felicia//bazel:felicia_cc.bzl", "fel_cc_native_library")

fel_cc_native_library(
    name = "rplidar",
    srcs = [
        "rplidar/rplidar_factory.cc",
        "rplidar/rplidar.cc",
    ],
    hdrs = [
        "rplidar/rplidar_factory.h",
        "rplidar/rplidar.h",
    ],
    deps = [
        "//external:felicia",
        "//external:rplidar",
    ],
    visibility = ["//visibility:public"],
)
