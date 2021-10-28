import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import xplatforms.cffflashcontainer.flashblock 1.0
import xplatforms.cffflashcontainer.flashsegment 1.0
import xplatforms.cffflashcontainer.flashsegmentmodel 1.0


ColumnLayout
{
    property CFFFlashDataBlock block;
    property CFFFlashSegmentModel segments_model: CFFFlashSegmentModel{}
    Component.onCompleted: {
        block.updateModel(segments_model);
        //segments_model.addFlashSegments(block.FlashSegments);
        console.log("Component width: " + width)
    }

    Layout.fillWidth: true

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
        Layout.fillWidth: true
        Label{
            font.bold: true
            text: "FlashDataInfo_Idk: "
        }
        Label{text: block.FlashDataInfo_Idk}
        //Label{text: "test"}
    }

    Rectangle
    {
        Layout.fillWidth: true
        height: 1
        color: "black"
    }

    Rectangle
    {
        Layout.fillWidth: true
        height: 10
        color: "white"
    }

    ListView
    {
        Layout.fillHeight: true
        Layout.fillWidth: true
        implicitHeight: 220
        snapMode: ListView.SnapOneItem
        //height: 200
        model: segments_model
        //block.getSegmentsModel()//segments_model.addFlashSegments(block.FlashSegments)
        delegate: FlashSegmentModel{idk: block.FlashDataInfo_Idk}
    }
}




