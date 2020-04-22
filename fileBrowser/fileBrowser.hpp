#include <QListWidget>
#include <QWidget>



class FileBrowser
{
Q_OBJECT

public:
    FileBrowser(const QString &filter, QWidget *parent = 0, const char *name = 0);
};
