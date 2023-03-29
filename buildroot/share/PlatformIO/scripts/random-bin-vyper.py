#
# random-bin.py
# Uses a fixed date because some dates are not detected by the bootloader
# Only certain numbers works with the bootloader
#
import pioutil
if pioutil.is_pio_build():
    from datetime import datetime
    Import("env")
    env['PROGNAME'] = datetime.now().strftime("main_board_20230328")
