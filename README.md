# Felicia RPLidar

## WORKSPACE setup

```python
bind(
    name = "felicia",
    actual = "@com_github_chokobole_felicia//felicia:felicia",
)

bind(
    name = "felicia_rplidar",
    actual = "@com_github_chokobole_felicia_rplidar//:rplidar",
)

git_repository(
    name = "com_github_chokobole_felicia",
    remote = "https://github.com/chokobole/felicia.git",
    commit = "<commit>",
)

git_repository(
    name = "com_github_chokobole_felicia_rplidar",
    remote = "https://github.com/chokobole/felicia-rplidar.git",
    commit = "<commit>",
)

load("@com_github_chokobole_felicia//bazel:felicia_deps.bzl", "felicia_deps")

felicia_deps()

load("@com_github_chokobole_felicia_rplidar//:rplidar_deps.bzl", "rplidar_deps")

rplidar_deps()
```

## Example

```python
load("@com_github_chokobole_felicia//bazel:felicia_cc.bzl", "fel_cc_native_binary")

fel_cc_native_binary(
    name = "<name>",
    ...,
    deps = [
        "//external:felicia_rplidar",
    ],
)
```

Check out examples [here](https://github.com/chokobole/felicia-examples/blob/master/examples/learn/topic/lidar/cc/BUILD).