#ifndef MENU_H
#define MENU_H

#include <QDir>
#include <QObject>
#include "src/mapwidget/poiitem.h"
#include <QMenu>

class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent, const QString &iconsPath = ".");
    QMenu PopUpMenu;
private:
    QHash<QString, QMenu*> MenuItemsList;
    QSignalMapper* signalMapper;
    void ScanDir(QDir dir, const QStringList &parentDirs, QMenu* menuParent);
    void AddFileItem(QDir dir, const QStringList &parentDirs, QMenu* menuParent);
    void AddFolderItem(QDir dir, const QStringList &parentDirs, QMenu* menuParent);
    QMenu* GetMenuItem(const QStringList &parentDirs, QString name, QMenu *menuParent,
                       const QString &absoluteFilePath, bool addAction);
signals:
    void clicked(const QString &text);

public slots:
};

#endif // MENU_H