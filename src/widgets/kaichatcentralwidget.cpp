/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcentralwidget.h"
#include "config-kaichat.h"
#include "kaichatglobalconfig.h"
#include "needupdateversion/needupdateversionwidget.h"
#include "whatsnew/whatsnewmessagewidget.h"
#include "whatsnew/whatsnewtranslations.h"
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateChatsModel>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateMessagesModel>
#include <TextAutoGenerateText/TextAutoGenerateStackWidget>
using namespace Qt::Literals::StringLiterals;
KAIChatCentralWidget::KAIChatCentralWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mTextAutogenerateWidget(new TextAutoGenerateText::TextAutoGenerateStackWidget(manager, this))
    , mManager(manager)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);

    WhatsNewTranslations translations;
    const QString newFeaturesMD5 = translations.newFeaturesMD5();
    if (!newFeaturesMD5.isEmpty()) {
        const bool hasNewFeature = (KAIChatGlobalConfig::self()->previousNewFeaturesMD5() != newFeaturesMD5);
        if (hasNewFeature) {
            auto whatsNewMessageWidget = new WhatsNewMessageWidget(this);
            whatsNewMessageWidget->setObjectName(u"whatsNewMessageWidget"_s);
            mainLayout->addWidget(whatsNewMessageWidget);
            KAIChatGlobalConfig::self()->setPreviousNewFeaturesMD5(newFeaturesMD5);
            whatsNewMessageWidget->animatedShow();
        }
    }

    mTextAutogenerateWidget->setObjectName("mTextAutogenerateWidget"_L1);
    mainLayout->addWidget(mTextAutogenerateWidget);

    if (NeedUpdateVersionUtils::checkVersion()) {
        const auto status = NeedUpdateVersionUtils::obsoleteVersionStatus(QLatin1StringView(KAICHAT_RELEASE_VERSION), QDate::currentDate());
        if (status != NeedUpdateVersionUtils::ObsoleteVersion::NotObsoleteYet) {
            auto needUpdateVersionWidget = new NeedUpdateVersionWidget(this);
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

QList<TextAutoGenerateText::TextAutoGenerateMessage> KAIChatCentralWidget::messagesFromCurrentChat() const
{
    const auto messageModel = mManager->messagesModelFromChatId(mManager->currentChatId());
    if (messageModel) {
        return messageModel->messages();
    }
    return {};
}

#include "moc_kaichatcentralwidget.cpp"
