# KAIChat

An application that lets you chat with AI language models, either running locally
with Ollama or provided by an online AI service.

![KAIChat Main Window](https://cdn.kde.org/screenshots/kaichat/kaichat.png)

## Features

KAIChat supports the following features:

- Export a chat as JSON, plain text or Markdown
- Increase or decrease the global font size with the `Ctrl++` and `Ctrl+-` shortcuts

## Source Code

You can get KAIChat from:

- <https://invent.kde.org/utilities/kaichat>
- <https://github.com/KDE/kaichat> (mirror)

```bash
git clone https://invent.kde.org/utilities/kaichat.git
# or, over SSH
git clone git@invent.kde.org:utilities/kaichat.git
```

Extra plugins can be found in the [kaichat-addons](https://invent.kde.org/utilities/kaichat-addons)
repository:

```bash
git clone https://invent.kde.org/utilities/kaichat-addons.git
```

## Requirements

- `cmake` 3.29 or later and `extra-cmake-modules` 6.26 or later
- Qt 6.10 or later: `Widgets`, `Sql`
- KDE Frameworks 6.26 or later: `kcoreaddons`, `kconfig`, `ki18n`, `kwidgetsaddons`,
  `kxmlgui`, `kiconthemes`, `kcrash`, `kwindowsystem`, `knotifyconfig`, `knotifications`,
  `kcmutils`, `syntax-highlighting`, `kglobalaccel`, `kio`, `sonnet`, `kstatusnotifieritem`
- `ktextaddons`

Optional: `kdbusaddons` (or `KDSingleApplication` when D-Bus support is disabled),
`purpose`, `kuserfeedback`, `kdoctools`.

## How to build KAIChat

```bash
mkdir build
cd build
cmake ..
make
make install
```

Or using the CMake presets (requires CMake 3.20 or later):

```bash
cmake --preset dev && cmake --build --preset dev
```

Using the mold linker:

```bash
cmake --preset dev-mold && cmake --build --preset dev-mold
```

## ASAN

The `sanitizers.supp` file can be used to suppress known reports, for example:

```bash
LSAN_OPTIONS=suppressions=../sanitizers.supp ./bin/kaichat
```

## Unity

KAIChat can be built with CMake unity build support:

```bash
cmake --preset unity && cmake --build --preset unity
```

## Contributing

Contributions are welcome. We use [https://invent.kde.org/](https://invent.kde.org/).

The [KDE Community Code of Conduct](https://kde.org/code-of-conduct) applies.

## License

This project is licensed under the GPL-2.0-or-later.
More information can be found in the `LICENSES` folder.

## Maintainer

- Laurent Montel <montel@kde.org>
