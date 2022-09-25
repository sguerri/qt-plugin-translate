#include "PTranslate.h"

#include <QSettings>
#include <QTranslator>

QList<QTranslator*> PTranslate::translators;

void PTranslate::initLocale(QLocale locale)
{
    QSettings settings;
    if (settings.contains("application/locale")) {
        QLocale::setDefault(QLocale(settings.value("application/locale").toString()));
    } else {
        settings.setValue("application/locale", locale.name());
        QLocale::setDefault(locale);
    }
}

void PTranslate::initLocale(const QString& locale)
{
    PTranslate::initLocale(QLocale(locale));
}

void PTranslate::addPlugin(QTranslator* translator)
{
    if (translator == nullptr) return;

    PTranslate::translators.append(translator);
}

void PTranslate::install(QApplication* app, bool loadApplicationTranslator)
{
    auto translators = PTranslate::translators;
    for (auto translator: translators) {
        app->installTranslator(translator);
    }

    if (loadApplicationTranslator) {
        QTranslator* mainTranslator = new QTranslator();
        if (mainTranslator->load(QLocale(), app->applicationName(), QLatin1String("_"), QLatin1String(":/i18n"))) {
            app->installTranslator(mainTranslator);
        } else {
            // TODO Error message
        }
    }
}
