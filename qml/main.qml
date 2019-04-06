import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Qt.labs.platform 1.0

Window {
    id: iq42
    visible: true

    SystemTrayIcon {
        visible: true
        icon.source: "qrc:/images3/iq42_icon32x32.png"
        iconSource: "qrc:/images3/iq42_icon32x32.png"
    }


 /*
    width: 600
    height: 600
    x: 100
    y: 100
    title: qsTr("IQ42xxxx")
    SystemTrayIcon {
        visible: true
        iconSource: "qrc:/images3/iq42_icon32x32.png"
    }
 */
}
