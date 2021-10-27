#ifndef CFFFLASHSEGMENTMODEL_H
#define CFFFLASHSEGMENTMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "cffflashsegment.h"

class CFFFlashSegmentModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CFFFlashSegmentModel(QObject *parent = nullptr);

    enum ListRoles
    {
        Name = Qt::UserRole+1,
        FlashSegment
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {Q_UNUSED(parent) return this->m_objs.count();}
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override{return this->m_roles;}

    Q_INVOKABLE void addFlashSegment(CFFFlashSegment *);
    Q_INVOKABLE void addFlashSegments(QList<CFFFlashSegment *>);
    Q_INVOKABLE void removeFlashSegment(CFFFlashSegment *);
    Q_INVOKABLE CFFFlashSegment * segmentAt(qint32 index);

    Q_INVOKABLE QList<CFFFlashSegment *> getFlashSegments(){return this->m_objs;}

private:
    QList<CFFFlashSegment *>    m_objs;
    QHash<int, QByteArray>      m_roles;
};
#endif // CFFFLASHSEGMENTMODEL_H
