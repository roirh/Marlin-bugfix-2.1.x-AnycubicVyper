#
# random-bin-vyper.py
# Generates bin file for vyper
#                              
import pioutil
if pioutil.is_pio_build():
    from datetime import datetime
    Import("env")
    env['PROGNAME'] = datetime.now().strftime("main_board_%Y%m%d-%H%M%S")
