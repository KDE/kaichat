# KAIChat

Apps which allows to chat with AI (local ollama, network service)

![KAIChat Main Window](https://cdn.kde.org/screenshots/kaichat/kaichat.png)

## Features

KAIChat supports the following features:

- Export chat as Json/Text/Markdown
- Increase/Decrease global font by using CTRL++/CTRL+- shortcut

## Source Code

You can get kaichat from:

- <https://github.com/KDE/kaichat>[https://github.com/KDE/kaichat]
- [git clone git@invent.kde.org](git@invent.kde.org:utilities/kaichat.git)
- [git clone https://invent.kde.org/utilities/kaichat.git](https://invent.kde.org/utilities/kaichat.git)

Extra plugins tools can be found in kaichat-addons repository

- [git clone https//invent.kde.org/utilities/kaichat-addons.git] (https//invent.kde.org/utilities/kaichat-addons.git)

## Requirements

`cmake`, `cmake-extra-tools`,
`kwidgetaddons`, `ki18n`, `kcrash`, `kcoreaddons`,
`iconthemes`, `xmlgui`, `ktextaddons`

## How to build KAIChat

````bash
mkdir build
cd build
cmake ..
make
make install
````

or using CMakePresets support (need cmake > 3.20)

````bash
cmake --preset dev && cmake --build --preset dev

or (using mold linker)

cmake --preset dev-mokd && cmake --build --preset dev-mold
````

## ASAN

We can use sanitizers.supp file
example: LSAN_OPTIONS=suppressions=../sanitizers.supp ./bin/kaichat

## UNITY

KAIChat can build with cmake unity support

````bash
cmake --preset unity && cmake --build --preset unity
````

## Contributing

Contributions are welcome. We use [https://invent.kde.org/](https://invent.kde.org/)

The [KDE Community Code of Conduct](https://kde.org/code-of-conduct) is applied.

## License

This project is licensed under the GPL-2.0-or-later.
More information can be found in the `LICENSES` folder.

## Maintainer

- Laurent Montel <montel@kde.org>
