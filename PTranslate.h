#ifndef PTRANSLATE_H
#define PTRANSLATE_H

#include <QApplication>

namespace PTranslate
{
    extern QList<QTranslator*> translators;

    extern void initLocale(QLocale locale);
    extern void initLocale(const QString& locale);
    extern void addPlugin(QTranslator* translator);
    extern void install(QApplication* app, bool loadApplicationTranslator = true);
};

#endif // PTRANSLATE_H
