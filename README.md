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

## Requirements

`cmake`, `cmake-extra-tools`,
`kwidgetaddons`, `ki18n`, `kcrash`, `kcoreaddons`, `syntaxhighlighting`, `sonnet`,
`textwidgets`, `kio`, `iconthemes`, `xmlgui`, `ktextaddons`, `qtkeychain`

## How to build ruqola

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
````

## ASAN

We can use sanitizers.supp file
example: LSAN_OPTIONS=suppressions=../sanitizers.supp ./bin/kaichat

## UNITY

KAIChat can build with cmake unity support

````bash
cmake --preset unity && cmake --build --preset unity
````

## Maintainer

- Laurent Montel <montel@kde.org>
