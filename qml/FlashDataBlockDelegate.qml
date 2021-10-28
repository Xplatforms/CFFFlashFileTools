import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.platform

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
        Rectangle
        {
            height: 1
            Layout.fillWidth: true
        }
        Button
        {
            //Layout.fillWidth: true
            text: " Export all segments... "
            onClicked:
            {
                console.log("export all segments");
                export_dialog.open();

            }
        }
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

    FolderDialog
    {
        id: export_dialog
        title: "Please choose where to export flash segments"
        //fileMode: FolderDialog.OpenFolder
        //folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)

        //nameFilters: [FlashSegment.SegmentName+".segment"]

        onAccepted: {
            console.log("You chose: " + export_dialog.folder)
            //FlashSegment.saveToFile(FlashSegment.SegmentName+"_"+idk+".segment");
            //loadCFF(fileDialog.currentFile);
            //Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            //Qt.quit()
        }
        //Component.onCompleted: visible = true
    }
}




