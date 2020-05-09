import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.6



Window {
    id: thermo
    visible: true
    width: 500
    height: 480
    title: qsTr("SCALE")

    signal adjustIndicator()

    property double weightWheel: 0;
    property double tempD: -1;
    property double tempQS: -1;
    property bool ok: false;


    Image {
        id: scale_out
        x: -72
        y: 10
        width: 556
        height: 470
        rotation: 0
        z: 1
        fillMode: Image.PreserveAspectFit
        source: "scale/window.png"

        transform: Rotation{ angle: weightWheel;origin.x:279; origin.y:145; }
        smooth:true


    }

    Image {
        id: image2
        x: 156
        y: 151
        z: 2
        width: 100
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "scale/arrow.png"
    }

    Text {
        id: element
        x: 405
        y: 47
        z: 3
        width: 36
        height: 24
        text: qsTr("lbs.")
        font.pixelSize: 18
    }

    TextInput {
        id: weight
        x: 348
        y: 52
        z: 3
        width: 60
        height: 20
        text: qsTr("100")
        font.pixelSize: 21
        }


    Image {
        id: image1
        x: -72
        y: 10
        width: 556
        height: 464
        fillMode: Image.PreserveAspectFit
        source: "scale/scale.png"
    }

    Button {
        id: button
        x: 413
        y: 223
        text: qsTr("up")
        onClicked: thermo.adjustIndicator.connect(thermo.rotateCCW())
    }

    Button {
        id: button1
        x: 413
        y: 300
        text: qsTr("down")
        onClicked: thermo.adjustIndicator.connect(thermo.rotateCW())
    }

    Button {
        id: button2
        x: 415
        y: 83
        text: qsTr("start")
        onClicked: thermo.adjustIndicator.connect(thermo.startTHREAD()())
    }

    Button {
        id: button3
        x: 417
        y: 138
        text: qsTr("stop")
        onClicked: thermo.adjustIndicator.connect(thermo.stopTHREAD()())
    }

    Timer {
            id: textTimer
            interval: 1000
            repeat: true
            running: true
            triggeredOnStart: true
            onTriggered: thermo.adjustIndicator.connect(thermo.updateVAL())
        }



    function updateVAL()
    {

        vals.read_sensor();

        weight.text = vals.get_qstring();

        weightWheel = vals.get_double()*-1;

        //if(vals.is_running)
        //{
            //vals.test();

            //posY = ( 122-vals.read_sensor() ) / .72;

            //the_temp.text= vals.read_sensor().toFixed(2).toString();
        //}

    }

    function rotateCW() {
            weightWheel += 1;
            weight.text = qsTr( weightWheel.toFixed().toString() );
        }

    function rotateCCW() {

            weightWheel -= 1;
            weight.text = qsTr( weightWheel.toFixed().toString() );
        }


    function startTHREAD() {
            vals.startThread();
        }

    function stopTHREAD() {
            vals.stopThread();
        }



}
