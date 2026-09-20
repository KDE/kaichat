# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

function get_files
{
    echo application-vnd-kde-kaichat.xml
}

function po_for_file
{
    case "$1" in
       application-vnd-kde-kaichat.xml)
           echo kaichat_xml_mimetypes.po
       ;;
    esac
}

function tags_for_file
{
    case "$1" in
       application-vnd-kde-kaichat.xml)
           echo comment
       ;;
    esac
}

