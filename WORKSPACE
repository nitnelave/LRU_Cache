workspace(name = "com_github_nitnelave_lru_cache")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# rules for c++
http_archive(
    name = "rules_cc",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/4c3e410486a078d6492baeaebb406ce4d20e3164.tar.gz"],
    strip_prefix = "rules_cc-4c3e410486a078d6492baeaebb406ce4d20e3164",
    sha256 = "abe679f9a6513a72d73f09f96318b0060770fdc93695a6cd766550b492ce6ef1",
)

# abseil-cpp
http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/c512f118dde6ffd51cb7d8ac8804bbaf4d266c3a.zip"],
  strip_prefix = "abseil-cpp-c512f118dde6ffd51cb7d8ac8804bbaf4d266c3a",
  sha256 = "8400c511d64eb4d26f92c5ec72535ebd0f843067515244e8b50817b0786427f9",
)

# catch2
http_archive(
    name = "com_github_catchorg_catch2",
    build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")
cc_library(
  name = "catch2",
  hdrs = ["single_include/catch2/catch.hpp"],
  visibility = ["//visibility:public"],
  includes = ["single_include/"],
)""",
    urls = ["https://github.com/catchorg/Catch2/archive/v2.12.1.tar.gz"],
    strip_prefix = "Catch2-2.12.1",
    sha256 = "e5635c082282ea518a8dd7ee89796c8026af8ea9068cd7402fb1615deacd91c3",
)