#include "defs.h"
#include "cffflashdatablocksmodel.h"
#include "cffflashdatablock.h"

CFFFlashDataBlocksModel::CFFFlashDataBlocksModel(QObject *parent):QAbstractListModel(parent)
{
    this->m_roles[Name] = "Name";
    this->m_roles[FlashDataBlock] = "FlashDataBlock";
}


QVariant CFFFlashDataBlocksModel::data(const QModelIndex &index, int role) const
{
    qDbg() << " DATA " << index.row() << role;
    if (index.row() < 0 || index.row() > this->m_objs.size())return QVariant();

        auto block = this->m_objs[index.row()];

        switch(role)
        {
            case Name:
                return block->FileName();
        }

        return QVariant::fromValue(block);
}

void CFFFlashDataBlocksModel::addFlashDataBlocks(QList<CFFFlashDataBlock *> blocks)
{
    qDbg() << "ADD BLOCKS" << blocks.count();
    //this->beginInsertRows(QModelIndex(), this->rowCount(), blocks.count()-1);
    //this->m_objs = blocks;
    //this->endInsertRows();

    foreach(auto block, blocks)
    {
        this->addFlashDataBlock(block);
    }
}

void CFFFlashDataBlocksModel::addFlashDataBlock(CFFFlashDataBlock * block)
{

    this->beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());
    this->m_objs.append(block);
    this->endInsertRows();
}

void CFFFlashDataBlocksModel::removeFlashDataBlock(CFFFlashDataBlock * block)
{
    auto idx = this->m_objs.indexOf(block);
    this->beginRemoveRows(QModelIndex(), idx, idx);
    this->m_objs.removeOne(block);
    this->endRemoveRows();
}

CFFFlashDataBlock * CFFFlashDataBlocksModel::blockAt(qint32 index)
{
    if(index < this->rowCount())return this->m_objs.at(index);
    else return new CFFFlashDataBlock(this);
}
