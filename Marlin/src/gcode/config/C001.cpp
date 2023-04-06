#include "../../inc/MarlinConfig.h"

#include "../gcode.h"
#include "../../module/probe.h"

#if HAS_PROBE_SETTINGS

void GcodeSuite::C001() {
    if (!parser.seen("SHBW")) return C001_report();
    if (parser.seenval('S')) probe.settings.turn_heaters_off = parser.value_bool();
    if (parser.seenval('H')) probe.settings.preheat_hotend_temp = parser.value_ushort();
    if (parser.seenval('B')) probe.settings.preheat_bed_temp = parser.value_ushort();
    if (parser.seenval('W')) probe.settings.stabilize_temperatures_after_probing = parser.value_bool();
}

void GcodeSuite::C001_report(const bool forReplay/*=true*/) {
    SERIAL_ECHOPGM("Improve bed leveling accuracy (Probe heaters off):");
    SERIAL_ECHOPGM("  C001 S", probe.settings.turn_heaters_off ? 1 : 0);
    SERIAL_ECHOPGM(" H", probe.settings.preheat_hotend_temp);
    SERIAL_ECHOPGM(" B", probe.settings.preheat_bed_temp);
    SERIAL_ECHOPGM(" W", probe.settings.stabilize_temperatures_after_probing);
}
#endif