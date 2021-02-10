#ifndef CFFFLASHDATABLOCK_H
#define CFFFLASHDATABLOCK_H

/*
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


        public long GetBlockLengthOffset(BinaryReader reader)
        {
            reader.BaseStream.Seek(BaseAddress, SeekOrigin.Begin);

            ulong bitflags = reader.ReadUInt32();
            reader.ReadUInt16();

            CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress); // Qualifier
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
        public long GetFlashDataOffset(BinaryReader reader)
        {
            reader.BaseStream.Seek(BaseAddress, SeekOrigin.Begin);

            ulong bitflags = reader.ReadUInt32();
            reader.ReadUInt16();

            CaesarReader.ReadBitflagStringWithReader(ref bitflags, reader, BaseAddress); // Qualifier
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

class CFFFlashDataBlock : public QObject
{
    Q_OBJECT
public:
    explicit CFFFlashDataBlock(QObject *parent = nullptr);
    static CFFFlashDataBlock * readFlashDataBlock(QFile * cff, long baseAddress, QObject * parent = Q_NULLPTR);

private:
    void readCFFData(QFile * cff, long baseAddress);

};

#endif // CFFFLASHDATABLOCK_H
