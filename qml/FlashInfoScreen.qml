import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import xplatforms.cffflashcontainer.container 1.0
import xplatforms.cffflashcontainer.flashheader 1.0
import xplatforms.cffflashcontainer.flashblock 1.0
import xplatforms.cffflashcontainer.flashblocksmodel 1.0

Page {

    title: qsTr("CFF Flash Files Tools")
    padding: 5

    property CFFFlashContainer cff: CFFFlashContainer{}
    property CFFFlashDataBlocksModel blocks_model: CFFFlashDataBlocksModel{}
    property CFFFlashHeader flash_header: null
    property int cff_checksum: 0
    property int cff_calculated_checksum: 0

    Component.onCompleted:
    {
        cff = cff.openCaesarFlashContainer(cff_object.selected_fname)
        cff_checksum = cff.readChecksum();
        cff_calculated_checksum = cff.genChecksum();

        flash_header = cff.readFlashCFF();
        //blocks_model.addFlashDataBlocks(flash_header.FlashDataBlocks);
        flash_header.updateModel(blocks_model);

        console.log(flash_header.FlashName)
    }

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 8

        RowLayout
        {
            Label
            {
                text: qsTr("Flash Name:")
                font: window.headerFont12
            }
            Label
            {
                text: flash_header.FlashName
            }
        }

        RowLayout
        {
            Label
            {
                text: qsTr("Flash Author:")
                font: window.headerFont12

            }
            Label
            {
                text: flash_header.FileAuthor
            }
        }

        Rectangle
        {
            Layout.fillWidth: true
            height: 1
            color: "black"
        }

        RowLayout
        {
            Layout.fillHeight: true
            ListView
            {
                model: blocks_model
                delegate: FlashDataBlockDelegate{}
            }
        }

        Rectangle
        {
            Layout.fillHeight: true
            width: 1
        }
    }

}
