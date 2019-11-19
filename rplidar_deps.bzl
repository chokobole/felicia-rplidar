# Copyright (c) 2019 The Felicia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "git_repository",
    "new_git_repository"
)

def rplidar_deps():
    native.bind(
        name = "felicia",
        actual = "@com_github_chokobole_felicia//felicia:felicia",
    )

    native.bind(
        name = "rplidar",
        actual = "@com_github_slamtec_rplidar_sdk//:rplidar_sdk",
    )

    if not native.existing_rule("com_github_chokobole_felicia"):
        git_repository(
            name = "com_github_chokobole_felicia",
            remote = "https://github.com/chokobole/felicia.git",
            commit = "c07f4d588fe628c362805a3ba9e5688437661436",
        )

    if not native.existing_rule("com_github_slamtec_rplidar_sdk"):
        new_git_repository(
            name = "com_github_slamtec_rplidar_sdk",
            remote = "https://github.com/Slamtec/rplidar_sdk.git",
            commit = "25d34dbfbcb4de9046a31d366fc734c5c09a69f7",  # release/v1.11.0 + patch
            build_file = "@com_github_chokobole_felicia_rplidar//third_party:rplidar_sdk.BUILD",
            patch_args = ["-p1"],
            patches = ["@com_github_chokobole_felicia_rplidar//third_party:rplidar_sdk.patch"],
        )