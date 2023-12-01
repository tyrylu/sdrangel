///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2023 Jon Beniston, M7RCE <jon@beniston.com>                     //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "util/rtty.h"

// From http://www.ct2fzi.net/abreviations/abreviations.html
const QHash<QString, QString> Rtty::m_acronyms = {
    {"AA", "After All"},
    {"AB", "All Before"},
    {"ABT", "About"},
    {"ACK", "Acknowledgement"},
    {"ADEE", "Addressee"},
    {"ADR", "Address"},
    {"AF", "Audio Frequency"},
    {"AGN", "Again"},
    {"AM", "Amplitude Modulation"},
    {"AMU", "Antenna Matching Unit"},
    {"ANS", "Answer"},
    {"ANT", "Antenna"},
    {"ARQ", "Automatic Repeat Request"},
    {"ATU", "Antenna Tuning Unit"},
    {"B4", "Before"},
    {"BCN", "Beacon"},
    {"BCNU", "Be Seeing You"},
    {"BD", "Bad"},
    {"BK", "Break"},
    {"BN", "Been"},
    {"BTH", "Both"},
    {"BTR", "Better"},
    {"BTW", "By The Way"},
    {"BTU", "Back To You"},
    {"C", "Correct"},
    {"CBA", "Callbook Address"},
    {"CFM", "Confirm"},
    {"CK", "Check"},
    {"CKT", "Circuit"},
    {"CL", "Closing Down"},
    {"CLBK", "Callbook"},
    {"CLD", "Called"},
    {"CLG", "Calling"},
    {"CMG", "Coming"},
    {"CNT", "Can't"},
    {"COMP", "Computer"},
    {"CONDX", "Conditions"},
    {"COZ", "Because"},
    {"CPI", "Copy"},
    {"CQ", "General Call"},
    {"CRD", "Card"},
    {"CS", "Callsign"},
    {"CTCSS", "Continuous Tone Coded Squelch System"},
    {"CU", "See You"},
    {"CUAGN", "See You Again"},
    {"CUD", "Could"},
    {"CUL", "See You Later"},
    {"CUM", "Come"},
    {"CUZ", "Because"},
    {"CW", "Continuous Wave / Morse"},
    {"DA", "Day"},
    {"DE", "From"},
    {"DF", "Direction Finding"},
    {"DIFF", "Difference"},
    {"DLD", "Delivered"},
    {"DLVD", "Delivered"},
    {"DN", "Down"},
    {"DR", "Dear"},
    {"DSB", "Double Side Band"},
    {"DSP", "Digital Signal Processing"},
    {"DSW", "Goodbye (Russian)"},
    {"DWN", "Down"},
    {"DX", "Distance"},
    {"EL", "Element"},
    {"EME", "Earth-Moon-Earth"},
    {"ENUF", "Enough"},
    {"ES", "And"},
    {"EU", "Europe"},
    {"EVE", "Evening"},
    {"FB", "Fine Business"},
    {"FER", "For"},
    {"FIO", "For Information Only"},
    {"FM", "Frequency Modulation"},
    {"FQ", "Frequency"},
    {"FREQ", "Frequency"},
    {"FSD", "Full Scale Deflection"},
    {"FSK", "Frequency Shift Keying"},
    {"FWD", "Forward"},
    {"FWIW", "For What It's Worth"},
    {"FYI", "For Your Information"},
    {"GA", "Good Afternoon"},
    {"GB", "Good Bye"},
    {"GD", "Good Day"},
    {"GE", "Good Evening"},
    {"GESS", "Guess"},
    {"GG", "Going"},
    {"GLD", "Glad"},
    {"GM", "Good Morning"},
    {"GMT", "Greenwich Mean Time"},
    {"GN", "Good Night"},
    {"GND", "Ground"},
    {"GP", "Ground Plane"},
    {"GPS", "Global Positioning System"},
    {"GS", "Green Stamp"},
    {"GUD", "Good"},
    {"GV", "Give"},
    {"GVG", "Giving"},
    {"HAGD", "Have A Good Day"},
    {"HAGWE", "Have A Good Weekend"},
    {"HF", "High Frequency"},
    {"HI", "High"},
    {"HPE", "Hope"},
    {"HQ", "Headquarters"},
    {"HR", "Here / Hour"},
    {"HRD", "Heard"},
    {"HV", "Have"},
    {"HVG", "Having"},
    {"HVY", "Heavy"},
    {"HW", "How"},
    {"IMHO", "In My Humble Opinion"},
    {"IMI", "Say again"},
    {"K", "Over"},
    {"KN", "Over"},
    {"LF", "Low Frequency"},
    {"LNG", "Long"},
    {"LP", "Long Path"},
    {"LSB", "Lower Sideband"},
    {"LSN", "Listen"},
    {"LTR", "Later"},
    {"LV", "Leave"},
    {"LVG", "Leaving"},
    {"LW", "Long Wire"},
    {"MGR", "Manager"},
    {"MI", "My"},
    {"MNI", "Many"},
    {"MOM", "Moment"},
    {"MS", "Meteor Scatter"},
    {"MSG", "Message"},
    {"N", "No"},
    {"NCS", "Net Control Station"},
    {"ND", "Nothing Doing"},
    {"NM", "No More"},
    {"NR", "Near / Number"},
    {"NW", "Now"},
    {"OB", "Old Boy"},
    {"OC", "Old Chap"},
    {"OM", "Old Man"},
    {"OP", "Operator"},
    {"OPR", "Operator"},
    {"OT", "Old Timer"},
    {"OW", "Old Woman"},
    {"PA", "Power Amplifier"},
    {"PBL", "Preamble"},
    {"PKG", "Package"},
    {"POV", "Point Of View"},
    {"PSE", "Please"},
    {"PSK", "Phase Shift Keying"},
    {"PT", "Point"},
    {"PTT", "Push To Talk"},
    {"PWR", "Power"},
    {"PX", "Prefix"},
    {"QRA", "Address"},
    {"QRG", "Frequency"},
    {"QRK", "Readability"},
    {"QRL", "Busy"},
    {"QRM", "Interference"},
    {"QRN", "Noise"},
    {"QRO", "High Power"},
    {"QRP", "Low Power"},
    {"QRQ", "Send Faster"},
    {"QRS", "Send Slower"},
    {"QRSS", "Send Very Slowly"},
    {"QRT", "Stop Sending"},
    {"QRU", "Nothing Further To Say"},
    {"QRV", "Ready"},
    {"QRX", "Wait"},
    {"QRZ", "Who Is Calling Me"},
    {"QSA", "Signal Strength"},
    {"QSB", "Fading"},
    {"QSK", "Break-in"},
    {"QSL", "All Received OK"},
    {"QSLL", "I Will Send A QSL Card"},
    {"QSO", "Contact"},
    {"QSP", "Relay A Message"},
    {"QSX", "Listening On Frequency"},
    {"QSY", "Change Frequency"},
    {"QTH", "Location"},
    {"R", "Received OK"},
    {"RC", "Ragchew"},
    {"RCD", "Recieved"},
    {"RCVR", "Receiver"},
    {"RE", "Regarding"},
    {"REF", "Reference"},
    {"RF", "Radio Frequency"},
    {"RFI", "Radio Frequency Interference"},
    {"RPT", "Repeat / Report"},
    {"RST", "Signal Report"},
    {"RTTY", "Radio Teletype"},
    {"RX", "Receive"},
    {"SA", "Say"},
    {"SDR", "Software Defined Radio"},
    {"SEZ", "Says"},
    {"SGD", "Signed"},
    {"SHUD", "Should"},
    {"SIG", "Signal"},
    {"SK", "End Of Work"},
    {"SKED", "Schedule"},
    {"SN", "Soon"},
    {"SP", "Short Path"},
    {"SRI", "Sorry"},
    {"SSB", "Single Sideband"},
    {"STN", "Station"},
    {"SUM", "Some"},
    {"SVC", "Service"},
    {"SWR", "Standing Wave Ratio"},
    {"TFC", "Traffic"},
    {"TIA", "Thanks In Advance"},
    {"TKS", "Thanks"},
    {"TMW", "Tomorrow"},
    {"TNC", "Terminal Node Controller"},
    {"TNX", "Thanks"},
    {"TR", "Transmit"},
    {"T/R", "Transmit/Receive"},
    {"TRBL", "Trouble"},
    {"TRF", "Tuned Radio Frequency"},
    {"TRIX", "Tricks"},
    {"TRX", "Transceiver"},
    {"TT", "That"},
    {"TTS", "That Is"},
    {"TU", "Thank You"},
    {"TVI", "Television Interference"},
    {"TX", "Transmit"},
    {"TXT", "Text"},
    {"U", "You"},
    {"UHF", "Ultra High Frequency"},
    {"UNLIS", "Unlicensed"},
    {"UR", "Your"},
    {"URS", "Yours"},
    {"UTC", "Coordinated Universal Time"},
    {"V", "Volts"},
    {"VHF", "Very High Frequency"},
    {"VE", "Understood"},
    {"VERT", "Vertical"},
    {"VFB", "Very Fine Business"},
    {"VFO", "Variable Frequency Oscillator"},
    {"VLF", "Very Low Frequency"},
    {"VOX", "Voice Operated"},
    {"VSB", "Vestigial Sideband"},
    {"VSWR", "Voltage Standing Wave Ratio"},
    {"VY", "Very"},
    {"W", "Watts"},
    {"WA", "Word After"},
    {"WAT", "What"},
    {"WATSA", "What Say"},
    {"WB", "Word Before"},
    {"WD", "Word"},
    {"WDS", "Words"},
    {"WID", "With"},
    {"WKD", "Worked"},
    {"WKG", "Working"},
    {"WL", "Will"},
    {"WPM", "Words Per Minute"},
    {"WRD", "Word"},
    {"WRK", "Work"},
    {"WUD", "Would"},
    {"WX", "Weather"},
    {"XCVR", "Transceiver"},
    {"XMTR", "Transmitter"},
    {"XTAL", "Crystal"},
    {"YF", "Wife"},
    {"YL", "Young Lady"},
    {"YR", "Year"},
    {"Z", "Zulu Time"},
    {"30", "I Have Nothing More to Send"},
    {"33", "Fondest Regards"},
    {"55", "Best Success"},
    {"73", "Best Wishes"},
    {"88", "Love And Kisses"},
};