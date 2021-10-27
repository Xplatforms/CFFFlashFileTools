import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import xplatforms.cffflashcontainer.flashblock 1.0

Component
{

    ColumnLayout
    {
        RowLayout
        {
            Label{text: FlashDataBlock.Qualifier}
            Label{text: FlashDataBlock.LongName}
            //Label{text: "test"}
        }
    }
}
