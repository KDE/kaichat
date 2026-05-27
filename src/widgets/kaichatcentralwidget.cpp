/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcentralwidget.h"
#include "config-kaichat.h"
#include "kaichatglobalconfig.h"
#if WHATSNEWSNGSUPPORT
#include <KAboutData>
#include <TextAddonsWidgets/WhatsNewMessageNgWidget>
#else
#include "kaichatwhatsnewtranslations.h"
#include <TextAddonsWidgets/WhatsNewMessageWidget>
#endif
#include <QVBoxLayout>
#include <TextAddonsWidgets/NeedUpdateVersionWidget>
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

    QString newFeaturesMD5;
#if WHATSNEWSNGSUPPORT
    const KAboutData aboutData = KAboutData::fromAppStreamForApplication();
    if (!aboutData.releases().isEmpty()) {
        newFeaturesMD5 = aboutData.releases().constFirst().untranslatedDescription();
    }
#else
    KAIChatWhatsNewTranslations translations;
    newFeaturesMD5 = translations.newFeaturesMD5();
#endif
    if (!newFeaturesMD5.isEmpty()) {
        const QString previousNewFeaturesMD5 = KAIChatGlobalConfig::self()->previousNewFeaturesMD5();
        if (!previousNewFeaturesMD5.isEmpty()) {
            const bool hasNewFeature = (previousNewFeaturesMD5 != newFeaturesMD5);
            if (hasNewFeature) {
#if WHATSNEWSNGSUPPORT
                auto whatsNewMessageWidget = new TextAddonsWidgets::WhatsNewMessageNgWidget(this);
                whatsNewMessageWidget->setObjectName(u"whatsNewMessageWidget"_s);
                mainLayout->addWidget(whatsNewMessageWidget);
                KAIChatGlobalConfig::self()->setPreviousNewFeaturesMD5(newFeaturesMD5);
                whatsNewMessageWidget->animatedShow();
#else
                auto whatsNewMessageWidget = new TextAddonsWidgets::WhatsNewMessageWidget(this);
                whatsNewMessageWidget->setWhatsNewInfos(translations.createWhatsNewInfo());
                whatsNewMessageWidget->setObjectName(u"whatsNewMessageWidget"_s);
                mainLayout->addWidget(whatsNewMessageWidget);
                KAIChatGlobalConfig::self()->setPreviousNewFeaturesMD5(newFeaturesMD5);
                whatsNewMessageWidget->animatedShow();
#endif
            }
        } else {
            KAIChatGlobalConfig::self()->setPreviousNewFeaturesMD5(newFeaturesMD5);
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

QList<TextAutoGenerateText::TextAutoGenerateMessage> KAIChatCentralWidget::messagesFromCurrentChat() const
{
    const auto messageModel = mManager->messagesModelFromChatId(mManager->currentChatId());
    if (messageModel) {
        return messageModel->messages();
    }
    return {};
}

#include "moc_kaichatcentralwidget.cpp"
