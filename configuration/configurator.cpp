//
// Created by rason on 16.04.2020.
//

#include "configurator.hpp"
#include <QtDebug>
#include <QMessageBox>
#include <QTextStream>
#include <QtCore/QJsonParseError>
#include <QtCore/QJsonObject>

configurator::configurator(const QString &path): filePath(path) {}

void configurator::loadConfig(config_t *config_t) const {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::warning(, "Warning", "cannot open file for reading: " + file.errorString());
    }
    QTextStream configStream(&file);
    QTextStream out(stdout);
    const auto configJson = configStream.readAll();
    QJsonParseError parseError{};
    auto config = QJsonDocument::fromJson(configJson.toUtf8(), &parseError).object();
    const auto config_json = config["config"].toObject();

    config_t->font_name = config_json["font_name"].toString();
    config_t->font_size = config_json["font_size"].toInt();
    config_t->color_scheme = config_json["color_scheme"].toString();

    file.close();

}

void configurator::saveConfig(config_t &config) const {
    QFile file(this->filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qErrnoWarning("Cannot open for writing...");
        exit(-1);
    }
    QTextStream out(stdout);
    QTextStream configStream(&file);
    auto configJson = configStream.readAll();
    file.seek(0);

    QJsonParseError parseError{};
    auto config_json = QJsonDocument::fromJson(configJson.toUtf8(), &parseError);
    auto configObject = config_json.object();
    auto cfg = configObject["config"].toObject();

    cfg["font_name"] = config.font_name;
    cfg["font_size"] = config.font_size;
    cfg["color_scheme"] = config.color_scheme;
    configObject["config"] = cfg;
    config_json.setObject(configObject);

    file.write(config_json.toJson());
    file.close();
}
