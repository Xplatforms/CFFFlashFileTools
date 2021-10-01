#ifndef CFFFLASHDATABLOCKSMODEL_H
#define CFFFLASHDATABLOCKSMODEL_H

#include <QAbstractListModel>
#include <QObject>

class CFFFlashDataBlock;

class CFFFlashDataBlocksModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CFFFlashDataBlocksModel(QObject *parent = nullptr);

    enum ListRoles
    {
        Name = Qt::UserRole+1,
        FlashDataBlock
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {Q_UNUSED(parent) return this->m_objs.count();}
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override{return this->m_roles;}

    Q_INVOKABLE void addFlashDataBlock(CFFFlashDataBlock *);
    Q_INVOKABLE void addFlashDataBlocks(QList<CFFFlashDataBlock *>);
    Q_INVOKABLE void removeFlashDataBlock(CFFFlashDataBlock *);
    Q_INVOKABLE CFFFlashDataBlock * blockAt(qint32 index);

    Q_INVOKABLE QList<CFFFlashDataBlock *> getFlashDataBlocks(){return this->m_objs;}

private:
    QList<CFFFlashDataBlock *>    m_objs;
    QHash<int, QByteArray>        m_roles;
};

#endif // CFFFLASHDATABLOCKSMODEL_H
