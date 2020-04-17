//
// Created by rason on 16.04.2020.
//

#ifndef MINI_CONFIGURATOR_HPP
#define MINI_CONFIGURATOR_HPP

#include <QFile>
#include <QString>

struct config_t {
    QString font_name;
    int font_size;
    QString color_scheme;
};

class configurator {
public:
    explicit configurator(const QString &pathFile);

    void loadConfig(config_t *config) const;

    void saveConfig(config_t &config) const;

private:
    const QString filePath;

};


#endif //MINI_CONFIGURATOR_HPP
