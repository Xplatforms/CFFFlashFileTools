#ifndef CFFFLASHDATABLOCK_H
#define CFFFLASHDATABLOCK_H

/*
<<<<<<< HEAD
=======
public class FlashDataBlock
    {

        // 0x16 [6,  4,4,4,4,  4,4,4,4,  4,4,4,2,  4,4,4,4,  4,4,4,4,  4,4,4,4,4],
        public string Qualifier;
        public int LongName;
        public int Description;
        public int FlashData;
        public int BlockLength;
        public int DataFormat;
        public int FileName;
        public int NumberOfFilters;
        public int FiltersOffset;
        public int NumberOfSegments;
        public int SegmentOffset;
        public int EncryptionMode;
        public int KeyLength;
        public int KeyBuffer;
        public int NumberOfOwnIdents;
        public int IdentsOffset;
        public int NumberOfSecurities;
        public int SecuritiesOffset;
        public string DataBlockType;
        public int UniqueObjectId;
        public string FlashDataInfo_Idk;
        public int FlashDataInfoLang1;
        public int FlashDataInfoLang2;
        public int FlashDataInfo_Idk2;

        public long BaseAddress;
        public List<FlashSegment> FlashSegments = new List<FlashSegment>();

        public FlashDataBlock(BinaryReader reader, long baseAddress)
        {
            BaseAddress = baseAddress;
            reader.BaseStream.Seek(BaseAddress, SeekOrigin.Begin);

            ulong bitflags = reader.ReadUInt32();
            reader.ReadUInt16();

            Qualifier = CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress);
            LongName = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            Description = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            FlashData = CaesarReader.ReadBitflagInt32(ref bitflags, reader);

            BlockLength = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            DataFormat = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            FileName = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            NumberOfFilters = CaesarReader.ReadBitflagInt32(ref bitflags, reader);

            FiltersOffset = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            NumberOfSegments = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            SegmentOffset = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            EncryptionMode = CaesarReader.ReadBitflagInt16(ref bitflags, reader);

            KeyLength = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            KeyBuffer = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            NumberOfOwnIdents = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            IdentsOffset = CaesarReader.ReadBitflagInt32(ref bitflags, reader);

            NumberOfSecurities = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            SecuritiesOffset = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            DataBlockType = CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress);
            UniqueObjectId = CaesarReader.ReadBitflagInt32(ref bitflags, reader);

            FlashDataInfo_Idk = CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress);
            FlashDataInfoLang1 = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            FlashDataInfoLang2 = CaesarReader.ReadBitflagInt32(ref bitflags, reader);
            FlashDataInfo_Idk2 = CaesarReader.ReadBitflagInt32(ref bitflags, reader);


            // CtfUnk1 = CaesarReader.ReadBitflagInt32(ref ctfBitflags, reader);
            FlashSegments = new List<FlashSegment>();
            for (int segmentIndex = 0; segmentIndex < NumberOfSegments; segmentIndex++)
            {
                long segmentEntryAddress = SegmentOffset + BaseAddress + (segmentIndex * 4);
                reader.BaseStream.Seek(segmentEntryAddress, SeekOrigin.Begin);

                long segmentBaseAddress = SegmentOffset + BaseAddress + reader.ReadInt32();

                FlashSegment segment = new FlashSegment(reader, segmentBaseAddress);
                FlashSegments.Add(segment);
            }

        }
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961


        public long GetBlockLengthOffset(BinaryReader reader)
        {
            reader.BaseStream.Seek(BaseAddress, SeekOrigin.Begin);

            ulong bitflags = reader.ReadUInt32();
            reader.ReadUInt16();

<<<<<<< HEAD
            CaesarReader.ReadBitflagString(ref bitflags, reader, BaseAddress); // Qualifier
=======
            CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress); // Qualifier
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
            CaesarReader.ReadBitflagInt32(ref bitflags, reader); // LongName
            CaesarReader.ReadBitflagInt32(ref bitflags, reader); // Description
            CaesarReader.ReadBitflagInt32(ref bitflags, reader); // FlashData

            if (CaesarReader.CheckAndAdvanceBitflag(ref bitflags))
            {
                return reader.BaseStream.Position;
            }
            else
            {
                return -1;
            }
        }
<<<<<<< HEAD

=======
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
        public long GetFlashDataOffset(BinaryReader reader)
        {
            reader.BaseStream.Seek(BaseAddress, SeekOrigin.Begin);

            ulong bitflags = reader.ReadUInt32();
            reader.ReadUInt16();

<<<<<<< HEAD
            CaesarReader.ReadBitflagString(ref bitflags, reader, BaseAddress); // Qualifier
=======
            CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress); // Qualifier
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
            CaesarReader.ReadBitflagInt32(ref bitflags, reader); // LongName
            CaesarReader.ReadBitflagInt32(ref bitflags, reader); // Description

            if (CaesarReader.CheckAndAdvanceBitflag(ref bitflags))
            {
                return reader.BaseStream.Position;
            }
            else
            {
                return -1;
            }
        }
*/

#include <QObject>
#include <QFile>
<<<<<<< HEAD
#include <QList>
#include "cffflashsegment.h"
=======
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961

class CFFFlashDataBlock : public QObject
{
    Q_OBJECT
public:
    explicit CFFFlashDataBlock(QObject *parent = nullptr);
    static CFFFlashDataBlock * readFlashDataBlock(QFile * cff, long baseAddress, QObject * parent = Q_NULLPTR);

<<<<<<< HEAD
    Q_PROPERTY(QString Qualifier READ Qualifier WRITE setQualifier NOTIFY QualifierChanged);
    Q_PROPERTY(QString DataBlockType READ DataBlockType WRITE setDataBlockType NOTIFY DataBlockTypeChanged);
    Q_PROPERTY(QString FlashDataInfo_Idk READ FlashDataInfo_Idk WRITE setFlashDataInfo_Idk NOTIFY FlashDataInfo_IdkChanged);
    Q_PROPERTY(int32_t LongName READ LongName WRITE setLongName NOTIFY LongNameChanged);
    Q_PROPERTY(int32_t Description READ Description WRITE setDescription NOTIFY DescriptionChanged);
    Q_PROPERTY(int32_t FlashData READ FlashData WRITE setFlashData NOTIFY FlashDataChanged);
    Q_PROPERTY(int32_t BlockLength READ BlockLength WRITE setBlockLength NOTIFY BlockLengthChanged);
    Q_PROPERTY(int32_t DataFormat READ DataFormat WRITE setDataFormat NOTIFY DataFormatChanged);
    Q_PROPERTY(int32_t FileName READ FileName WRITE setFileName NOTIFY FileNameChanged);
    Q_PROPERTY(int32_t NumberOfFilters READ NumberOfFilters WRITE setNumberOfFilters NOTIFY NumberOfFiltersChanged);
    Q_PROPERTY(int32_t FiltersOffset READ FiltersOffset WRITE setFiltersOffset NOTIFY FiltersOffsetChanged);
    Q_PROPERTY(int32_t NumberOfSegments READ NumberOfSegments WRITE setNumberOfSegments NOTIFY NumberOfSegmentsChanged);
    Q_PROPERTY(int32_t SegmentOffset READ SegmentOffset WRITE setSegmentOffset NOTIFY SegmentOffsetChanged);
    Q_PROPERTY(int32_t EncryptionMode READ EncryptionMode WRITE setEncryptionMode NOTIFY EncryptionModeChanged);
    Q_PROPERTY(int32_t KeyLength READ KeyLength WRITE setKeyLength NOTIFY KeyLengthChanged);
    Q_PROPERTY(int32_t KeyBuffer READ KeyBuffer WRITE setKeyBuffer NOTIFY KeyBufferChanged);
    Q_PROPERTY(int32_t NumberOfOwnIdents READ NumberOfOwnIdents WRITE setNumberOfOwnIdents NOTIFY NumberOfOwnIdentsChanged);
    Q_PROPERTY(int32_t IdentsOffset READ IdentsOffset WRITE setIdentsOffset NOTIFY IdentsOffsetChanged);
    Q_PROPERTY(int32_t NumberOfSecurities READ NumberOfSecurities WRITE setNumberOfSecurities NOTIFY NumberOfSecuritiesChanged);
    Q_PROPERTY(int32_t SecuritiesOffset READ SecuritiesOffset WRITE setSecuritiesOffset NOTIFY SecuritiesOffsetChanged);
    Q_PROPERTY(int32_t UniqueObjectId READ UniqueObjectId WRITE setUniqueObjectId NOTIFY UniqueObjectIdChanged);
    Q_PROPERTY(int32_t FlashDataInfoLang1 READ FlashDataInfoLang1 WRITE setFlashDataInfoLang1 NOTIFY FlashDataInfoLang1Changed);
    Q_PROPERTY(int32_t FlashDataInfoLang2 READ FlashDataInfoLang2 WRITE setFlashDataInfoLang2 NOTIFY FlashDataInfoLang2Changed);
    Q_PROPERTY(int32_t FlashDataInfo_Idk2 READ FlashDataInfo_Idk2 WRITE setFlashDataInfo_Idk2 NOTIFY FlashDataInfo_Idk2Changed);
    Q_PROPERTY(QList<CFFFlashSegment *> FlashSegments READ FlashSegments WRITE setFlashSegments NOTIFY FlashSegmentsChanged);
    Q_PROPERTY(long BaseAddress READ BaseAddress WRITE setBaseAddress NOTIFY BaseAdressChanged);

    QString Qualifier(){return this->m_Qualifier;}
    int32_t LongName(){return this->m_LongName;}
    int32_t Description(){return this->m_Description;}
    int32_t FlashData(){return this->m_FlashData;}
    int32_t BlockLength(){return this->m_BlockLength;}
    int32_t DataFormat(){return this->m_DataFormat;}
    int32_t FileName(){return this->m_FileName;}
    int32_t NumberOfFilters(){return this->m_NumberOfFilters;}
    int32_t FiltersOffset(){return this->m_FiltersOffset;}
    int32_t NumberOfSegments(){return this->m_NumberOfSegments;}
    int32_t SegmentOffset(){return this->m_SegmentOffset;}
    int32_t EncryptionMode(){return this->m_EncryptionMode;}
    int32_t KeyLength(){return this->m_KeyLength;}
    int32_t KeyBuffer(){return this->m_KeyBuffer;}
    int32_t NumberOfOwnIdents(){return this->m_NumberOfOwnIdents;}
    int32_t IdentsOffset(){return this->m_IdentsOffset;}
    int32_t NumberOfSecurities(){return this->m_NumberOfSecurities;}
    int32_t SecuritiesOffset(){return this->m_SecuritiesOffset;}
    QString DataBlockType(){return this->m_DataBlockType;}
    int32_t UniqueObjectId(){return this->m_UniqueObjectId;}
    QString FlashDataInfo_Idk(){return this->m_FlashDataInfo_Idk;}
    int32_t FlashDataInfoLang1(){return this->m_FlashDataInfoLang1;}
    int32_t FlashDataInfoLang2(){return this->m_FlashDataInfoLang2;}
    int32_t FlashDataInfo_Idk2(){return this->m_FlashDataInfo_Idk2;}
    QList<CFFFlashSegment *> FlashSegments(){return this->m_FlashSegments;}
    long    BaseAddress(){return this->m_BaseAddress;}

    void setQualifier(QString data){this->m_Qualifier = data; emit QualifierChanged();}
    void setLongName(int32_t data){this->m_LongName = data; emit LongNameChanged();}
    void setDescription(int32_t data){this->m_Description = data; emit DescriptionChanged();}
    void setFlashData(int32_t data){this->m_FlashData = data; emit FlashDataChanged();}
    void setBlockLength(int32_t data){this->m_BlockLength = data; emit BlockLengthChanged();}
    void setDataFormat(int32_t data){this->m_DataFormat = data; emit DataFormatChanged();}
    void setFileName(int32_t data){this->m_FileName = data; emit FileNameChanged();}
    void setNumberOfFilters(int32_t data){this->m_NumberOfFilters = data; emit NumberOfFiltersChanged();}
    void setFiltersOffset(int32_t data){this->m_FiltersOffset = data; emit FiltersOffsetChanged();}
    void setNumberOfSegments(int32_t data){this->m_NumberOfSegments = data; emit NumberOfSegmentsChanged();}
    void setSegmentOffset(int32_t data){this->m_SegmentOffset = data; emit SegmentOffsetChanged();}
    void setEncryptionMode(int32_t data){this->m_EncryptionMode = data; emit EncryptionModeChanged();}
    void setKeyLength(int32_t data){this->m_KeyLength = data; emit KeyLengthChanged();}
    void setKeyBuffer(int32_t data){this->m_KeyBuffer = data; emit KeyBufferChanged();}
    void setNumberOfOwnIdents(int32_t data){this->m_NumberOfOwnIdents = data; emit NumberOfOwnIdentsChanged();}
    void setIdentsOffset(int32_t data){this->m_IdentsOffset = data; emit IdentsOffsetChanged();}
    void setNumberOfSecurities(int32_t data){this->m_NumberOfSecurities = data; emit NumberOfSecuritiesChanged();}
    void setSecuritiesOffset(int32_t data){this->m_SecuritiesOffset = data; emit SecuritiesOffsetChanged();}
    void setDataBlockType(QString data){this->m_DataBlockType = data; emit DataBlockTypeChanged();}
    void setUniqueObjectId(int32_t data){this->m_UniqueObjectId = data; emit UniqueObjectIdChanged();}
    void setFlashDataInfo_Idk(QString data){this->m_FlashDataInfo_Idk = data; emit FlashDataInfo_IdkChanged();}
    void setFlashDataInfoLang1(int32_t data){this->m_FlashDataInfoLang1 = data; emit FlashDataInfoLang1Changed();}
    void setFlashDataInfoLang2(int32_t data){this->m_FlashDataInfoLang2 = data; emit FlashDataInfoLang2Changed();}
    void setFlashDataInfo_Idk2(int32_t data){this->m_FlashDataInfo_Idk2 = data; emit FlashDataInfo_Idk2Changed();}
    void setBaseAddress(long data){this->m_BaseAddress = data; emit BaseAdressChanged();}
    void setFlashSegments(QList<CFFFlashSegment *> data){this->m_FlashSegments = data; emit FlashSegmentsChanged();}

private:
    void readCFFData(QFile * cff, long baseAddress);

signals:
    void QualifierChanged();
    void LongNameChanged();
    void DescriptionChanged();
    void FlashDataChanged();
    void BlockLengthChanged();
    void DataFormatChanged();
    void FileNameChanged();
    void NumberOfFiltersChanged();
    void FiltersOffsetChanged();
    void NumberOfSegmentsChanged();
    void SegmentOffsetChanged();
    void EncryptionModeChanged();
    void KeyLengthChanged();
    void KeyBufferChanged();
    void NumberOfOwnIdentsChanged();
    void IdentsOffsetChanged();
    void NumberOfSecuritiesChanged();
    void SecuritiesOffsetChanged();
    void DataBlockTypeChanged();
    void UniqueObjectIdChanged();
    void FlashDataInfo_IdkChanged();
    void FlashDataInfoLang1Changed();
    void FlashDataInfoLang2Changed();
    void FlashDataInfo_Idk2Changed();
    void FlashSegmentsChanged();
    void BaseAdressChanged();

private:
    QString m_Qualifier;
    int32_t m_LongName;
    int32_t m_Description;
    int32_t m_FlashData;
    int32_t m_BlockLength;
    int32_t m_DataFormat;
    int32_t m_FileName;
    int32_t m_NumberOfFilters;
    int32_t m_FiltersOffset;
    int32_t m_NumberOfSegments;
    int32_t m_SegmentOffset;
    int32_t m_EncryptionMode;
    int32_t m_KeyLength;
    int32_t m_KeyBuffer;
    int32_t m_NumberOfOwnIdents;
    int32_t m_IdentsOffset;
    int32_t m_NumberOfSecurities;
    int32_t m_SecuritiesOffset;
    QString m_DataBlockType;
    int32_t m_UniqueObjectId;
    QString m_FlashDataInfo_Idk;
    int32_t m_FlashDataInfoLang1;
    int32_t m_FlashDataInfoLang2;
    int32_t m_FlashDataInfo_Idk2;
    QList<CFFFlashSegment *> m_FlashSegments;
    long    m_BaseAddress;
=======
private:
    void readCFFData(QFile * cff, long baseAddress);

>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
};

#endif // CFFFLASHDATABLOCK_H
