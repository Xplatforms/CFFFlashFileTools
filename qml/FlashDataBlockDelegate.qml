import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import xplatforms.cffflashcontainer.flashblock 1.0
import xplatforms.cffflashcontainer.flashsegment 1.0
import xplatforms.cffflashcontainer.flashsegmentmodel 1.0

Item
{
    property CFFFlashDataBlock block;
    property CFFFlashSegmentModel segments_model: CFFFlashSegmentModel{};

    ColumnLayout
    {

        RowLayout
        {
            Label{
                font.bold: true
                text: "Qualifier: "
            }
            Label{text: block.Qualifier}
            //Label{text: "test"}
        }

        RowLayout
        {
            Label{
                font.bold: true
                text: "FlashDataInfo_Idk: "
            }
            Label{text: block.FlashDataInfo_Idk}
            //Label{text: "test"}
        }

        RowLayout
        {
            Layout.fillHeight: true
            ListView
            {
                model: segments_model.addFlashSegments(block.FlashSegments)
                delegate: ColumnLayout
                {
                    RowLayout
                    {
                        Label{text: "segment" }
                    }
                }
            }
        }
    }
}
