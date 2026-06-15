/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcentralwidget.h"
#include "kaichatglobalconfig.h"
#include <QVBoxLayout>
#include <TextAddonsWidgets/NeedUpdateVersionWidget>
#include <TextAddonsWidgets/WhatsNewMessageNgWidget>
#include <TextAddonsWidgets/WhatsNewNgUtils>
#include <TextAutoGenerateText/TextAutoGenerateChatsModel>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateMessagesModel>
#include <TextAutoGenerateText/TextAutoGenerateStackWidget>
using namespace Qt::Literals::StringLiterals;
KAIChatCentralWidget::KAIChatCentralWidget(const QList<KAboutRelease> &releases, TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mTextAutogenerateWidget(new TextAutoGenerateText::TextAutoGenerateStackWidget(manager, this))
    , mManager(manager)
    , mReleases(releases)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);

    QString newFeaturesMD5;
    if (!mReleases.isEmpty()) {
        newFeaturesMD5 = TextAddonsWidgets::WhatsNewNgUtils::createMD5(mReleases.constFirst().untranslatedDescription());
    }
    if (!newFeaturesMD5.isEmpty()) {
        const QString previousNewFeaturesMD5 = KAIChatGlobalConfig::self()->previousNewFeaturesMD5();
        if (!previousNewFeaturesMD5.isEmpty()) {
            const bool hasNewFeature = (previousNewFeaturesMD5 != newFeaturesMD5);
            if (hasNewFeature) {
                auto whatsNewMessageWidget = new TextAddonsWidgets::WhatsNewMessageNgWidget(this);
                whatsNewMessageWidget->setReleases(mReleases);
                whatsNewMessageWidget->setObjectName(u"whatsNewMessageWidget"_s);
                mainLayout->addWidget(whatsNewMessageWidget);
                KAIChatGlobalConfig::self()->setPreviousNewFeaturesMD5(newFeaturesMD5);
                KAIChatGlobalConfig::self()->save();
                whatsNewMessageWidget->animatedShow();
            }
        } else {
            KAIChatGlobalConfig::self()->setPreviousNewFeaturesMD5(newFeaturesMD5);
            KAIChatGlobalConfig::self()->save();
        }
    }

    mTextAutogenerateWidget->setObjectName("mTextAutogenerateWidget"_L1);
    mainLayout->addWidget(mTextAutogenerateWidget);

    if (TextAddonsWidgets::NeedUpdateVersionUtils::checkVersion()) {
        const auto status = TextAddonsWidgets::NeedUpdateVersionUtils::obsoleteVersionStatus(QStringLiteral(KAICHAT_RELEASE_VERSION), QDate::currentDate());
        if (status != TextAddonsWidgets::NeedUpdateVersionUtils::ObsoleteVersion::NotObsoleteYet) {
            auto needUpdateVersionWidget = new TextAddonsWidgets::NeedUpdateVersionWidget(this);
            needUpdateVersionWidget->setObjectName(u"needUpdateVersionWidget"_s);
            mainLayout->insertWidget(0, needUpdateVersionWidget);
            needUpdateVersionWidget->setObsoleteVersion(status);
        }
    }
}

KAIChatCentralWidget::~KAIChatCentralWidget() = default;

void KAIChatCentralWidget::showArchive(bool checked)
{
    mManager->setShowArchived(checked);
}

void KAIChatCentralWidget::searchText()
{
    mTextAutogenerateWidget->slotSearchText();
}

QString KAIChatCentralWidget::chatCurrentTitle() const
{
    return mManager->textAutoGenerateChatsModel()->title(mManager->currentChatId());
}

QList<KAboutRelease> KAIChatCentralWidget::releases() const
{
    return mReleases;
}

QList<TextAutoGenerateText::TextAutoGenerateMessage> KAIChatCentralWidget::messagesFromCurrentChat() const
{
    const auto messageModel = mManager->messagesModelFromChatId(mManager->currentChatId());
    if (messageModel) {
        return messageModel->messages();
    }
    return {};
}

#include "moc_kaichatcentralwidget.cpp"
