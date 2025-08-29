# Release method

- change set(KAICHAT_STABLE_VERSION false) in toplevel CMakeLists.txt to true
- change set(KAICHAT_RELEASE_VERSION "24.12.16") in toplevel CMakeLists.txt
  (used for show when version is too old)
- change src/widgets/needupdateversion/needupdateversionutils.cpp
  [https://cdn.kde.org/ci-builds/utilities/kaichat/](https://cdn.kde.org/ci-builds/utilities/kaichat/)

## Update generate binaire

- sysadmin/repo-metadata (update version here)
- sysadmin/ci-utilities (update version here)
