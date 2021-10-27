#include "defs.h"
#include "cffflashsegmentmodel.h"


CFFFlashSegmentModel::CFFFlashSegmentModel(QObject *parent):QAbstractListModel(parent)
{
    this->m_roles[Name] = "Name";
    this->m_roles[FlashSegment] = "FlashSegment";
}


QVariant CFFFlashSegmentModel::data(const QModelIndex &index, int role) const
{
    qDbg() << " DATA " << index.row() << role;
    if (index.row() < 0 || index.row() > this->m_objs.size())return QVariant();

        auto block = this->m_objs[index.row()];

        switch(role)
        {
            case Name:
                return block->SegmentName();
        }

        return QVariant::fromValue(block);
}

void CFFFlashSegmentModel::addFlashSegments(QList<CFFFlashSegment *> blocks)
{
    qDbg() << "ADD SEGMENTS" << blocks.count();
    //this->beginInsertRows(QModelIndex(), this->rowCount(), blocks.count()-1);
    //this->m_objs = blocks;
    //this->endInsertRows();

    foreach(auto block, blocks)
    {
        this->addFlashSegment(block);
    }
}

void CFFFlashSegmentModel::addFlashSegment(CFFFlashSegment * block)
{

    this->beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());
    this->m_objs.append(block);
    this->endInsertRows();
}

void CFFFlashSegmentModel::removeFlashSegment(CFFFlashSegment * block)
{
    auto idx = this->m_objs.indexOf(block);
    this->beginRemoveRows(QModelIndex(), idx, idx);
    this->m_objs.removeOne(block);
    this->endRemoveRows();
}

CFFFlashSegment * CFFFlashSegmentModel::segmentAt(qint32 index)
{
    if(index < this->rowCount())return this->m_objs.at(index);
    else return new CFFFlashSegment(this);
}
