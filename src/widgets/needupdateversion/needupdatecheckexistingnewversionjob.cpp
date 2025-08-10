/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "needupdatecheckexistingnewversionjob.h"
using namespace Qt::Literals::StringLiterals;

#include "kaichat_widget_debug.h"
#include "needupdateparsehtmljob.h"
#include "needupdateparsehtmlutil.h"

NeedUpdateCheckExistingNewVersionJob::NeedUpdateCheckExistingNewVersionJob(QObject *parent)
    : QObject{parent}
{
}

NeedUpdateCheckExistingNewVersionJob::~NeedUpdateCheckExistingNewVersionJob() = default;

void NeedUpdateCheckExistingNewVersionJob::start()
{
    if (!canStart()) {
        qCWarning(KAICHAT_WIDGET_LOG) << "Impossible to start NeedUpdateCheckExistingNewVersionJob";
        Q_EMIT foundNewVersion(false);
        deleteLater();
        return;
    }
    auto job = new NeedUpdateParseHtmlJob(this);
    job->setUrl(mUrl);
    connect(job, &NeedUpdateParseHtmlJob::downLoadDone, this, &NeedUpdateCheckExistingNewVersionJob::slotDownloadDone);
    job->start();
}

void NeedUpdateCheckExistingNewVersionJob::slotDownloadDone(const QString &str)
{
    const QString compileDateStr = NeedUpdateParseHtmlUtil::extractDate(str);
    if (compileDateStr.isEmpty()) {
        Q_EMIT foundNewVersion(false);
        deleteLater();
        return;
    }

    qCDebug(KAICHAT_WIDGET_LOG) << " currentCompiledDate " << mCompileDate;

    const QDate dateFromUrl = QDate::fromString(compileDateStr, u"yyyy-MM-dd"_s);
    qCDebug(KAICHAT_WIDGET_LOG) << " dateFromUrl " << dateFromUrl << " original " << compileDateStr;

    if (dateFromUrl > mCompileDate) {
        Q_EMIT foundNewVersion(true);
    } else {
        Q_EMIT foundNewVersion(false);
    }
    deleteLater();
}

QUrl NeedUpdateCheckExistingNewVersionJob::url() const
{
    return mUrl;
}

void NeedUpdateCheckExistingNewVersionJob::setUrl(const QUrl &newUrl)
{
    mUrl = newUrl;
}

bool NeedUpdateCheckExistingNewVersionJob::canStart() const
{
    return !mUrl.isEmpty() && mCompileDate.isValid();
}

QDate NeedUpdateCheckExistingNewVersionJob::compileDate() const
{
    return mCompileDate;
}

void NeedUpdateCheckExistingNewVersionJob::setCompileDate(const QDate &newCompileDate)
{
    mCompileDate = newCompileDate;
}

#include "moc_needupdatecheckexistingnewversionjob.cpp"
