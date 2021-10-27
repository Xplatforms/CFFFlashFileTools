import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import xplatforms.cffflashcontainer.flashblock 1.0
import xplatforms.cffflashcontainer.flashsegment 1.0
import xplatforms.cffflashcontainer.flashsegmentmodel 1.0

Item
{
    property CFFFlashDataBlock block;
    property CFFFlashSegmentModel segments_model: CFFFlashSegmentModel{}
    Component.onCompleted: {
        block.updateModel(segments_model);
        //segments_model.addFlashSegments(block.FlashSegments);
    }

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


        ListView
        {
            Layout.fillHeight: true
            model: segments_model
            //block.getSegmentsModel()//segments_model.addFlashSegments(block.FlashSegments)
            delegate:
                RowLayout
            {
                Label{text: "segment" }
                Label{text: FlashSegment.SegmentName}
            }

        }
    }



}
